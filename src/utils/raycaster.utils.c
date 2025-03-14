/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 02:56:34 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/14 03:09:54 by joseoliv         ###   ########.fr       */
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
