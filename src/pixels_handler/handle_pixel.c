/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 19:21:19 by cereais           #+#    #+#             */
/*   Updated: 2025/03/22 02:37:53 by joseoliv         ###   ########.fr       */
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

void	paint_walls(t_game *game, t_bob *bob, int pixel_x, int side)
{
	int		y;
	int		tex_x;
	int		tex_y;
	int		color;
	float	tex_pos;
	float	step;
	t_texture *texture;

	// Choose texture based on wall direction
	if (side == 0)
		texture = &game->textures[game->ray.h_direction > 0 ? 0 : 1];
	else
		texture = &game->textures[game->ray.v_direction > 0 ? 2 : 3];

	// Calculate texture x-coordinate
	tex_x = (int)(game->ray.x * texture->width / SIZE) % texture->width;
	if (side == 0)
		tex_x = (int)(game->ray.y * texture->width / SIZE) % texture->width;

	// Calculate step and initial texture position
	step = 1.0 * texture->height / bob->line_height;
	tex_pos = (bob->draw_start - HEIGHT / 2 + bob->line_height / 2) * step;

	// Draw the wall slice
	y = bob->draw_start;
	while (y < bob->draw_end)
	{
		tex_y = (int)tex_pos & (texture->height - 1);
		tex_pos += step;
		color = *(int *)(texture->addr + (tex_y * texture->line_length + tex_x * (texture->bits_per_pixel / 8)));
		my_mlx_pixel_put(&game->img, pixel_x, y, color);
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
