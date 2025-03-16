/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cereais <cereais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:43:56 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/16 18:07:30 by cereais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	move_player_angle(t_player *player, double angle_speed)
{
	if (player->left_direction)
		player->angle -= degree_to_radians(angle_speed);
	if (player->right_direction)
		player->angle += degree_to_radians(angle_speed);
}

static void	move_player_position(t_player *player, double move_speed)
{
	if (player->key_up)
	{
		player->x += player->x_cos * move_speed;
		player->y += player->y_sin * move_speed;
	}
	if (player->key_down)
	{
		player->x -= player->x_cos * move_speed;
		player->y -= player->y_sin * move_speed;
	}
	if (player->key_left)
	{
		player->x += player->y_sin * move_speed;
		player->y -= player->x_cos * move_speed;
	}
	if (player->key_right)
	{
		player->x -= player->y_sin * move_speed;
		player->y += player->x_cos * move_speed;
	}
}

void	move_player(t_game *game)
{
	double	move_speed;
	double	angle_speed;
	
	move_speed = get_fps() / 800.0;
	angle_speed = get_fps() / 50.0;

	move_player_angle(&game->player, angle_speed);
	
	game->player.x_cos = cos(game->player.angle);
	game->player.y_sin = sin(game->player.angle);
	
	move_player_position(&game->player, move_speed);
}
