/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 07:25:05 by cereais           #+#    #+#             */
/*   Updated: 2025/03/29 09:49:57 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_textures(t_game *game, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		if (game->textures[i].img)
			mlx_destroy_image(game->mlx, game->textures[i].img);
		i++;
	}
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
}

void	free_config_paths(t_game *game)
{
	if (game->config.no_texture)
		free(game->config.no_texture);
	if (game->config.so_texture)
		free(game->config.so_texture);
	if (game->config.we_texture)
		free(game->config.we_texture);
	if (game->config.ea_texture)
		free(game->config.ea_texture);
	if (game->config.door_texture)
		free(game->config.door_texture);
	game->config.no_texture = NULL;
	game->config.so_texture = NULL;
	game->config.we_texture = NULL;
	game->config.ea_texture = NULL;
	game->config.door_texture = NULL;
}
