/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cereais <cereais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:56:22 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/19 18:48:30 by cereais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(void)
{
	t_game	game;

	/* if (argc != 2)
		return (simple_exit_error(ARGUMENTS_ERROR)); */
	ft_bzero(&game, sizeof(t_game));
	ft_bzero(&game.img, sizeof(t_img));
	//map_validation();  TODO
	init(&game);
	render_cub3d(&game);
	hooks_listener(&game);
	mlx_loop_hook(game.mlx, render_cub3d, &game);
	mlx_loop(game.mlx);
}

// https://lodev.org/cgtutor/raycasting.html

//Stubborn bugs that still make me wanna cry

// 1-> minimap size

//TODO
// 1-> texture
// 2-> doors