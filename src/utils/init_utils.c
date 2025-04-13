/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:25:04 by joseoliv          #+#    #+#             */
/*   Updated: 2025/04/13 18:17:52 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_xpm_header(char *path)
{
	int		fd;
	char	buf[5];
	int		ret;
	size_t	len;

	len = ft_strlen(path);
	if (ft_strncmp(path + len - 4, ".xpm", 4) != 0)
		return (0);
	if (ft_strncmp(path + len - 5, "/.xpm", 5) == 0)
		return (false);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	ret = read(fd, buf, 4);
	close(fd);
	if (ret != 4)
		return (0);
	buf[4] = '\0';
	if (ft_strncmp(buf, "/* X", 4) != 0)
		return (0);
	return (1);
}

void	check_texture_paths(t_game *game)
{
	if (!check_xpm_header(game->config.no_texture))
		mlx_exit_error("Failed to load texture", game, 0);
	if (!check_xpm_header(game->config.so_texture))
		mlx_exit_error("Failed to load texture", game, 0);
	if (!check_xpm_header(game->config.we_texture))
		mlx_exit_error("Failed to load texture", game, 0);
	if (!check_xpm_header(game->config.ea_texture))
		mlx_exit_error("Failed to load texture", game, 0);
	if (game->bonus && game->config.door_texture)
	{
		if (!check_xpm_header(game->config.door_texture))
			mlx_exit_error("Failed to load texture", game, 0);
	}
}
