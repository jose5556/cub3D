/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cub3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cereais <cereais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:18:14 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/18 22:35:29 by cereais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	render_cub3d(void *param)
{
	t_game	*game;
	float	fraction;
	float	start_x;

	game = (t_game *)param;
	//printf("%f\n", get_fps());
	move_player(game);
	clear_image(game);
	set_ray_parameters(game, &fraction, &start_x);
	render_raycaster(game, start_x, fraction);
	draw_map(game);  //minimap?
	draw_player(SIZE / 2, GREEN, game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}
