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
	printf("%s%s\n", STANDARD_ERROR, error_message);
	return (0);
}

void	mlx_exit_error(char *error_message, t_game *game, int error)
{
	free_config_paths(game);
	if (error == 1)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	else if (error == 2)
	{
		if (game->img.img)
			mlx_destroy_image(game->mlx, game->img.img);
		free_textures(game, 4);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map)
		ft_free_array(game->map);
	printf("%s%s\n", STANDARD_ERROR, error_message);
	exit(EXIT_FAILURE);
}
