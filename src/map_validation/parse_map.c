/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:26:13 by joseoliv          #+#    #+#             */
/*   Updated: 2025/04/13 16:28:48 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	*read_file_content(char *file_path)
{
	int		fd;
	char	*line;
	char	*content;
	char	*temp;

	content = ft_strdup("");
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = content;
		content = ft_strjoin(content, line);
		free(temp);
		free(line);
	}
	close(fd);
	return (content);
}

static void	extract_line(char *content, int *i, char **line, int *line_len)
{
	int	start;

	start = *i;
	while (content[*i] && content[*i] != '\n')
		(*i)++;
	*line_len = *i - start;
	*line = &content[start];
	if (content[*i] == '\n')
		(*i)++;
}

static bool	process_line(char *line, int len, bool *started, bool *ended)
{
	if (!(*started))
	{
		if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0
			|| ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0
			|| ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0
			|| ft_strncmp(line, "PO", 2) == 0)
			return (false);
		if (is_config_or_empty(line, len))
			return (false);
		if (line_has_map_characters(line, len))
			*started = true;
		else
			return (true);
	}
	else if (!(*ended))
	{
		if (!line_has_map_characters(line, len))
			*ended = true;
	}
	else if (len > 0 && !line_is_whitespace(line, len))
		return (true);
	return (false);
}

static bool	has_content_after_map(char *content)
{
	int		i;
	int		len;
	char	*line;
	bool	started;
	bool	ended;

	i = 0;
	started = false;
	ended = false;
	while (content[i])
	{
		extract_line(content, &i, &line, &len);
		if (process_line(line, len, &started, &ended))
			return (true);
	}
	return (false);
}

char	**parse_map_file(char *file_path)
{
	char	*content;
	char	**map;

	if (!ft_strnstr(file_path, ".cub", ft_strlen(file_path)))
		return (NULL);
	content = read_file_content(file_path);
	if (!content)
		return (NULL);
	if (content[0] == '\0' || is_empty_content(content))
	{
		free(content);
		simple_exit_error(EMPTY_MAP);
		exit(1);
	}
	if (has_content_after_map(content))
	{
		free(content);
		simple_exit_error(UNEXPECTED_FILE_CONTENT);
		exit(1);
	}
	map = ft_split(content, '\n');
	free(content);
	if (!map)
		return (NULL);
	return (map);
}
