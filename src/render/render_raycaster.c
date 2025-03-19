/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_raycaster.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cereais <cereais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:27:32 by cereais           #+#    #+#             */
/*   Updated: 2025/03/19 21:22:30 by cereais          ###   ########.fr       */
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

static int	raycast_loop(t_game *game, t_ray *ray, int *map_x, int *map_y)
{
	int		side;

	side = -1;
	while (!touch_wall(*map_x, *map_y, game))
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			*map_x += ray->h_direction;
			side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			*map_y += ray->v_direction;
			side = 1;
		}
		ray->x = *map_x;
		ray->y = *map_y;
	}
	return (side);
}

static void	ray_caster_dda(t_game *game, float start_x, int pixel)
{
	t_ray	ray;
	int		map_x;
	int		map_y;
	int		side;

	calculate_ray_direction(start_x, &ray);
	calculate_step_sizes(game->player, &ray, &map_x, &map_y);
	side = raycast_loop(game, &ray, &map_x, &map_y);
	game->ray = ray;
	if (side >= 0)
		bob_builder(game, side, pixel, start_x);
}

void	render_raycaster(t_game *game, float start_x, float fraction)
{
	int	pixel_x;

	pixel_x = -1;
	while (++pixel_x < WIDTH)
	{
		ray_caster_dda(game, start_x, pixel_x);
		start_x += fraction;
	}
}
