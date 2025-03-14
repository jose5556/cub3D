/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:56:22 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/14 03:18:18 by joseoliv         ###   ########.fr       */
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
	//map_validation();  TODO
	init(&game);
	render_cub3d(&game);
	hooks_listener(&game);
	mlx_loop_hook(game.mlx, render_cub3d, &game);
	mlx_loop(game.mlx);
}
