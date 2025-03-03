/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:56:36 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/03 17:19:03 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/minilibx-linux/mlx.h"
# include "../libs/libft/libft.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>

# define HEIGHT	800
# define WIDTH	800
# define ERROR_MESSAGE "ERROR\n"

# define BLACK				0x000000
# define WHITE				0xFFFFFF
# define RED				0xFF0000

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img		img;
}	t_data;

//init
void	init(t_data *data);

//render
int		render_cub3d(void *param);
void	handle_pixel(int x, int y, t_data *data);
void	my_mlx_pixel_put(t_img *vars, int x, int y, int color);

//events
int		close_program(t_data *data);
int		hooks_listener(t_data *data);
int		handle_keys(int keycode, t_data *data);





#endif