/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cereais <cereais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 02:56:34 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/16 23:08:13 by cereais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_ray_parameters(t_game *game, float *fraction, float *start_x)
{
	*fraction = PI / 3 / WIDTH;
	*start_x = game->player.angle - (PI / 3) / 2;
}

void	calculate_ray_direction(float start_x, t_ray *ray)
{
	ray->dir_x = cosf(start_x);
	ray->dir_y = sinf(start_x);
}

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
