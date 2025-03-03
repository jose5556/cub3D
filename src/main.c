/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:56:22 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/03 17:54:20 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(void)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	//map_validation();  TODO
	init(&data);
	render_cub3d(&data);
	hooks_listener(&data);
	mlx_loop_hook(data.mlx, render_cub3d, &data);
	mlx_loop(data.mlx);
}
