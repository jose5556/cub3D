/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cereais <cereais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:07:09 by joseoliv          #+#    #+#             */
/*   Updated: 2025/04/16 14:43:20 by cereais          ###   ########.fr       */
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

static void	handle_interactions(int keycode, t_game *game)
{
	if (keycode == E)
	{
		if (!(game->player.interact))
			game->player.interact = true;
		else if (!is_inside_door(game->player.x, game->player.y, game))
			game->player.interact = false;
	}
	if (keycode == XK_m)
	{
		if (game->player.show_map)
			game->player.show_map = false;
		else
			game->player.show_map = true;
	}
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
	if (game->bonus)
	{
		if (keycode == E || keycode == XK_m)
			handle_interactions(keycode, game);
	}
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
	double		angle_speed;
	int			delta_x;

	(void)y;
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
