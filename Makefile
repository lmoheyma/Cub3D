# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 11:45:38 by aleite-b          #+#    #+#              #
#    Updated: 2024/02/18 23:10:24 by lmoheyma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Wextra -Werror -g3 -O3

INCLUDE = -I inc/

RM = rm -f

MLX = -lXext -lX11

LIB = libft/libft.a mlx/libmlx_Linux.a -lm

SOURCES = mandatory/src/main.c \
			mandatory/src/map/assets.c \
			mandatory/src/map/assets2.c \
			mandatory/src/map/file.c \
			mandatory/src/map/err.c \
			mandatory/src/map/get_width_and_height.c \
			mandatory/src/map/map.c \
			mandatory/src/map/map2.c \
			mandatory/src/map/map3.c \
			mandatory/src/map/utils.c \
			mandatory/src/map/init_game.c \
			mandatory/src/exec/init.c \
			mandatory/src/exec/raycasting.c \
			mandatory/src/exec/texture.c \
			mandatory/src/exec/move_manager.c \
			mandatory/src/exec/move.c \
			mandatory/src/exec/rotate.c \
			mandatory/src/exec/color_utils.c \
			mandatory/src/exec/utils.c \
			mandatory/src/exec/utils2.c \
			mandatory/src/exec/play_game.c \

BSOURCES = bonus/src/main.c \
			bonus/src/map/assets.c \
			bonus/src/map/assets2.c \
			bonus/src/map/file.c \
			bonus/src/map/err.c \
			bonus/src/map/get_width_and_height.c \
			bonus/src/map/map.c \
			bonus/src/map/map2.c \
			bonus/src/map/map3.c \
			bonus/src/map/utils.c \
			bonus/src/map/init_game.c \
			bonus/src/exec/init.c \
			bonus/src/exec/raycasting.c \
			bonus/src/exec/texture.c \
			bonus/src/exec/move_manager.c \
			bonus/src/exec/door.c \
			bonus/src/exec/move.c \
			bonus/src/exec/rotate.c \
			bonus/src/exec/color_utils.c \
			bonus/src/exec/utils.c \
			bonus/src/exec/utils2.c \
			bonus/src/exec/utils3.c \
			bonus/src/exec/play_game.c \
			bonus/src/minimap/minimap.c \
			bonus/src/exec/sprite.c \
			bonus/src/exec/floor_ceiling.c \
			bonus/src/exec/animation_sprite.c \
			bonus/src/exec/add_sprites.c
			
OBJS_BASE = $(SOURCES:.c=.o)
BOBJS_BASE = $(BSOURCES:.c=.o)

OBJS = $(addprefix obj/,$(OBJS_BASE))
BOBJS = $(addprefix obj/,$(BOBJS_BASE))

NAME = cub3d

all: obj $(NAME)

obj:
	mkdir -p obj
	mkdir -p obj/mandatory/src
	mkdir -p obj/mandatory/src/map
	mkdir -p obj/mandatory/src/exec
	mkdir -p obj/mandatory/src/minimap
bobj:
	mkdir -p obj
	mkdir -p obj/bonus/src
	mkdir -p obj/bonus/src/exec
	mkdir -p obj/bonus/src/map
	mkdir -p obj/bonus/src/minimap

$(NAME): $(OBJS) 
	@echo "\n"
	make -C libft/
	make -C mlx/
	@echo "\033[0;32mCompiling cub3D..."
	$(CC) $(FLAGS) $(INCLUDE) $(MLX) -o $(NAME) $(OBJS) $(LIB)
	@echo "\n\033[0mDone !"

bonus: bobj $(BOBJS) 
	@echo "\n"
	make -C libft/
	make -C mlx/
	@echo "\033[0;32mCompiling cub3D..."
	$(CC) $(FLAGS) $(INCLUDE) $(MLX) -o $(NAME) $(BOBJS) $(LIB)
	@echo "\n\033[0mDone !"

obj/%.o: %.c
	@printf "\033[0;33mGenerating cub3D objects... %-33.33s\r" $@
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	@echo "\033[0;31m"
#	@make clean -C libft/
	@echo "\nRemoving binaries..."
	rm -f $(OBJS)
	rm -f $(BOBJS)
	@echo "\033[0m"

fclean: clean
	@echo "\033[0;31m\nDeleting executable..."
	rm -f $(NAME)
	@echo "\033[0m"

re: fclean $(NAME)

.PHONY: all clean fclean re
