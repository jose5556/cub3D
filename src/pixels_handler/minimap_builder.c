/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_builder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cereais <cereais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 19:24:16 by cereais           #+#    #+#             */
/*   Updated: 2025/03/19 19:48:43 by cereais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_player(int size, int color, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			my_mlx_pixel_put(&game->img, game->player.x + j,
				game->player.y + i, color);
	}
}

static void	draw_square(int x, int y, int size, int color, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			my_mlx_pixel_put(&game->img, x + j, y + i, color);
	}
}

static void	draw_grid_lines(int x, int y, int size, t_game *game)
{
	int	i;

	i = -1;
	while (++i < size)
		my_mlx_pixel_put(&game->img, x, y + i, GRAY);
	i = -1;
	while (++i < size)
		my_mlx_pixel_put(&game->img, x + i, y, GRAY);
}

void	draw_map(t_game *game)
{
	char	**map;
	int		color;
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
				draw_square(x * MINIMAP_SIZE, y * MINIMAP_SIZE,
					MINIMAP_SIZE, WHITE, game);
			else
			{
				draw_square(x * MINIMAP_SIZE, y * MINIMAP_SIZE,
					MINIMAP_SIZE, 0, game);
				draw_grid_lines(x * MINIMAP_SIZE, y * MINIMAP_SIZE,
					MINIMAP_SIZE, game);
			}
		}
	}
}
