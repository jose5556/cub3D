/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:24:41 by joseoliv          #+#    #+#             */
/*   Updated: 2025/04/13 16:24:42 by joseoliv         ###   ########.fr       */
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
