/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:26:07 by joseoliv          #+#    #+#             */
/*   Updated: 2025/04/13 16:26:08 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static bool	check_comma_count(const char *str)
{
	int	i;
	int	comma_count;

	i = 0;
	comma_count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			comma_count++;
		i++;
	}
	if (comma_count != 2)
	{
		return (simple_exit_error(INVALID_RGB));
	}
	return (true);
}

static bool	validate_and_convert(char *value, int *rgb_component)
{
	char	*trimmed;
	int		j;

	j = 0;
	trimmed = ft_strtrim(value, " \t\n\r");
	if (!trimmed)
		return (false);
	while (trimmed[j])
	{
		if (!ft_isdigit(trimmed[j]))
		{
			free(trimmed);
			return (simple_exit_error(INVALID_RGB));
		}
		j++;
	}
	*rgb_component = ft_atoi_int(trimmed);
	free(trimmed);
	if (*rgb_component < 0 || *rgb_component > 255)
	{
		return (simple_exit_error(INVALID_RGB));
	}
	return (true);
}

static bool	extract_rgb_components(char **values, int rgb[3])
{
	int	i;

	i = 0;
	while (values[i] && i < 3)
	{
		if (!validate_and_convert(values[i], &rgb[i]))
		{
			ft_free_array(values);
			return (false);
		}
		i++;
	}
	if (i != 3)
	{
		ft_free_array(values);
		return (simple_exit_error(INVALID_RGB));
	}
	return (true);
}

bool	parse_rgb_values(char *str, int rgb[3])
{
	char	**values;
	int		count;

	count = 0;
	if (!check_comma_count(str))
		return (false);
	values = ft_split(str, ',');
	if (!values)
		return (false);
	while (values[count])
		count++;
	if (count > 3)
	{
		ft_free_array(values);
		return (simple_exit_error(INVALID_RGB));
	}
	if (!extract_rgb_components(values, rgb))
		return (false);
	ft_free_array(values);
	return (true);
}

bool	store_rgb_values(char *line, t_map_config *config)
{
	char	*values;
	bool	result;

	values = ft_strtrim(line + 2, " \t\n\r");
	if (!values)
		return (false);
	if (line[0] == 'F')
	{
		result = parse_rgb_values(values, config->floor_rgb);
		config->floor_found = result;
	}
	else
	{
		result = parse_rgb_values(values, config->ceiling_rgb);
		config->ceiling_found = result;
	}
	free(values);
	return (result);
}
