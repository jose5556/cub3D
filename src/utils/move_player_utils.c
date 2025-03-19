/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cereais <cereais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:53:57 by cereais           #+#    #+#             */
/*   Updated: 2025/03/19 22:54:41 by cereais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	is_inside_wall(float px, float py, float radius, t_game *game)
{
	if (px < 0 || px >= WIDTH || py < 0 || py >= HEIGHT)
		return (true);
	if (game->map[(int)(py - radius)][(int)(px - radius)] == '1' ||
		game->map[(int)(py - radius)][(int)(px + radius)] == '1' ||
		game->map[(int)(py + radius)][(int)(px - radius)] == '1' ||
		game->map[(int)(py + radius)][(int)(px + radius)] == '1')
		return (true);
	return (false);
}
