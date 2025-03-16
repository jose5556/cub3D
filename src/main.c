/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cereais <cereais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:56:22 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/16 19:28:31 by cereais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://lodev.org/cgtutor/raycasting.html

#include "../includes/cub3d.h"

int	main(void)
{
	t_game	game;

	/* if (argc != 2)
		return (simple_exit_error(ARGUMENTS_ERROR)); */
	ft_bzero(&game, 0);
	ft_bzero(&game.mlx, 0);
	//map_validation();  TODO
	init(&game);
	render_cub3d(&game);
	hooks_listener(&game);
	mlx_loop_hook(game.mlx, render_cub3d, &game);
	mlx_loop(game.mlx);
}
