/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:56:36 by joseoliv          #+#    #+#             */
/*   Updated: 2025/03/29 09:53:29 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

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
# include <fcntl.h>

//SCREEN / PLAYER SIZE
//# define HEIGHT			1080
# define HEIGHT			720
//# define WIDTH			1980
# define WIDTH			1280
# define SIZE			10
# define RADIUS			4

//ERROR MESSAGES
# define STANDARD_ERROR		"Error\n"

# define ARGUMENTS_ERROR	"Invalid number of arguments"

# define MLX_INIT_ERROR		"Impossible to connect with mlx api, \
please try again later"

# define MLX_WINDOW_ERROR	"Impossible to create a new window, \
please try again later"

# define MLX_IMAGE_ERROR	"Impossible to create a new image, \
please try again later"

# define MISSING_TEXTURE_ERROR	"Missing texture"

# define INVALID_TEXTURE_PATH	"Invalid texture path"

# define INVALID_RGB	"Invalid RGB Configuration"

# define DUPLICATE_TEXTURE	"Duplicate texture found"

# define OPEN_SPACES	"Map contains invalid open spaces"

# define WALKABLE_TILES	"Map has walkable tiles on the edge"

# define PLAYER_COUNT	"Map must contain exactly one player"

# define MISSING_PO	"Door tile found but no PO texture provided"

# define EMPTY_MAP "Empty map"

# define INVALID_MAP_FILE "Invalid map file"

# define UNEXPECTED_FILE_CONTENT "Unexpected content found after file validation"

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

typedef struct s_map_config
{
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	char	*door_texture;
	bool	no_found;
	bool	so_found;
	bool	we_found;
	bool	ea_found;
	bool	door_found;
	bool	floor_found;
	bool	ceiling_found;
	bool	config_section_done;
	int		floor_rgb[3];
	int		ceiling_rgb[3];
}	t_map_config;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	char			**map;
	int				is_door;
	bool			bonus;
	t_img			img;
	t_texture		textures[5];
	t_player		player;
	t_ray			ray;
	t_bob			bob;
	t_map_config	config;
}	t_game;

//init
void			init(t_game *game);

//render
int				render_cub3d(void *param);
void			render_raycaster(t_game *game, double start_x, double fraction);

//events
int				hooks_listener(t_game *game);
int				handle_keys_press(int keycode, t_game *game);
int				handle_keys_released(int keycode, t_game *game);
int				handle_mouse(int x, int y, t_game *game);

//exit
int				close_program_hook(t_game *game);
int				simple_exit_error(char *error_message);
void			mlx_exit_error(char *error_message, t_game *game, int error);

//player
double			get_player_angle(t_game *game);
void			move_player(t_game *game);
int				get_player_x(t_game *game);
int				get_player_y(t_game *game);

//pixels_handler
void			paint_walls(t_game *game, t_bob *bob,
					int wall_color, int pixel_x);
void			my_mlx_pixel_put(t_img *vars, int x, int y, int color);
void			draw_player(int size, int color, t_game *game);
void			clear_image(t_game *game);
void			draw_map(t_game *game);
void			draw_player(int size, int color, t_game *game);
void			paint_floor_ceil(t_game *game);

//utils
bool			touch_wall(double px, double py, t_game *game);
bool			is_inside_wall(double px, double py, t_game *game);
bool			is_inside_door(double px, double py, t_game *game);
void			set_ray_parameters(t_game *game, double *fraction,
					double *start_x);
void			calculate_ray_direction(double start_x, t_ray *ray);
double			degree_to_radians(double a);
double			get_fps(void);
void			free_textures(t_game *game, int max);
unsigned long	convert_rgb(int	*rgb);
void			free_config_paths(t_game *game);
void			ft_free_array(char **array);
bool			is_invalid_tile(char c);
bool			is_line_empty(char *trimmed);
int				check_xpm_header(char *path);
void			check_texture_paths(t_game *game);
bool			is_map_char(char c);
bool			line_has_map_characters(const char *line, int len);
bool			line_is_whitespace(const char *line, int len);
bool			is_config_or_empty(char *line, int len);

// map_validation
char			**parse_map_file(char *file_path);
void			init_map_config(t_map_config *config);
bool			is_texture_line(t_game *game, char *line, t_map_config *config);
bool			is_color_line(char *line, t_map_config *config);
bool			parse_config_line(t_game *game, char *line, t_map_config *config);
bool			validate_map(t_game *game);
bool			validate_space_enclosure(char **map);
bool			validate_map_content(t_game *game);
bool			validate_map_edges(char **map);
bool			parse_rgb_values(char *str, int rgb[3]);
bool			store_rgb_values(char *line, t_map_config *config);
bool			handle_config_complete(char *trimmed, t_map_config *config);
bool			handle_texture_and_color(t_game *game, char *trimmed, t_map_config *config);
bool			store_texture_path(t_game *game, char *line, t_map_config *config);
bool			is_config_line_start(const char *line);
bool			is_empty_content(const char *content);

#endif