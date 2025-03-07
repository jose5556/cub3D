/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cub3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cereais <cereais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:18:14 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/07 16:28:53 by cereais          ###   ########.fr       */
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
			my_mlx_pixel_put(&game->img, game->player.x + j, game->player.y + i, color);
	}
}

static void	clear_image(t_game *game)
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

static void	draw_line(t_game *game, float start_x, int i)
{
	float cos_angle;
	float sin_angle;
	float ray_x;
	float ray_y;

	cos_angle = cos(start_x);
	sin_angle = sin(start_x);
	ray_x = game->player.x;
	ray_y = game->player.y;
	while(!touch_wall(ray_x, ray_y, game))
	{
		my_mlx_pixel_put(&game->img, ray_x, ray_y, RED);
		ray_x += cos_angle;
		ray_y += sin_angle;
	}
}

int	render_cub3d(void *param)
{
	t_game	*game;
	int		i;
	float	fraction;
	float	start_x;

	game = (t_game *)param;
	move_player(game);
	clear_image(game);
	draw_map(game);
	draw_player(10 ,GREEN, game);
	fraction = PI / 3 / WIDTH;
	start_x = game->player.angle - PI / 6;
	i = -1;
	while(++i < WIDTH)
	{
		draw_line(game, start_x, i);
		start_x += fraction;
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}
