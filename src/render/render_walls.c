/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cereais <cereais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:27:14 by cereais           #+#    #+#             */
/*   Updated: 2025/03/19 18:45:55 by cereais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	bob_builder(t_game *game, t_ray *ray, t_bob *bob, int side, int i, float start_x)
{
	float	correct_angle;
	int		color;
	
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
	if (side == 0)
	{
		if (ray->h_direction > 0)
			color = RED;
		else
			color = PINK;
	}
	else
	{
		if (ray->v_direction > 0)
			color = PURPLE;
		else
			color = BROWN;
	}
	paint_walls(game, bob, color, i);
}
