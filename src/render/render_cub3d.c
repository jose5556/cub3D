/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cub3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:18:14 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/04 17:35:37 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	my_mlx_pixel_put(t_img *vars, int x, int y, int color)
{
	char	*dst;

	if(x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
        return ;
	dst = vars->addr + (y * vars->line_length + x
			* (vars->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_square(int size, int color, t_game *game)
{
	int	i;

	i = -1;
	while (++i < size)
		my_mlx_pixel_put(&game->img, game->player.x + i, game->player.y, color);  //up
	i = -1;
	while (++i < size)
		my_mlx_pixel_put(&game->img, game->player.x, game->player.y + i, color); //down
	i = -1;
	while (++i < size)
		my_mlx_pixel_put(&game->img, game->player.x + size, game->player.y + i, color);  //right
	i = -1;
	while (++i < size)
		my_mlx_pixel_put(&game->img, game->player.x + i, game->player.y + size, color);  //left
}

static void	clean_image(t_game *game)
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

int	render_cub3d(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	move_player(&game->player);
	clean_image(game);
	draw_square(10 ,GREEN, game);
	draw_map(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}
