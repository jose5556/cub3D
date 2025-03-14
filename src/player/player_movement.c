/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:43:56 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/14 01:22:12 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_player(t_game *game)
{
	if (game->player.left_direction)
		game->player.angle -= degree_to_radians(game->player.movement);
	if (game->player.right_direction)
		game->player.angle += degree_to_radians(game->player.movement);

	if (game->player.angle > 2 * PI)
		game->player.angle -= 2 * PI;
	if (game->player.angle < 0)
		game->player.angle += 2 * PI;

	game->player.x_cos = cos(game->player.angle);
	game->player.y_sin = sin(game->player.angle);
	
	if (game->player.key_up)
	{
		game->player.x += game->player.x_cos * game->player.movement;
		game->player.y += game->player.y_sin * game->player.movement;
	}
	if (game->player.key_down)
	{
		game->player.x -= game->player.x_cos * game->player.movement;
		game->player.y -= game->player.y_sin * game->player.movement;
	}
	if (game->player.key_left)
	{
		game->player.x += game->player.y_sin * game->player.movement;
		game->player.y -= game->player.x_cos * game->player.movement;
	}
	if (game->player.key_right)
	{
		game->player.x -= game->player.y_sin * game->player.movement;
		game->player.y += game->player.x_cos * game->player.movement;
	}
}
