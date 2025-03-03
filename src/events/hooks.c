/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:07:09 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/03 18:52:35 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	hooks_listener(t_game *game)
{
	mlx_hook(game->win, KeyPress, KeyPressMask,
		handle_keys, game);
	mlx_hook(game->win, DestroyNotify, NoEventMask,
		close_program, game);
	return (0);
}

int	handle_keys(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		close_program(game);
	return (0);
}
