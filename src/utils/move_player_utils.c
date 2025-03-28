/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cereais <cereais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:53:57 by cereais           #+#    #+#             */
/*   Updated: 2025/03/23 06:54:29 by cereais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	is_inside_wall(double px, double py, t_game *game)
{
	double	radius;

	radius = 0.2;
	if (px < 0 || px >= WIDTH || py < 0 || py >= HEIGHT)
		return (true);
	if (!game->player.interact
		&& (game->map[(int)(py - radius)][(int)(px - radius)] == '4' ||
		game->map[(int)(py - radius)][(int)(px + radius)] == '4' ||
		game->map[(int)(py + radius)][(int)(px - radius)] == '4' ||
		game->map[(int)(py + radius)][(int)(px + radius)] == '4'))
		return (true);
	else if (game->map[(int)(py - radius)][(int)(px - radius)] == '1' ||
		game->map[(int)(py - radius)][(int)(px + radius)] == '1' ||
		game->map[(int)(py + radius)][(int)(px - radius)] == '1' ||
		game->map[(int)(py + radius)][(int)(px + radius)] == '1')
		return (true);
	return (false);
}

bool	is_inside_door(double px, double py, t_game *game)
{
	double	radius;

	radius = 0.2;
	if (px < 0 || px >= WIDTH || py < 0 || py >= HEIGHT)
		return (true);
	if (game->map[(int)(py - radius)][(int)(px - radius)] == '4' ||
			game->map[(int)(py - radius)][(int)(px + radius)] == '4' ||
			game->map[(int)(py + radius)][(int)(px - radius)] == '4' ||
			game->map[(int)(py + radius)][(int)(px + radius)] == '4')
		return (true);
	return (false);
}
