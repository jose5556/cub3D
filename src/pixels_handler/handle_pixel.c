/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cereais <cereais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 19:21:19 by cereais           #+#    #+#             */
/*   Updated: 2025/03/19 19:49:07 by cereais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	my_mlx_pixel_put(t_img *vars, int x, int y, int color)
{
	char	*dst;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	dst = vars->addr + (y * vars->line_length + x
			* (vars->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	clear_image(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			my_mlx_pixel_put(&game->img, x, y, 0);
	}
}

void	paint_walls(t_game *game, t_bob *bob, int wall_color, int pixel_x)
{
	int	y;

	y = bob->draw_start;
	while (y <= bob->draw_end)
	{
		my_mlx_pixel_put(&game->img, pixel_x, y, wall_color);
		y++;
	}
}

void	paint_floor_ceil(t_game *game)
{
	int	y;
	int	i;

	y = -1;
	while (++y < HEIGHT / 2)
	{
		i = -1;
		while (++i < WIDTH)
			my_mlx_pixel_put(&game->img, i, y, LIGHT_BLUE);
	}
	while (++y < HEIGHT)
	{
		i = -1;
		while (++i < WIDTH)
			my_mlx_pixel_put(&game->img, i, y, GREEN);
	}
}
