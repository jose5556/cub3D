/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:56:22 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/25 02:27:56 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(void)
{
	t_game	game;

	/* if (argc != 2)
		return (simple_exit_error(ARGUMENTS_ERROR)); */
	ft_bzero(&game, sizeof(t_game));
	//map_validation();  TODO
	init(&game);
	render_cub3d(&game);
	hooks_listener(&game);
	mlx_loop_hook(game.mlx, render_cub3d, &game);
	mlx_loop(game.mlx);
}

// https://lodev.org/cgtutor/raycasting.html

//TODO

//	1-> sprits
//	2-> handle properly the exit if texture is not valid


//AT BONUS, WE NEED TO CHECK IF THE DOOR HAS VALID MAP BEHIND