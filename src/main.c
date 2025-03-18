/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cereais <cereais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:56:22 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/18 21:38:39 by cereais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://lodev.org/cgtutor/raycasting.html

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

//bus that make me wanna cry

// 1-> player can go throw some corners that has valid map behind;
// 2-> if the map has diferent rows, minimap is a bit buggy, but game has no probs;

//TODO
// 1-> circular radius colision;