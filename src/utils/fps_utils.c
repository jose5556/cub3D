/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cereais <cereais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 16:33:03 by cereais           #+#    #+#             */
/*   Updated: 2025/03/19 19:40:54 by cereais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static double	get_ticks(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

static double	calculate_fps(double old_time)
{
	double	time;
	double	frame_time;
	double	fps;

	time = get_ticks();
	frame_time = (time - old_time) / 1000.0;
	if (frame_time > 0)
		fps = (1.0 / frame_time);
	else
		fps = 0;
	return (fps);
}

static void	update_fps_buffer(double fps_buffer[], int *index,
		int *count, double fps)
{
	fps_buffer[*index] = fps;
	*index = (*index + 1) % FRAME_AVERAGE;
	if (*count < FRAME_AVERAGE)
		(*count)++;
}

static double	calculate_avg_fps(const double fps_buffer[], int count)
{
	double	avg_fps;
	int		i;

	avg_fps = 0;
	i = -1;
	while (++i < count)
		avg_fps += fps_buffer[i];
	avg_fps /= count;
	return (avg_fps);
}

double	get_fps(void)
{
	static double	old_time = 0;
	static double	fps_buffer[FRAME_AVERAGE];
	static int		index = 0;
	static int		count = 0;
	double			fps;

	fps = calculate_fps(old_time);
	old_time = get_ticks();
	update_fps_buffer(fps_buffer, &index, &count, fps);
	return (calculate_avg_fps(fps_buffer, count));
}
