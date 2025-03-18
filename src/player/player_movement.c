/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cereais <cereais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:43:56 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/18 23:21:58 by cereais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	move_player_angle(t_player *player, double angle_speed)
{
	if (player->left_direction)
		player->angle -= degree_to_radians(angle_speed);
	if (player->right_direction)
		player->angle += degree_to_radians(angle_speed);
	player->angle = fmod(player->angle, 2 * PI);
	if (player->angle < 0)
		player->angle += 2 * PI;
}

static void	move_player_position(t_game *game,
		t_player *player, double move_speed)
{
	if (player->key_up && !is_out_map(game, player, move_speed, 'n'))
	{
		player->x += player->x_cos * move_speed;
		player->y += player->y_sin * move_speed;
	}
	if (player->key_down && !is_out_map(game, player, move_speed, 's'))
	{
		player->x -= player->x_cos * move_speed;
		player->y -= player->y_sin * move_speed;
	}
	if (player->key_left && !is_out_map(game, player, move_speed, 'e'))
	{
		player->x += player->y_sin * move_speed;
		player->y -= player->x_cos * move_speed;
	}
	if (player->key_right && !is_out_map(game, player, move_speed, 'w'))
	{
		player->x -= player->y_sin * move_speed;
		player->y += player->x_cos * move_speed;
	}
}

void	move_player(t_game *game)
{
	double	move_speed;
	double	angle_speed;
	float	fps;

	fps = get_fps();
	move_speed = 0.07 * (60.0 / fps);
	angle_speed = 0.5;
	if (game->player.shift)
	{
		angle_speed *= 3;
		move_speed *= 5;		
	}
	move_player_angle(&game->player, angle_speed);
	game->player.x_cos = cos(game->player.angle);
	game->player.y_sin = sin(game->player.angle);
	move_player_position(game, &game->player, move_speed);
}
