/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_builder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cereais <cereais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 19:24:16 by cereais           #+#    #+#             */
/*   Updated: 2025/03/19 22:58:46 by cereais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_player(int radius, int color, t_game *game)
{
	int	i;
	int	j;
	int	scaled_x;
	int	scaled_y;

	scaled_x = game->player.x * SIZE;
	scaled_y = game->player.y * SIZE;
	i = -radius;
	while (++i <= radius)
	{
		j = -radius;
		while (++j <= radius)
		{
			if (i * i + j * j <= radius * radius)
				my_mlx_pixel_put(&game->img, scaled_x + j, scaled_y + i, color);
		}
	}
}

static void	draw_square(int x, int y, int color, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < SIZE)
	{
		j = -1;
		while (++j < SIZE)
			my_mlx_pixel_put(&game->img, x + j, y + i, color);
	}
}

static void	draw_grid_lines(int x, int y, t_game *game)
{
	int	i;

	i = -1;
	while (++i < SIZE)
		my_mlx_pixel_put(&game->img, x, y + i, GRAY);
	i = -1;
	while (++i < SIZE)
		my_mlx_pixel_put(&game->img, x + i, y, GRAY);
}

void	draw_map(t_game *game)
{
	char	**map;
	int		y;
	int		x;

	y = -1;
	map = game->map;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == '1')
				draw_square(x * SIZE, y * SIZE, WHITE, game);
			else
			{
				draw_square(x * SIZE, y * SIZE, 0, game);
				draw_grid_lines(x * SIZE, y * SIZE, game);
			}
		}
	}
}
