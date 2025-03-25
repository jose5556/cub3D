/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_raycaster.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:27:32 by cereais           #+#    #+#             */
/*   Updated: 2025/03/25 03:04:34 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	bob_builder(t_game *game, int side, int pixel_x, double start_x)
{
	double	correct_angle;
	t_ray	ray;
	t_bob	bob;
	double	aspect_ratio;

	aspect_ratio = (double)WIDTH / HEIGHT;
	ray = game->ray;
	bob = game->bob;
	correct_angle = cosf(game->player.angle - start_x);
	if (side)
		bob.perp_wall_dist = (ray.side_dist_y - ray.delta_dist_y)
			* correct_angle;
	else
		bob.perp_wall_dist = (ray.side_dist_x - ray.delta_dist_x)
			* correct_angle;
	bob.line_height = (int)(HEIGHT / (bob.perp_wall_dist) * aspect_ratio);
	bob.draw_start = HEIGHT / 2 - bob.line_height / 2;
	if (bob.draw_start < 0)
		bob.draw_start = 0;
	bob.draw_end = HEIGHT / 2 + bob.line_height / 2;
	if (bob.draw_end > HEIGHT - 1)
		bob.draw_end = HEIGHT - 1;
	paint_walls(game, &bob, pixel_x, side);
}

static void	calculate_step_sizes(t_player player, t_ray *ray,
						int *map_x, int *map_y)
{
	ray->delta_dist_x = fabs(1.0 / ray->dir_x);
	ray->delta_dist_y = fabs(1.0 / ray->dir_y);
	*map_x = (int)player.x;
	*map_y = (int)player.y;
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player.x - *map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (*map_x + 1.0 - player.x) * ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player.y - *map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (*map_y + 1.0 - player.y) * ray->delta_dist_y;
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
			*map_x += ray->step_x;
			side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			*map_y += ray->step_y;
			side = 1;
		}
		ray->x = *map_x;
		ray->y = *map_y;
	}
	return (side);
}

static void	ray_caster_dda(t_game *game, double start_x, int pixel)
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

void	render_raycaster(t_game *game, double start_x, double fraction)
{
	int	pixel_x;

	pixel_x = -1;
	while (++pixel_x < WIDTH)
	{
		ray_caster_dda(game, start_x, pixel_x);
		start_x += fraction;
	}
}
