/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cereais <cereais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:56:36 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/07 16:12:18 by cereais          ###   ########.fr       */
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
# define SIZE	64

//ERROR MESSAGES
# define STANDART_ERROR		"Error\n"
# define ARGUMENTS_ERROR	"Invalid number of arguments\n"
# define MLX_INIT_ERROR		"Impossible to connect with mlx api, please try again later\n"
# define MLX_WINDOW_ERROR	"Impossible to create a new window, please try again later\n"
# define MLX_IMAGE_ERROR	"Impossible to create a new image, please try again later\n"

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
# define GRAY			0x888888
# define BLUE			0x00008B

//PI
# define PI 3.14159265359

typedef struct s_player
{
	int		x;
	int		y;
	float	angle;
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
	char		**map;   //temp
	t_img		img;
	t_player	player;
}	t_game;

//init
void	init(t_game *game);

//render
int		render_cub3d(void *param);
void	draw_player(int size, int color, t_game *game);

//events
int		hooks_listener(t_game *game);
int		handle_keys_press(int keycode, t_game *game);
int		handle_keys_released(int keycode, t_game *game);

//exit
int		close_program_hook(t_game *game);
int		simple_exit_error(char *error_message);
void	mlx_exit_error(char *error_message, t_game *game, int error);

//player
float	get_player_angle(t_game *game);
void	move_player(t_game *game);
int		get_player_x(t_game *game);
int		get_player_y(t_game *game);

//render_map temp
void	draw_square(int x, int y, int size, int color, t_game *game);
char	**get_map(void);
void	draw_map(t_game *game);

//utils
void	my_mlx_pixel_put(t_img *vars, int x, int y, int color);
bool	touch_wall(float px, float py, t_game *game);

#endif