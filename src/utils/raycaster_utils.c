/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 02:56:34 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/22 05:50:32 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_ray_parameters(t_game *game, double *fraction, double *start_x)
{
	*fraction = PI / 4 / WIDTH;
	*start_x = game->player.angle - (PI / 4) / 2;
}

void	calculate_ray_direction(double start_x, t_ray *ray)
{
	ray->dir_x = cosf(start_x);
	ray->dir_y = sinf(start_x);
}

double	degree_to_radians(double a)
{
	return (a * PI / 180.0);
}

bool	touch_wall(double px, double py, t_game *game)
{
	if (px < 0 || px >= WIDTH || py < 0 || py >= HEIGHT)
		return (true);

	if (!(game->player.interact))
	{
		if (game->map[(int)py][(int)px] == '1'
			|| game->map[(int)py][(int)px] == '4')
			return (true);
	}
	else
	{
		if (game->map[(int)py][(int)px] == '1')
		return (true);
	}
	return (false);
}
