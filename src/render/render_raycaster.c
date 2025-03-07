/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_raycaster.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cereais <cereais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:27:32 by cereais           #+#    #+#             */
/*   Updated: 2025/03/07 17:28:39 by cereais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    draw_line(t_game *game, float start_x, int i)
{
	float ray_x;
	float ray_y;

	ray_x = game->player.x;
	ray_y = game->player.y;
	while(!touch_wall(ray_x, ray_y, game))
	{
		my_mlx_pixel_put(&game->img, ray_x, ray_y, RED);
		ray_x += game->player.x_cos;
		ray_y += game->player.y_sin;
	}
}
