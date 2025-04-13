/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzinchen <dzinchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:24:41 by joseoliv          #+#    #+#             */
/*   Updated: 2025/04/13 17:18:42 by dzinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

bool	has_cub_extension(char *file_path)
{
	size_t	len;

	len = ft_strlen(file_path);
	if (ft_strncmp(file_path + len - 4, ".cub", 4) != 0)
		return (false);
	if (ft_strncmp(file_path + len - 5, "/.cub", 5) == 0)
		return (false);
	return (true);
}
