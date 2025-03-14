/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_raycaster.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:27:32 by cereais           #+#    #+#             */
/*   Updated: 2025/03/14 03:09:41 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


static void	calculate_step_sizes(t_player player, t_ray *ray,
						int *map_x, int *map_y)
{
	ray->delta_dist_x = fabsf(1.0f / ray->dir_x);
	ray->delta_dist_y = fabsf(1.0f / ray->dir_y);
	*map_x = (int)player.x;
	*map_y = (int)player.y;
	if (ray->dir_x < 0)
	{
		ray->h_direction = -1;
		ray->side_dist_x = (player.x - *map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->h_direction = 1;
		ray->side_dist_x = (*map_x + 1.0f - player.x) * ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->v_direction = -1;
		ray->side_dist_y = (player.y - *map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->v_direction = 1;
		ray->side_dist_y = (*map_y + 1.0f - player.y) * ray->delta_dist_y;
	}
}

static void	raycast_loop(t_game *game, t_ray *ray, int *map_x, int *map_y)
{
	while (!touch_wall(*map_x, *map_y, game))
	{
		my_mlx_pixel_put(&game->img, ray->x, ray->y, RED);
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			*map_x += ray->h_direction;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			*map_y += ray->v_direction;
		}
		ray->x = *map_x;
		ray->y = *map_y;
	}
}

static void	ray_caster_dda(t_game *game, float start_x, int i)
{
	t_ray	ray;
	int		map_x;
	int		map_y;

	calculate_ray_direction(start_x, &ray);
	calculate_step_sizes(game->player, &ray, &map_x, &map_y);
	raycast_loop(game, &ray, &map_x, &map_y);
}

void	render_raycaster(t_game *game, float start_x, float fraction)
{
	int i = -1;
	while (++i < WIDTH)
	{
		ray_caster_dda(game, start_x, i);
		start_x += fraction;
	}
}
