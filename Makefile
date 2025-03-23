# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cereais <cereais@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/01 12:50:37 by joseoliv          #+#    #+#              #
#    Updated: 2025/03/23 06:28:34 by cereais          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc

MINILIBX_DIR	= libs/minilibx-linux
MINILIBX 	= $(MINILIBX_DIR)/libmlx.a

LIBFT_DIR	= libs/libft
LIBFT		= $(LIBFT_DIR)/libft.a

CFLAGS		= -Wextra -Wall -Werror  
LDFLAGS 	= $(LIBFT) $(MINILIBX) -lX11 -lXext -lm

OBJS_PATH	=	./objects/
SRCS_PATH	=	./src/

SRCS		=	main.c \
				events/hooks.c \
				exit/exit_error_message.c exit/hooks_exit.c \
				init/init.c \
				pixels_handler/minimap_painter.c pixels_handler/paint_image.c \
				player/player_movement.c player/player_position.c \
				render/render_cub3d.c render/render_map.c render/render_raycaster.c \
				utils/fps_utils.c utils/move_player_utils.c utils/raycaster_utils.c \
				
SRCS_FILES		= 	$(addprefix $(SRCS_PATH), $(SRCS))
OBJS			= 	$(addprefix $(OBJS_PATH), $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	@$(CC) -o $@ $(OBJS) $(LDFLAGS)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR) -s

$(MINILIBX):
	@make -C $(MINILIBX_DIR) -s

clean:
	@rm -rf $(OBJS_PATH)
	@make clean -C $(LIBFT_DIR) -s

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR) -s

re: fclean all