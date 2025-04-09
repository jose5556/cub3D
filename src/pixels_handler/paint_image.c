/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 19:21:19 by cereais           #+#    #+#             */
/*   Updated: 2025/03/29 09:50:11 by joseoliv         ###   ########.fr       */
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

void	paint_floor_ceil(t_game *game)
{
	int	y;
	int	i;
	int	floor_color;
	int	ceiling_color;

	floor_color = (game->config.floor_rgb[0] << 16)
		| (game->config.floor_rgb[1] << 8)
		| game->config.floor_rgb[2];
	ceiling_color = (game->config.ceiling_rgb[0] << 16)
		| (game->config.ceiling_rgb[1] << 8)
		| game->config.ceiling_rgb[2];
	y = -1;
	while (++y < HEIGHT / 2)
	{
		i = -1;
		while (++i < WIDTH)
			my_mlx_pixel_put(&game->img, i, y, ceiling_color);
	}
	while (++y < HEIGHT - 1)
	{
		i = -1;
		while (++i < WIDTH)
			my_mlx_pixel_put(&game->img, i, y, floor_color);
	}
}
