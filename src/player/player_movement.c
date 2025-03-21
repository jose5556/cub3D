/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cereais <cereais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:43:56 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/21 08:46:04 by cereais          ###   ########.fr       */
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

static void	move_up_down(t_game *game, t_player *player,
		double move_speed)
{
	float	new_x;
	float	new_y;

	if (player->key_up)
	{
		new_x = player->x + player->x_cos * move_speed;
		new_y = player->y + player->y_sin * move_speed;
		if (!is_inside_wall(new_x, player->y, game))
			player->x = new_x;
		if (!is_inside_wall(player->x, new_y, game))
			player->y = new_y;
	}
	if (player->key_down)
	{
		new_x = player->x - player->x_cos * move_speed;
		new_y = player->y - player->y_sin * move_speed;
		if (!is_inside_wall(new_x, player->y, game))
			player->x = new_x;
		if (!is_inside_wall(player->x, new_y, game))
			player->y = new_y;
	}
}

static void	move_left_right(t_game *game, t_player *player,
		double move_speed)
{
	float	new_x;
	float	new_y;

	if (player->key_left)
	{
		new_x = player->x + player->y_sin * move_speed;
		new_y = player->y - player->x_cos * move_speed;
		if (!is_inside_wall(new_x, player->y, game))
			player->x = new_x;
		if (!is_inside_wall(player->x, new_y, game))
			player->y = new_y;
	}
	if (player->key_right)
	{
		new_x = player->x - player->y_sin * move_speed;
		new_y = player->y + player->x_cos * move_speed;
		if (!is_inside_wall(new_x, player->y, game))
			player->x = new_x;
		if (!is_inside_wall(player->x, new_y, game))
			player->y = new_y;
	}
}

static void	move_player_position(t_game *game,
	t_player *player, double move_speed)
{
	move_left_right(game, player, move_speed);
	move_up_down(game, player, move_speed);
}

void	move_player(t_game *game)
{
	double	move_speed;
	double	angle_speed;
	float	fps;

	fps = get_fps();
	move_speed = 0.03 * (60.0 / fps);
	angle_speed = 0.7;
	if (game->player.shift)
	{
		angle_speed *= 2;
		move_speed *= 3;
	}
	move_player_angle(&game->player, angle_speed);
	game->player.x_cos = cos(game->player.angle);
	game->player.y_sin = sin(game->player.angle);
	move_player_position(game, &game->player, move_speed);
}
