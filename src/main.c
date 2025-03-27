/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cereais <cereais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:56:22 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/27 08:01:16 by cereais          ###   ########.fr       */
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
	if (BONUS == 1)
	{
		game.bonus = 1;
		ft_printf("in main, bonus is -> %d\n", game.bonus);
	}
	else
	{
		game.bonus = 0;
		ft_printf("in main, bonus is -> %d\n", game.bonus);
	}
	init(&game);
	render_cub3d(&game);
	hooks_listener(&game);
	mlx_loop_hook(game.mlx, render_cub3d, &game);
	mlx_loop(game.mlx);
}

// https://lodev.org/cgtutor/raycasting.html

//TODO

//


//AT BONUS, WE NEED TO CHECK IF THE DOOR HAS VALID MAP BEHIND