/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cereais <cereais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:27:14 by cereais           #+#    #+#             */
/*   Updated: 2025/03/15 23:05:07 by cereais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	paint_walls(t_game *game, t_bob *bob, t_ray *ray, int side, int i)
{
	int	color;

	color = RED;
	if (side)
		color /= 2;
	while (bob->draw_start <= bob->draw_end)
	{
		my_mlx_pixel_put(&game->img, i, bob->draw_start, color);
		bob->draw_start++;
	}
}

void	bob_builder(t_game *game, t_ray *ray, t_bob *bob, int side, int i)
{
	if (side)
		bob->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		bob->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;

	bob->line_height = (int)(HEIGHT / bob->perp_wall_dist);

	bob->draw_start = -bob->line_height / 2 + HEIGHT / 2;
	if(bob->draw_start < 0)
		bob->draw_start = 0;

	bob->draw_end = bob->line_height / 2 + HEIGHT / 2;
	if(bob->draw_end >= HEIGHT)
		bob->draw_end = HEIGHT - 1;
	paint_walls(game, bob, ray, side, i);
}
