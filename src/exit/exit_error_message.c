/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error_message.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:09:18 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/25 02:26:03 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	simple_exit_error(char *error_message)
{
	printf("%s%s\n", STANDART_ERROR, error_message);
	return (0);
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
	else if (error == 3)
	{
		mlx_destroy_display(game->mlx);
		mlx_destroy_window(game->mlx, game->win);
		free(game->mlx);
		free_textures(game, 4);
	}
	printf("%s%s\n", STANDART_ERROR, error_message);
	exit(EXIT_FAILURE);
}
