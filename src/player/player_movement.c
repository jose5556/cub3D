/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cereais <cereais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:43:56 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/15 23:17:33 by cereais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	move_player_angle(t_game *game)
{
	if (game->player.left_direction)
		game->player.angle -= degree_to_radians(1);
	if (game->player.right_direction)
		game->player.angle += degree_to_radians(1);
}

static void	move_player_position(t_game *game)
{
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

void	move_player(t_game *game)
{
	move_player_angle(game);
	if (game->player.angle > 2 * PI)
		game->player.angle -= 2 * PI;
	if (game->player.angle < 0)
		game->player.angle += 2 * PI;
	game->player.x_cos = cos(game->player.angle);
	game->player.y_sin = sin(game->player.angle);
	move_player_position(game);
}
