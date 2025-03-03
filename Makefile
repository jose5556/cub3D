# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/01 12:50:37 by joseoliv          #+#    #+#              #
#    Updated: 2025/03/03 19:02:20 by joseoliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc -g

MINILIBX_DIR = libs/minilibx-linux
MINILIBX = $(MINILIBX_DIR)/libmlx.a

LIBFT_DIR = libs/libft
LIBFT = $(LIBFT_DIR)/libft.a

# CFLAGS = -Wextra -Wall -Werror  
LDFLAGS = $(LIBFT) $(MINILIBX) -lX11 -lXext -lm

SRCS = $(wildcard src/**/*.c src/*.c)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	@$(CC) -o $@ $(OBJS) $(LDFLAGS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR) -s

$(MINILIBX):
	@make -C $(MINILIBX_DIR) -s

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFT_DIR) -s

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR) -s

re: fclean all