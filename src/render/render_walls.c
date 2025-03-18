/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cereais <cereais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:27:14 by cereais           #+#    #+#             */
/*   Updated: 2025/03/18 23:06:30 by cereais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	bob_builder(t_game *game, t_ray *ray, t_bob *bob, int side, int i, float start_x)
{
	float correct_angle;
	
	correct_angle= cosf(game->player.angle - start_x);
	if (side)
    	bob->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y) * correct_angle;
	else
    	bob->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x) * correct_angle;
	bob->line_height = (int)(HEIGHT / bob->perp_wall_dist);
	bob->draw_start = HEIGHT / 2 - bob->line_height / 2;
	if (bob->draw_start < 0)
		bob->draw_start = 0;
	bob->draw_end = HEIGHT / 2 + bob->line_height / 2;
	if (bob->draw_end > HEIGHT - 1)
		bob->draw_end = HEIGHT - 1;
	paint_walls(game, bob, side, i);
}
