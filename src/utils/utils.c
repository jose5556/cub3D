/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:40:15 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/04 17:40:31 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	my_mlx_pixel_put(t_img *vars, int x, int y, int color)
{
	char	*dst;

	if(x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
        return ;
	dst = vars->addr + (y * vars->line_length + x
			* (vars->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
