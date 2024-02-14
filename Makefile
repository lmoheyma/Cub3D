# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 11:45:38 by aleite-b          #+#    #+#              #
#    Updated: 2024/02/12 16:25:51 by aleite-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Wextra -Werror -g3 -O3

INCLUDE = -I inc/

RM = rm -f

MLX = -lXext -lX11

LIB = libft/libft.a mlx/libmlx_Linux.a -lm

SOURCES = src/main.c \
			src/map/assets.c \
			src/map/assets2.c \
			src/map/file.c \
			src/map/err.c \
			src/map/get_width_and_height.c \
			src/map/map.c \
			src/map/map2.c \
			src/map/map3.c \
			src/map/utils.c \
			src/map/init_game.c \
			src/exec/init.c \
			src/exec/raycasting.c \
			src/exec/texture.c \
			src/exec/move.c \
			src/exec/rotate.c \
			src/exec/color_utils.c \
			src/exec/utils.c \
			src/exec/directions.c \
			src/exec/xpm.c \
			src/exec/play_game.c \
			src/minimap/minimap.c \
			
OBJS_BASE = $(SOURCES:.c=.o)

OBJS = $(addprefix obj/,$(OBJS_BASE))

NAME = cub3d

all: obj $(NAME)

obj:
	mkdir -p obj
	mkdir -p obj/src
	mkdir -p obj/src/exec
	mkdir -p obj/src/map
	mkdir -p obj/src/minimap

$(NAME): $(OBJS) 
	@echo "\n"
	make -C libft/
	make -C mlx/
	@echo "\033[0;32mCompiling cub3D..."
	$(CC) $(FLAGS) $(INCLUDE) $(MLX) -o $(NAME) $(OBJS) $(LIB)
	@echo "\n\033[0mDone !"

obj/%.o: %.c
	@printf "\033[0;33mGenerating cub3D objects... %-33.33s\r" $@
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	@echo "\033[0;31m"
#	@make clean -C libft/
	@echo "\nRemoving binaries..."
	rm -f $(OBJS)
	@echo "\033[0m"

fclean: clean
	@echo "\033[0;31m\nDeleting executable..."
	rm -f $(NAME)
	@echo "\033[0m"

re: fclean $(NAME)

.PHONY: all clean fclean re
