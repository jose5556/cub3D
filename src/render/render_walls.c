/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cereais <cereais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:27:14 by cereais           #+#    #+#             */
/*   Updated: 2025/03/17 17:35:03 by cereais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	bob_builder(t_game *game, t_ray *ray, t_bob *bob, int side, int i)
{
	if (side)
		bob->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
	else
		bob->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	bob->line_height = (int)(HEIGHT / bob->perp_wall_dist);
	bob->draw_start = -bob->line_height / 2 + HEIGHT / 2;
	if (bob->draw_start < 0)
		bob->draw_start = 0;
	bob->draw_end = bob->line_height / 2 + HEIGHT / 2;
	if (bob->draw_end >= HEIGHT)
		bob->draw_end = HEIGHT - 1;
	paint_walls(game, bob, ray, side, i);
}
