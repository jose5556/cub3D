/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:06:23 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/04 20:26:27 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* static void	init_map(t_coisa coisa) TODO
{
	
} */

static void	init_player(t_game *game)
{
	/* game->player.x = get_player_x(game);
	printf("%d\n", game->player.x);
	game->player.y = get_player_y(game);
	printf("%d\n", game->player.y); */

	game->player.x = WIDTH / 2;
	game->player.y = HEIGHT / 2;

	game->player.angle = PI / 2;
	
	game->player.key_down = false;
	game->player.key_up = false;
	game->player.key_right = false;
	game->player.key_left = false;

	game->player.left_direction = false;
	game->player.right_direction = false;
}

static void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		mlx_exit_error(MLX_INIT_ERROR, game, 0);
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3D");
	if (!game->win)
		mlx_exit_error(MLX_WINDOW_ERROR, game, 1);
	game->img.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img.img)
		mlx_exit_error(MLX_IMAGE_ERROR, game, 2);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel,
			&game->img.line_length, &game->img.endian);
}

void	init(t_game *game)
{
	init_mlx(game);
	game->map = get_map();
	init_player(game);
}
