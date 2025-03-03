/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:43:56 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/03 20:59:48 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_player(t_player *player)
{
	int	speed;

	speed = 7;
	if (player->key_left)
		player->x -= speed;
	if (player->key_right)
		player->x += speed;
	if (player->key_up)
		player->y -= speed;
	if (player->key_down)
		player->y += speed;
}
