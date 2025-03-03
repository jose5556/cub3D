/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:07:09 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/03 17:19:36 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	hooks_listener(t_data *data)
{
	mlx_hook(data->win, KeyPress, KeyPressMask,
		handle_keys, data);
	mlx_hook(data->win, DestroyNotify, NoEventMask,
		close_program, data);
	return (0);
}

int	handle_keys(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		close_program(data);
	return (0);
}
