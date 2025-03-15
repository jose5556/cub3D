/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cereais <cereais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:40:15 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/15 20:13:10 by cereais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	my_mlx_pixel_put(t_img *vars, int x, int y, int color)
{
	char	*dst;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	dst = vars->addr + (y * vars->line_length + x
			* (vars->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

float	degree_to_radians(int a) 
{ 
	return (a * PI / 180.0);
}

bool	touch_wall(float px, float py, t_game *game)
{
	int x;
	int y;

	x = px / SIZE;
	y = py / SIZE;
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return true;
	if (game->map[y][x] == '1')
		return true;
	return false;
}
