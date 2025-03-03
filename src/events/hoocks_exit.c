/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hoocks_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:13:24 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/03 17:46:28 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	close_program(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit (EXIT_SUCCESS);
	return (0);
}
