# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cereais <cereais@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/01 12:50:37 by joseoliv          #+#    #+#              #
#    Updated: 2025/04/16 14:54:16 by cereais          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc
BONUS = 0

MINILIBX_DIR = libs/minilibx-linux
MINILIBX = $(MINILIBX_DIR)/libmlx.a

LIBFT_DIR = libs/libft
LIBFT = $(LIBFT_DIR)/libft.a

CFLAGS = -Wall -Wextra -Werror
LDFLAGS = $(LIBFT) $(MINILIBX) -lX11 -lXext -lm

OBJS_PATH = ./objects/
SRCS_PATH = ./src/

SRCS =	main.c \
		events/hooks.c \
		exit/exit_error_message.c exit/hooks_exit.c \
		init/init.c \
		pixels_handler/minimap_painter.c pixels_handler/paint_image.c \
		pixels_handler/texture_painter.c \
		player/player_movement.c player/player_position.c \
		render/render_cub3d.c render/render_raycaster.c \
		utils/fps_utils.c utils/move_player_utils.c utils/raycaster_utils.c \
		utils/free_utils.c utils/rgb_utils.c utils/validation_utils.c \
		utils/init_utils.c utils/validation_utils2.c \
		map_validation/validate_border.c map_validation/validate_map2.c \
		map_validation/parse_map.c map_validation/validate_map.c \
		map_validation/parse_config.c map_validation/validate_config.c \
		map_validation/validate_enclosure.c map_validation/parse_rgb.c

SRCS_FILES = $(addprefix $(SRCS_PATH), $(SRCS))
OBJS = $(addprefix $(OBJS_PATH), $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) | $(MINILIBX)
	@$(CC) $(CFLAGS) -DBONUS=$(BONUS) $(OBJS) $(LDFLAGS) -o $@

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c | $(MINILIBX)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -DBONUS=$(BONUS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MINILIBX):
	@if [ ! -d "$(MINILIBX_DIR)" ]; then \
		echo "MiniLibX not found, cloning..."; \
		git clone https://github.com/42Paris/minilibx-linux.git $(MINILIBX_DIR); \
	fi
	@make -C $(MINILIBX_DIR) || true
	@test -f $(MINILIBX) || (echo "MiniLibX build failed!" && exit 1)


bonus:
	make all BONUS=1

clean:
	@rm -rf $(OBJS_PATH)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MINILIBX_DIR) clean >/dev/null 2>&1 || true

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
