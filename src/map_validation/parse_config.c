#include "../../includes/cub3d.h"

static void	set_texture_path(t_game *game, char *line,
	char *path, t_map_config *config)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		config->no_texture = path;
		config->no_found = true;
	}
	else if (ft_strncmp(line, "SO ", 3) == 0)
	{
		config->so_texture = path;
		config->so_found = true;
	}
	else if (ft_strncmp(line, "WE ", 3) == 0)
	{
		config->we_texture = path;
		config->we_found = true;
	}
	else if (ft_strncmp(line, "EA ", 3) == 0)
	{
		config->ea_texture = path;
		config->ea_found = true;
	}
	else if (game->bonus && ft_strncmp(line, "PO ", 3) == 0)
	{
		config->door_texture = path;
		config->door_found = true;
	}
}

bool	store_texture_path(t_game *game, char *line, t_map_config *config)
{
	char	*path;

	path = ft_strtrim(line + 3, " \t\n\r");
	if (!path)
		return (false);
	set_texture_path(game, line, path, config);
	return (true);
}

static bool	handle_duplicates_and_missing(t_game *game,
	char *trimmed, t_map_config *config)
{
	if ((ft_strncmp(trimmed, "NO ", 3) == 0 && config->no_found)
		|| (ft_strncmp(trimmed, "SO ", 3) == 0 && config->so_found)
		|| (ft_strncmp(trimmed, "WE ", 3) == 0 && config->we_found)
		|| (ft_strncmp(trimmed, "EA ", 3) == 0 && config->ea_found)
		|| (game->bonus && ft_strncmp(trimmed, "PO ", 3)
			== 0 && config->door_found))
		return (simple_exit_error(DUPLICATE_TEXTURE));
	else if (!config->no_found || !config->so_found
		|| !config->we_found || !config->ea_found)
		return (simple_exit_error(MISSING_TEXTURE_ERROR));
	if ((!config->ceiling_found || !config->floor_found)
		&& !(ft_strncmp(trimmed, "F ", 2) == 0
			|| ft_strncmp(trimmed, "C ", 2) == 0))
	{
		return (simple_exit_error(INVALID_RGB));
	}
	return (false);
}

static bool	handle_trimmed_line(t_game *game,
	char *trimmed, t_map_config *config)
{
	if (is_line_empty(trimmed))
		return (true);
	if (handle_config_complete(trimmed, config))
		return (true);
	if (handle_texture_and_color(game, trimmed, config))
		return (true);
	if (handle_duplicates_and_missing(game, trimmed, config))
		return (true);
	return (false);
}

bool	parse_config_line(t_game *game, char *line, t_map_config *config)
{
	char	*trimmed;

	trimmed = ft_strtrim(line, " \t");
	if (!trimmed)
		return (false);
	if (handle_trimmed_line(game, trimmed, config))
	{
		free(trimmed);
		return (true);
	}
	free(trimmed);
	return (false);
}
