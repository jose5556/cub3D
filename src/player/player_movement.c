/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cereais <cereais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:43:56 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/07 17:12:34 by cereais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_player(t_game *game)
{
	int		speed;

	speed = 5;

	if (game->player.left_direction)
		game->player.angle -= degree_to_radians(speed);
	if (game->player.right_direction)
		game->player.angle += degree_to_radians(speed);

	if (game->player.angle > 2 * PI)
		game->player.angle -= 2 * PI;
	if (game->player.angle < 0)
		game->player.angle += 2 * PI;

	game->player.x_cos = cos(game->player.angle);
	game->player.y_sin = sin(game->player.angle);
	
	if (game->player.key_up && !touch_wall(game->player.x, game->player.y, game))
	{
		game->player.x += game->player.x_cos * speed;
		game->player.y += game->player.y_sin * speed;
	}
	if (game->player.key_down && !touch_wall(game->player.x, game->player.y, game))
	{
		game->player.x -= game->player.x_cos * speed;
		game->player.y -= game->player.y_sin * speed;
	}
	if (game->player.key_left && !touch_wall(game->player.x, game->player.y, game))
	{
		game->player.x += game->player.y_sin * speed;
		game->player.y -= game->player.x_cos * speed;
	}
	if (game->player.key_right && !touch_wall(game->player.x, game->player.y, game))
	{
		game->player.x -= game->player.y_sin * speed;
		game->player.y += game->player.x_cos * speed;
	}
}
