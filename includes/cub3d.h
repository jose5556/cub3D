/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:56:36 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/29 09:29:28 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BONUS
#  define BONUS 1
# endif

# include "../libs/minilibx-linux/mlx.h"
# include "../libs/libft/libft.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <stdbool.h>
# include <sys/time.h>

//SCREEN / PLAYER SIZE
//# define HEIGHT			1080
# define HEIGHT			720
//# define WIDTH			1980
# define WIDTH			1280
# define SIZE			10
# define RADIUS			4

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
# define E				101

//COLORS HEXADECIMAL
# define BLACK			0x000000
# define WHITE			0xFFFFFF
# define RED			0xFF0000
# define PURPLE			0xA020F0
# define PINK			0xFF0084
# define BROWN			0x964B00
# define GREEN			0x00FF00
# define GRAY			0x888888
# define BLUE			0x00008B
# define LIGHT_BLUE		0xADD8E6
# define YELLOW			0xFFB343

//PI
# define PI 3.141592653589793238462643383279502884197

//FPS STABILIZER
# define FRAME_AVERAGE 60

typedef struct s_bob
{
	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_bob;

typedef struct s_raycaster
{
	double	x;
	double	y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
	double	dir_x;
	double	dir_y;
}	t_ray;

typedef struct s_player
{
	double	x;
	double	y;
	double	x_cos;
	double	y_sin;
	double	angle;
	bool	show_map;
	bool	shift;
	bool	key_up;
	bool	key_down;
	bool	key_left;
	bool	key_right;	
	bool	interact;
	bool	left_direction;
	bool	right_direction;
}	t_player;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_texture;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_rgb
{
	int	*floor_color;
	int	*ceil_color;
}	t_rgb;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			is_door;
	bool		bonus;
	t_img		img;
	t_texture	textures[5];
	t_player	player;
	t_ray		ray;
	t_bob		bob;
	t_rgb		rgb;
}	t_game;

//init
void	init(t_game *game);

//render
int		render_cub3d(void *param);
void	render_raycaster(t_game *game, double start_x, double fraction);

//events
int		hooks_listener(t_game *game);
int		handle_keys_press(int keycode, t_game *game);
int		handle_keys_released(int keycode, t_game *game);
int		handle_mouse(int x, int y, t_game *game);

//exit
int		close_program_hook(t_game *game);
int		simple_exit_error(char *error_message);
void	mlx_exit_error(char *error_message, t_game *game, int error);
void	texture_exit_error(int i, t_game *game);

//player
double	get_player_angle(t_game *game);
void	move_player(t_game *game);
int		get_player_x(t_game *game);
int		get_player_y(t_game *game);

//render_map temp
char	**get_map(void);

//pixels_handler
void	paint_walls(t_game *game, t_bob *bob, int wall_color, int pixel_x);
void	my_mlx_pixel_put(t_img *vars, int x, int y, int color);
void	draw_player(int size, int color, t_game *game);
void	clear_image(t_game *game);
void	draw_map(t_game *game);
void	draw_player(int size, int color, t_game *game);
void	paint_floor_ceil(t_game *game);

//utils
bool	touch_wall(double px, double py, t_game *game);
bool	is_inside_wall(double px, double py, t_game *game);
bool	is_inside_door(double px, double py, t_game *game);
void	set_ray_parameters(t_game *game, double *fraction, double *start_x);
void	calculate_ray_direction(double start_x, t_ray *ray);
double	degree_to_radians(double a);
double	get_fps(void);
void	free_textures(t_game *game, int max);
unsigned long	convert_rgb(int	*rgb);

#endif