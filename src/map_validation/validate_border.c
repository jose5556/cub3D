#include "../../includes/cub3d.h"

static bool	is_invalid_char_near_edge(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == '4');
}

static bool	check_top_bottom_edges(char *line)
{
	int	j;

	j = 0;
	while (line[j])
	{
		if (is_invalid_char_near_edge(line[j]))
			return (false);
		j++;
	}
	return (true);
}

bool	validate_map_edges(char **map)
{
	int	height;
	int	width;
	int	i;

	height = 0;
	while (map[height])
		height++;
	i = 0;
	while (map[i])
	{
		width = ft_strlen(map[i]);
		if (is_invalid_char_near_edge(map[i][0]) ||
			is_invalid_char_near_edge(map[i][width - 1]))
			return (false);
		if (i == 0 || i == height - 1)
		{
			if (!check_top_bottom_edges(map[i]))
				return (false);
		}
		i++;
	}
	return (true);
}
