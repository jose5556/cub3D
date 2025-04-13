/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_enclosure.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:25:56 by joseoliv          #+#    #+#             */
/*   Updated: 2025/04/13 16:25:57 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static bool	has_invalid_adjacent(char **map, int i, int j)
{
	if (is_invalid_tile(map[i - 1][j])
		|| is_invalid_tile(map[i + 1][j])
		|| is_invalid_tile(map[i][j - 1])
		|| is_invalid_tile(map[i][j + 1])
		|| is_invalid_tile(map[i - 1][j - 1])
		|| is_invalid_tile(map[i - 1][j + 1])
		|| is_invalid_tile(map[i + 1][j - 1])
		|| is_invalid_tile(map[i + 1][j + 1]))
		return (true);
	return (false);
}

static char	**pad_map(char **map, int height, int width)
{
	char	**padded;
	int		i;
	int		j;

	padded = malloc(sizeof(char *) * (height + 3));
	if (!padded)
		return (NULL);
	i = 0;
	while (i < height + 2)
	{
		padded[i] = malloc(width + 3);
		if (!padded[i])
			return (NULL);
		j = 0;
		while (j < width + 2)
			padded[i][j++] = ' ';
		padded[i][j] = '\0';
		i++;
	}
	padded[i] = NULL;
	i = -1;
	while (++i < height)
		ft_memcpy(padded[i + 1] + 1, map[i], ft_strlen(map[i]));
	return (padded);
}

static void	free_padded_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

static bool	check_enclosure_tiles(char **padded, int height, int width)
{
	int	i;
	int	j;

	i = 1;
	while (i <= height)
	{
		j = 1;
		while (j <= width)
		{
			if (padded[i][j] == '0' || padded[i][j] == 'N'
				|| padded[i][j] == 'S' || padded[i][j] == 'E'
				|| padded[i][j] == 'W' || padded[i][j] == '4')
			{
				if (has_invalid_adjacent(padded, i, j))
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	validate_space_enclosure(char **map)
{
	int		height;
	int		width;
	char	**padded;

	height = 0;
	width = 0;
	while (map[height])
	{
		if ((int)ft_strlen(map[height]) > width)
			width = ft_strlen(map[height]);
		height++;
	}
	padded = pad_map(map, height, width);
	if (!padded)
		return (false);
	if (!check_enclosure_tiles(padded, height, width))
	{
		free_padded_map(padded);
		return (false);
	}
	free_padded_map(padded);
	return (true);
}
