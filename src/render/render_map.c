/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:34:55 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/22 06:10:14 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* char **get_map(void)   //temp func
{
    char	**map;
    int     i = -1;

	map = malloc(sizeof(char *) * 28);
    map[++i] = "111111111111111";
	map[++i] = "111111000111111";
    map[++i] = "111110000011111";
    map[++i] = "111100000001111";
    map[++i] = "111000000000111";
    map[++i] = "110000000000011";
    map[++i] = "100001111100001";
	map[++i] = "110000101S00011";
	map[++i] = "111000010000111";
	map[++i] = "111100000001111";
	map[++i] = "111111444111111";
	map[++i] = "111111000111111";
	map[++i] = "111111000111111";
    map[++i] = "100000000111111";
	map[++i] = "111111000111111";
    map[++i] = "111110000011111";
    map[++i] = "111100000001111";
    map[++i] = "111000000000111";
    map[++i] = "110000000000011";
    map[++i] = "100001111100001";
	map[++i] = "110000101000011";
	map[++i] = "111000010000111";
	map[++i] = "111100000001111";
	map[++i] = "111110000011111";
	map[++i] = "111111000111111";
	map[++i] = "111111111111111";
    map[++i] = NULL;
    return (map);
} */

char **get_map(void)   //temp func
{
    char	**map;
    int     i = -1;

	map = malloc(sizeof(char *) * 13);
    map[++i] = "111111111111111";
	map[++i] = "100100000000001";
	map[++i] = "100000000N00001";
	map[++i] = "100000000000001";
    map[++i] = "100000000000001";
    map[++i] = "101010141010101";
    map[++i] = "100000000000001";
    map[++i] = "100000000000001";
    map[++i] = "100000000000001";
    map[++i] = "100000000000001";
	map[++i] = "111111111111111";
    map[++i] = NULL;
    return (map);
}
