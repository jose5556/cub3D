/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:06:23 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/29 09:29:49 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	init_textures(t_game *game)
{
	int	i;
	int	max;

	i = -1;
	max = 4;
	game->textures[0].img = mlx_xpm_file_to_image(game->mlx, "assets/textures/simonkraft/respawn_anchor_side0.xpm",			//east
		&game->textures[0].width, &game->textures[0].height);
	if (!(game->textures[0].img))
		simple_exit_error("Failed to load texture");
	game->textures[1].img = mlx_xpm_file_to_image(game->mlx, "assets/textures/simonkraft/respawn_anchor_side2.xpm",			//west
		&game->textures[1].width, &game->textures[1].height);
	if (!(game->textures[1].img))
		texture_exit_error(2, game);
	game->textures[2].img = mlx_xpm_file_to_image(game->mlx, "assets/textures/simonkraft/respawn_anchor_side4.xpm",  		//south
		&game->textures[2].width, &game->textures[2].height);
	if (!(game->textures[2].img))
		texture_exit_error(3, game);
	game->textures[3].img = mlx_xpm_file_to_image(game->mlx, "assets/textures/simonkraft/respawn_anchor_side3.xpm",			//north
		&game->textures[3].width, &game->textures[3].height);
	if (!(game->textures[3].img))
		texture_exit_error(4, game);
	if (game->bonus)
	{
		game->textures[4].img = mlx_xpm_file_to_image(game->mlx, "assets/textures/wolfenstein/wood.xpm", //door
			&game->textures[4].width, &game->textures[4].height);
		if (!(game->textures[4].img))
			texture_exit_error(5, game);
		max++;
	}
	while (++i < max)
	{
		game->textures[i].addr = mlx_get_data_addr(game->textures[i].img,
			&game->textures[i].bits_per_pixel, &game->textures[i].line_length,
			&game->textures[i].endian);
	}

	game->rgb.ceil_color = ft_calloc(sizeof(int *), 4);
	game->rgb.floor_color = ft_calloc(sizeof(int *), 4);

	game->rgb.ceil_color[0] = 35;
	game->rgb.ceil_color[1] = 19;
	game->rgb.ceil_color[2] = 73;

	game->rgb.floor_color[0] = 15;
	game->rgb.floor_color[1] = 6;
	game->rgb.floor_color[2] = 40;
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
	player->show_map = true;
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
	init_textures(game);
	game->map = get_map();
	game->is_door = 0;
	init_player(&game->player, game);
}
