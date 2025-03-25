/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error_message.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:09:18 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/25 04:46:06 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	simple_exit_error(char *error_message)
{
	printf("%s%s\n", STANDART_ERROR, error_message);
	exit (0);
}

void	mlx_exit_error(char *error_message, t_game *game, int error)
{
	if (error == 1)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	else if (error == 2)
	{
		mlx_destroy_display(game->mlx);
		mlx_destroy_window(game->mlx, game->win);
		free(game->mlx);
	}
	printf("%s%s\n", STANDART_ERROR, error_message);
	exit(EXIT_FAILURE);
}

void	texture_exit_error(int i, t_game *game)
{
	free_textures(game, i);
	if (game->img.img)
		mlx_destroy_image(game->mlx, game->img.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	simple_exit_error("Failed to load texture");
}
