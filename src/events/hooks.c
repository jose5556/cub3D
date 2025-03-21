/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cereais <cereais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:07:09 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/21 07:06:24 by cereais          ###   ########.fr       */
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
		close_program_hook, game);
	mlx_hook(game->win, MotionNotify, PointerMotionMask,
		handle_mouse, game);
	return (0);
}

int	handle_keys_press(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		close_program_hook(game);
	if (keycode == A)
		game->player.key_left = true;
	if (keycode == S)
		game->player.key_down = true;
	if (keycode == W)
		game->player.key_up = true;
	if (keycode == D)
		game->player.key_right = true;
	if (keycode == XK_Left)
		game->player.left_direction = true;
	if (keycode == XK_Right)
		game->player.right_direction = true;
	if (keycode == XK_Shift_L)
		game->player.shift = true;
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
	if (keycode == XK_Left)
		game->player.left_direction = false;
	if (keycode == XK_Right)
		game->player.right_direction = false;
	if (keycode == XK_Shift_L)
		game->player.shift = false;
	return (0);
}

int	handle_mouse(int x, int y, t_game *game)
{
	static int	previous_mouse_x = -1;
	int			delta_x;
	double 		angle_speed;

	if (previous_mouse_x == -1)
		previous_mouse_x = x;
	else
	{
		delta_x = x - previous_mouse_x;
		angle_speed = 0.005;
		game->player.angle += delta_x * angle_speed;
		game->player.angle = fmod(game->player.angle, 2 * PI);
		if (game->player.angle < 0)
			game->player.angle += 2 * PI;
		game->player.x_cos = cos(game->player.angle);
		game->player.y_sin = sin(game->player.angle);
		previous_mouse_x = x;
	}
	return (0);
}
