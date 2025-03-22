/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:27:14 by cereais           #+#    #+#             */
/*   Updated: 2025/03/22 06:08:43 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	wall_direction(t_ray ray, int side)
{
	int	color;

	if (!side)
	{
		if (ray.step_x > 0)
			color = RED;
		else
			color = PINK;
	}
	else
	{
		if (ray.step_y > 0)
			color = PURPLE;
		else
			color = BROWN;
	}
	return (color);
}

void	bob_builder(t_game *game, int side, int pixel_x, double start_x)
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
		bob.perp_wall_dist = (ray.side_dist_y - ray.delta_dist_y) * correct_angle;
	else
		bob.perp_wall_dist = (ray.side_dist_x - ray.delta_dist_x) * correct_angle;
	bob.line_height = (int)(HEIGHT / (bob.perp_wall_dist) * aspect_ratio);
	bob.draw_start = HEIGHT / 2 - bob.line_height / 2;
	if (bob.draw_start < 0)
		bob.draw_start = 0;
	bob.draw_end = HEIGHT / 2 + bob.line_height / 2;
	if (bob.draw_end > HEIGHT - 1)
		bob.draw_end = HEIGHT - 1;
	paint_walls(game, &bob, pixel_x, side);
}
