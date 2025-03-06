/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cereais <cereais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:34:55 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/06 18:42:17 by cereais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* void	draw_square_map(int x, int y, int size, int color, t_game *game)  //temp
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
} */
void	draw_square_map(int x, int y, int size, int color, t_game *game)  //temp
{
	int	i;

	i = -1;
	while (++i < size)
		my_mlx_pixel_put(&game->img, x + i, y, color);  //up
	i = -1;
	while (++i < size)
		my_mlx_pixel_put(&game->img, x, y + i, color); //down
	i = -1;
	while (++i < size)
		my_mlx_pixel_put(&game->img,x + size, y + i, color);  //right
	i = -1;
	while (++i < size)
		my_mlx_pixel_put(&game->img, x + i, y + size, color);  //left
}

void	draw_map(t_game *game)  //temp
{
	char	**map;
	int		color;
	int		y;
	int		x;

	y = -1;
	map = game->map;
	color = 0x0000FF;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if(map[y][x] == '1')
				draw_square_map(x * SIZE, y * SIZE, SIZE, color, game);
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
    map[3] = "1000001000N0001";
    map[4] = "100000000000001";
    map[5] = "100000010000001";
    map[6] = "100001000000001";
    map[7] = "100000000000001";
    map[8] = "100000000000001";
    map[9] = "111111111111111";
    map[10] = NULL;
    return (map);
}
