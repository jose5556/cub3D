/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:56:22 by joseoliv          #+#    #+#             */
/*   Updated: 2025/04/13 16:24:25 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (simple_exit_error(ARGUMENTS_ERROR));
	ft_bzero(&game, sizeof(t_game));
	if (BONUS == 1)
		game.bonus = 1;
	else
		game.bonus = 0;
	game.map = parse_map_file(argv[1]);
	if (!game.map)
		return (simple_exit_error(INVALID_MAP_FILE));
	if (!validate_map(&game))
	{
		free_config_paths(&game);
		if (game.map)
			ft_free_array(game.map);
		return (0);
	}
	init(&game);
	render_cub3d(&game);
	hooks_listener(&game);
	mlx_loop_hook(game.mlx, render_cub3d, &game);
	mlx_loop(game.mlx);
}
