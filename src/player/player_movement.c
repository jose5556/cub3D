/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cereais <cereais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:43:56 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/06 18:38:25 by cereais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_player(t_game *game)
{
	int		speed;
	float	angle_speed;
	float	cos_angle;
	float	sin_angle;

	speed = 5;
	angle_speed = 0.03;
	cos_angle = cos(game->player.angle);
	sin_angle = sin(game->player.angle);

	if (game->player.left_direction)
		game->player.angle -= angle_speed;
	if (game->player.right_direction)
		game->player.angle += angle_speed;
	if (game->player.angle > 2 * PI)
		game->player.angle = 0;
	if (game->player.angle < 0)
		game->player.angle = 2 * PI;
	
	if (game->player.key_up && !touch_wall(game->player.x, game->player.y, game))
	{
		game->player.x += cos_angle * speed;
		game->player.y += sin_angle * speed;
	}
	if (game->player.key_down && !touch_wall(game->player.x, game->player.y, game))
	{
		game->player.x -= cos_angle * speed;
		game->player.y -= sin_angle * speed;
	}
	if (game->player.key_left && !touch_wall(game->player.x, game->player.y, game))
	{
		game->player.x += sin_angle * speed;
		game->player.y -= cos_angle * speed;
	}
	if (game->player.key_right && !touch_wall(game->player.x, game->player.y, game))
	{
		game->player.x -= sin_angle * speed;
		game->player.y += cos_angle * speed;
	}
}
