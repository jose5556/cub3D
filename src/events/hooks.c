/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:07:09 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/03 21:00:32 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	hooks_listener(t_game *game)
{
	mlx_hook(game->win, KeyPress, KeyPressMask,
		handle_keys_press, game);
	mlx_hook(game->win, KeyRelease, KeyReleaseMask,
		handle_keys_released, game);
	mlx_hook(game->win, DestroyNotify, NoEventMask,
		close_program, game);
	return (0);
}

int	handle_keys_press(int keycode, t_game *game)
{
	float	speed;

	speed = 5;
	if (keycode == XK_Escape)
		close_program(game);
	if (keycode == A)
		game->player.key_left = true;
	if (keycode == S)
		game->player.key_down = true;
	if (keycode == W)
		game->player.key_up = true;
	if (keycode == D)
		game->player.key_right = true;
	return (0);
}

int	handle_keys_released(int keycode, t_game *game)
{
	if (keycode == A)
		game->player.key_left = false;
	if (keycode == S)
		game->player.key_down = false;
	if (keycode == W)
		game->player.key_up = false;
	if (keycode == D)
		game->player.key_right = false;
}
