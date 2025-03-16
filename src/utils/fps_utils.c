/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cereais <cereais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 16:33:03 by cereais           #+#    #+#             */
/*   Updated: 2025/03/16 19:36:51 by cereais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	get_ticks(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

double	get_fps(void)
{
	static double	old_time = 0;
	static double	fps_buffer[FRAME_AVERAGE];
	static int		index = 0;
	static int		count = 0;
	double			time;
	double			frame_time;
	double			fps;
	int				i;
	double			avg_fps;

	i = -1;
	time = get_ticks();
	frame_time = (time - old_time) / 1000.0;
	if (frame_time > 0)
		fps = (1.0 / frame_time);
	else
		fps = 0;
	old_time = time;
	fps_buffer[index] = fps;
	index = (index + 1) % FRAME_AVERAGE;
	if (count < FRAME_AVERAGE)
		count++;
	avg_fps = 0;
	while (++i < count)
		avg_fps += fps_buffer[i];
	avg_fps /= count;
	return (avg_fps);
}
