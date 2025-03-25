/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cub3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:18:14 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/25 03:02:11 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	render_cub3d(void *param)
{
	t_game	*game;
	double	fraction;
	double	start_x;

	game = (t_game *)param;
	move_player(game);
	clear_image(game);
	paint_floor_ceil(game);
	set_ray_parameters(game, &fraction, &start_x);
	render_raycaster(game, start_x, fraction);
	draw_map(game);
	draw_player(SIZE / 4, GREEN, game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}
