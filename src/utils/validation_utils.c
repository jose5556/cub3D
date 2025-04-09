#include "../../includes/cub3d.h"

bool	is_invalid_tile(char c)
{
	return (c == ' ');
}

bool	is_line_empty(char *trimmed)
{
	return (trimmed[0] == '\n' || trimmed[0] == '\0');
}

bool	is_map_char(char c)
{
	return (c == '1' || c == '0' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W' || c == '4');
}

bool	line_has_map_characters(const char *line, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (is_map_char(line[i]))
			return (true);
		i++;
	}
	return (false);
}

bool	line_is_whitespace(const char *line, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (false);
		i++;
	}
	return (true);
}
