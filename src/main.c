/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cereais <cereais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:56:22 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/27 04:48:27 by cereais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(void)
{
	t_game	game;

	/* if (argc != 2)
		simple_exit_error(ARGUMENTS_ERROR); */
	ft_bzero(&game, sizeof(t_game));
	//map_validation();  TODO
	ft_printf("%d\n", BONUS);
	init(&game);
	render_cub3d(&game);
	hooks_listener(&game);
	mlx_loop_hook(game.mlx, render_cub3d, &game);
	mlx_loop(game.mlx);
}

// https://lodev.org/cgtutor/raycasting.html

//TODO

//	1-> handle properly the exit if texture is not valid


//AT BONUS, WE NEED TO CHECK IF THE DOOR HAS VALID MAP BEHIND