#include "../../includes/cub3d.h"

static bool	copy_map_lines(t_game *game, char **new_map,
	int map_start, int map_lines)
{
	int	j;
	int	k;

	j = 0;
	while (j < map_lines)
	{
		new_map[j] = ft_strdup(game->map[map_start + j]);
		if (!new_map[j])
		{
			k = 0;
			while (k < j)
			{
				free(new_map[k]);
				k++;
			}
			free(new_map);
			return (false);
		}
		j++;
	}
	new_map[j] = NULL;
	ft_free_array(game->map);
	game->map = new_map;
	return (true);
}

static bool	allocate_and_copy_map(t_game *game, int map_start)
{
	int		map_lines;
	int		j;
	char	**new_map;

	map_lines = 0;
	while (game->map[map_start + map_lines])
		map_lines++;
	new_map = malloc(sizeof(char *) * (map_lines + 1));
	if (!new_map)
		return (false);
	j = 0;
	while (j <= map_lines)
	{
		new_map[j] = NULL;
		j++;
	}
	return (copy_map_lines(game, new_map, map_start, map_lines));
}

static int	parse_config_lines(t_game *game, t_map_config *config)
{
	int		i;
	bool	success;

	i = 0;
	init_map_config(config);
	while (game->map[i])
	{
		success = parse_config_line(game, game->map[i], config);
		if (!success)
			return (-1);
		if (config->config_section_done)
			break ;
		i++;
	}
	return (i);
}

bool	is_empty_content(const char *content)
{
	int	i;

	i = 0;
	while (content[i])
	{
		if (content[i] != ' ' && content[i] != '\n' && content[i] != '\t')
			return (false);
		i++;
	}
	return (true);
}

bool	validate_map(t_game *game)
{
	int				map_start;
	bool			result;
	t_map_config	*config;

	config = &game->config;
	map_start = parse_config_lines(game, config);
	if (map_start == -1)
		return (false);
	if (!allocate_and_copy_map(game, map_start))
		return (false);
	result = validate_map_content(game);
	if (!result)
	{
		ft_free_array(game->map);
		game->map = NULL;
	}
	return (result);
}
