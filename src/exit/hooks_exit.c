/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:13:24 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/29 09:49:22 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	close_program_hook(t_game *game)
{
	int	normal_textures_counter;

	normal_textures_counter = 4;
	free_textures(game, normal_textures_counter + BONUS);
	if (game->img.img)
		mlx_destroy_image(game->mlx, game->img.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game->map);
	exit (EXIT_SUCCESS);
	return (0);
}
