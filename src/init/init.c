/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cereais <cereais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:06:23 by joseoliv          #+#    #+#             */
/*   Updated: 2025/04/16 14:42:16 by cereais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	load_single_texture(t_game *game, int index, char *path)
{
	game->textures[index].img = mlx_xpm_file_to_image(
			game->mlx, path,
			&game->textures[index].width, &game->textures[index].height);
	if (!game->textures[index].img)
		mlx_exit_error("Failed to load texture", game, 1);
	game->textures[index].addr = mlx_get_data_addr(
			game->textures[index].img,
			&game->textures[index].bits_per_pixel,
			&game->textures[index].line_length,
			&game->textures[index].endian);
}

static void	init_textures(t_game *game)
{
	load_single_texture(game, 0, game->config.no_texture);
	load_single_texture(game, 1, game->config.so_texture);
	load_single_texture(game, 2, game->config.we_texture);
	load_single_texture(game, 3, game->config.ea_texture);
	if (game->bonus && game->config.door_texture)
	{
		game->textures[4].img = mlx_xpm_file_to_image(game->mlx,
				game->config.door_texture,
				&game->textures[4].width, &game->textures[4].height);
		if (!game->textures[4].img)
			mlx_exit_error("Failed to load door texture", game, 1);
		game->textures[4].addr = mlx_get_data_addr(game->textures[4].img,
				&game->textures[4].bits_per_pixel,
				&game->textures[4].line_length,
				&game->textures[4].endian);
	}
}

static void	init_player(t_player *player, t_game *game)
{
	player->y = get_player_y(game) + 0.5;
	player->x = get_player_x(game) + 0.5;
	player->angle = get_player_angle(game);
	player->x_cos = cos(player->angle);
	player->y_sin = sin(player->angle);
	player->key_down = false;
	player->key_up = false;
	player->key_right = false;
	player->key_left = false;
	player->left_direction = false;
	player->right_direction = false;
	player->shift = false;
	player->interact = false;
	player->show_map = 1;
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
	check_texture_paths(game);
	init_mlx(game);
	init_textures(game);
	game->is_door = 0;
	init_player(&game->player, game);
}
