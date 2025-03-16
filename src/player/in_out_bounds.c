/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_out_bounds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cereais <cereais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:40:15 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/16 23:08:11 by cereais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	is_out_map(t_game *game, t_player *player,
	double move_speed, char p)
{
float	py;
float	px;

if (p == 'n' || p == 's')
	return (out_s_n(game, player, move_speed, p));
else
	return (out_e_w(game, player, move_speed, p));
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
