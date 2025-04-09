#include "../../includes/cub3d.h"

void	init_map_config(t_map_config *config)
{
	config->no_texture = NULL;
	config->so_texture = NULL;
	config->we_texture = NULL;
	config->ea_texture = NULL;
	config->door_texture = NULL;
	config->no_found = false;
	config->so_found = false;
	config->we_found = false;
	config->ea_found = false;
	config->door_found = false;
	config->floor_found = false;
	config->ceiling_found = false;
	config->config_section_done = false;
	ft_memset(config->floor_rgb, 0, sizeof(int) * 3);
	ft_memset(config->ceiling_rgb, 0, sizeof(int) * 3);
}

bool	is_texture_line(t_game *game, char *line, t_map_config *config)
{
	if (ft_strncmp(line, "NO ", 3) == 0 && !config->no_found)
		return (true);
	if (ft_strncmp(line, "SO ", 3) == 0 && !config->so_found)
		return (true);
	if (ft_strncmp(line, "WE ", 3) == 0 && !config->we_found)
		return (true);
	if (ft_strncmp(line, "EA ", 3) == 0 && !config->ea_found)
		return (true);
	if (game->bonus && ft_strncmp(line, "PO ", 3) == 0 && !config->door_found)
		return (true);
	return (false);
}

bool	is_color_line(char *line, t_map_config *config)
{
	if (ft_strncmp(line, "F ", 2) == 0 && !config->floor_found)
		return (true);
	if (ft_strncmp(line, "C ", 2) == 0 && !config->ceiling_found)
		return (true);
	return (false);
}

bool	handle_config_complete(char *trimmed, t_map_config *config)
{
	if (config->no_found && config->so_found && config->we_found
		&& config->ea_found && config->floor_found && config->ceiling_found)
	{
		if (ft_strspn(trimmed, " 10NSEW") == ft_strlen(trimmed))
		{
			config->config_section_done = true;
			return (true);
		}
	}
	return (false);
}

bool	handle_texture_and_color(t_game *game, char *trimmed,
	t_map_config *config)
{
	if (is_texture_line(game, trimmed, config))
		return (store_texture_path(game, trimmed, config));
	else if (is_color_line(trimmed, config))
		return (store_rgb_values(trimmed, config));
	return (false);
}
