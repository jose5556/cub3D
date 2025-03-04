/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:56:36 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/04 15:56:25 by joseoliv         ###   ########.fr       */
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
# include <stdbool.h>

//SCREEN SIZE
# define HEIGHT	720
# define WIDTH	1280

//ERROR MESSAGES
# define STANDART_ERROR		"Error\n"
# define ARGUMENTS_ERROR	"Invalid number of arguments\n"

//KEYCODES
# define W				119
# define A				97
# define S				115
# define D				100

//COLORS HEXADECIMAL
# define BLACK			0x000000
# define WHITE			0xFFFFFF
# define RED			0xFF0000
# define GREEN			0x00FF00

//PI
# define PI 3.14159265359

typedef struct s_player
{
	float	x;
	float	y;
	float	angle;
	int		size;
	bool	key_up;
    bool	key_down;
    bool	key_left;
    bool	key_right;	
	bool	left_direction;
	bool	right_direction;
}	t_player;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_player	player;
}	t_game;

//init
void	init(t_game *game);

//render
int		render_cub3d(void *param);
void	my_mlx_pixel_put(t_img *vars, int x, int y, int color);

//events
int		close_program_hook(t_game *game);
int		hooks_listener(t_game *game);
int		handle_keys_press(int keycode, t_game *game);
int		handle_keys_released(int keycode, t_game *game);
void	move_player(t_player *player);


//temp
void	draw_square(int color, t_game *game);

#endif