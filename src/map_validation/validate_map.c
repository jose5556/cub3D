/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:25:53 by joseoliv          #+#    #+#             */
/*   Updated: 2025/04/13 16:25:54 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static bool	is_valid_map_char(t_game *game, char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W' || c == ' ')
		return (true);
	if (game->bonus && c == '4')
		return (true);
	return (false);
}

static int	count_players_in_map(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

static bool	validate_map_characters(t_game *game, bool *found_door)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		c = game->map[i][j];
		while (c)
		{
			if (!is_valid_map_char(game, c) && (!game->bonus || c != '4'))
			{
				printf("Error\nInvalid character '%c' found in game map\n", c);
				return (false);
			}
			if (game->bonus && c == '4')
				*found_door = true;
			j++;
			c = game->map[i][j];
		}
		i++;
	}
	return (true);
}

bool	is_config_line_start(const char *line)
{
	return (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0
		|| ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0
		|| ft_strncmp(line, "PO ", 3) == 0);
}

bool	validate_map_content(t_game *game)
{
	bool	found_door;

	found_door = false;
	if (!validate_map_edges(game->map))
		return (simple_exit_error(WALKABLE_TILES), false);
	if (!validate_space_enclosure(game->map))
		return (simple_exit_error(OPEN_SPACES), false);
	if (!validate_map_characters(game, &found_door))
		return (false);
	if (count_players_in_map(game->map) != 1)
		return (simple_exit_error(PLAYER_COUNT), false);
	if (game->bonus && found_door && !game->config.door_texture)
		return (simple_exit_error(MISSING_PO), false);
	return (true);
}
