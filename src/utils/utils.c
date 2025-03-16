/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cereais <cereais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:40:15 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/16 19:33:33 by cereais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	degree_to_radians(int a)
{
	return (a * PI / 180.0);
}

bool	touch_wall(float px, float py, t_game *game)
{
	int	x;
	int	y;

	x = px / SIZE;
	y = py / SIZE;
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return (true);
	if (game->map[y][x] == '1')
		return (true);
	return (false);
}

bool	out_s_n(t_game *game, t_player *player, double move_speed, char p)
{
	float	py;
	float	px;

	if (p == 'n')
	{
		px = player->x + player->x_cos * (move_speed * 2);
		py = player->y + player->y_sin * (move_speed * 2);
		return (touch_wall(px, py, game));
	}
	else if (p == 's')
	{
		px = player->x - player->x_cos * (move_speed * 2);
		py = player->y - player->y_sin * (move_speed * 2);
		return (touch_wall(px, py, game));
	}
	return (false);
}

bool	out_e_w(t_game *game, t_player *player, double move_speed, char p)
{
	float	py;
	float	px;

	if (p == 'e')
	{
		px = player->x + player->y_sin * (move_speed * 2);
		py = player->y - player->x_cos * (move_speed * 2);
		return (touch_wall(px, py, game));
	}
	else if (p == 'w')
	{
		px = player->x - player->y_sin * (move_speed * 2);
		py = player->y + player->x_cos * (move_speed * 2);
		return (touch_wall(px, py, game));
	}
	return (false);
}
