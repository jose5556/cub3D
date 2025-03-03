/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:06:23 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/03 20:35:56 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	init_player(t_player *player)
{
	player->x = WIDTH / 2;
	player->y = HEIGHT / 2;
	player->size = 10;
	player->key_down = false;
	player->key_up = false;
	player->key_right = false;
	player->key_left = false;
}

void	init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit (EXIT_FAILURE);
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3D");
	if (!game->win)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit (EXIT_FAILURE);
	}
	game->img.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img.img)
	{
		mlx_destroy_display(game->mlx);
		mlx_destroy_window(game->mlx, game->win);
		free(game->mlx);
		exit (EXIT_FAILURE);
	}
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel,
			&game->img.line_length, &game->img.endian);
	init_player(&game->player);
}
