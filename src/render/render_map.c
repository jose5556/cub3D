/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cereais <cereais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:34:55 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/07 17:21:39 by cereais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	draw_grid_lines(int x, int y, int size, int color, t_game *game)
{
	int	i;

	i = -1;
	while (++i < size)
		my_mlx_pixel_put(&game->img, x, y + i, color); //vertical
	i = -1;
	while (++i < size)
		my_mlx_pixel_put(&game->img, x + i, y, color);  //horizontal
}

void	draw_square(int x, int y, int size, int color, t_game *game)
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
			if(map[y][x] == '1')
				color = WHITE;
			else
				color = BLACK;
			draw_square(x * SIZE, y * SIZE, SIZE, color, game);
			draw_grid_lines(x * SIZE, y * SIZE, SIZE, GRAY, game);
		}
	}
}

char **get_map(void)   //temp func
{
    char **map;

	map = malloc(sizeof(char *) * 11);
    map[0] = "111111111111111";
    map[1] = "100000000000001";
    map[2] = "100000000000001";
    map[3] = "1000100000N0001";
    map[4] = "100000000000001";
    map[5] = "100000000000001";
    map[6] = "100000000000001";
    map[7] = "100100000000001";
    map[8] = "100000000000001";
    map[9] = "111111111111111";
    map[10] = NULL;
    return (map);
}
