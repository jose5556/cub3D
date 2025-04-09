#include "../../includes/cub3d.h"

bool	is_config_or_empty(char *line, int len)
{
	int	j;

	if (len == 0 || line_is_whitespace(line, len))
		return (true);
	j = 0;
	while (j < len && (line[j] == ' ' || line[j] == '\t'))
		j++;
	return (is_config_line_start(&line[j]));
}
