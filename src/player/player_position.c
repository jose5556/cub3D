/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:39:45 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/22 05:50:32 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	is_player(char p)
{
	if (p == 'N' || p == 'S' || p == 'E' || p == 'W')
		return (p);
	return (0);
}

int	get_player_y(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (is_player(game->map[i][j]))
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

int	get_player_x(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (is_player(game->map[i][j]))
				return (j);
			j++;
		}
		i++;
	}
	return (-1);
}

static char	get_player_chr(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (is_player(game->map[i][j]))
				return (game->map[i][j]);
			j++;
		}
		i++;
	}
	return (0);
}

double	get_player_angle(t_game *game)
{
	char	player;

	player = get_player_chr(game);
	if (player == 'S')
		return (PI / 2);
	if (player == 'E')
		return (0);
	if (player == 'N')
		return (3 * PI / 2);
	if (player == 'W')
		return (PI);
	return (0);
}
