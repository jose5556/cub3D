/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_painter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cereais <cereais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 06:36:00 by cereais           #+#    #+#             */
/*   Updated: 2025/03/23 07:13:44 by cereais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_texture	*select_texture(t_game *game, int side)
{
	if (side == 0)
	{
		if (game->ray.step_x > 0)
			return (&game->textures[0]);
		return (&game->textures[1]);
	}
	if (game->ray.step_y > 0)
		return (&game->textures[2]);
	return (&game->textures[3]);
}

static double	calculate_wall_x(t_game *game, t_bob *bob, int side)
{
	double	wall_x;

	if (side == 0)
		wall_x = game->player.y + bob->perp_wall_dist * game->ray.dir_y;
	else
		wall_x = game->player.x + bob->perp_wall_dist * game->ray.dir_x;
	return (wall_x - floor(wall_x));
}

static int	calculate_tex_x(t_texture *texture, double wall_x,
		int side, t_game *game)
{
	int	tex_x;

	tex_x = (int)(wall_x * (double)texture->width);
	if ((side == 0 && game->ray.dir_x > 0)
		|| (side == 1 && game->ray.dir_y < 0))
		tex_x = texture->width - tex_x - 1;
	return (tex_x);
}

static void	draw_texture_column(t_game *game, t_texture *texture,
		int pixel_x, int tex_x)
{
	int		y;
	double	step;
	double	tex_pos;
	int		tex_y;
	int		color;

	y = game->bob.draw_start;
	step = 1.0 * texture->height / game->bob.line_height;
	tex_pos = (game->bob.draw_start - HEIGHT / 2 + game->bob.line_height / 2)
		* step;
	while (y < game->bob.draw_end)
	{
		tex_y = (int)tex_pos & (texture->height - 1);
		tex_pos += step;
		color = *(int *)(texture->addr + (tex_y * texture->line_length + tex_x
					* (texture->bits_per_pixel / 8)));
		my_mlx_pixel_put(&game->img, pixel_x, y, color);
		y++;
	}
}

void	paint_walls(t_game *game, t_bob *bob, int pixel_x, int side)
{
	int			tex_x;
	double		wall_x;
	t_texture	*texture;

	game->bob = *bob;
	texture = select_texture(game, side);
	wall_x = calculate_wall_x(game, bob, side);
	tex_x = calculate_tex_x(texture, wall_x, side, game);
	draw_texture_column(game, texture, pixel_x, tex_x);
}
