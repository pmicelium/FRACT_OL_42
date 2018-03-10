# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/28 17:43:26 by pmiceli           #+#    #+#              #
#    Updated: 2018/03/10 02:44:28 by pmiceli          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCDIR = ./srcs/
SRCNAMES = main.c loop_hook.c destroy_fract.c fps/fps.c event/key_fonct.c\
		   event/mouse_fonct.c event/motion_notify.c draw/draw_map.c\
		   draw/choice/display_choice.c draw/choice/motion_choice.c\
		   draw/choice/mouse_choice.c draw/mandelbrot/draw_mandelbrot.c\
		   draw/mandelbrot/key_mandel.c draw/mandelbrot/mouse_mandel.c\
		   draw/julia/draw_julia.c draw/julia/mouse_julia.c\
		   draw/julia/motion_julia.c draw/julia/key_julia.c\
		   draw/ship/draw_ship.c draw/ship/mouse_ship.c\
		   draw/ship/key_ship.c\
		   draw/hugulus/draw_hugulus.c draw/hugulus/mouse_hugulus.c\
		   draw/hugulus/key_hugulus.c\

SRC = $(addprefix $(SRCDIR), $(SRCNAMES))
INC = ./includes/
INCS = ./includes/fract.h ./srcs/draw/mandelbrot/mandelbrot.h\
	   ./srcs/draw/choice/choice.h ./srcs/event/event.h ./srcs/fps/fps.h\
	   ./srcs/draw/julia/julia.h ./srcs/draw/ship/ship.h\
	   ./srcs/draw/hugulus/hugulus.h\

OBJS_DIR = ./objs/
OBJS = $(addprefix $(OBJS_DIR), $(SRCNAMES:.c=.o))

LIB_INCS = ./lib/libft/includes/get_next_line.h ./lib/libft/includes/libft.h\
		   ./lib/minilibx_macos/mlx.h ./lib/mlx_perso/includes/mlx_define.h\
		   ./lib/mlx_perso/includes/mlx_perso.h

LIBFT_DIR = ./lib/libft/
LIBFT = ./lib/libft/libft.a
MLX_DIR = ./lib/minilibx_macos/
MLX = ./lib/minilibx_macos/libmlx.a
MLX_PERSO_DIR = ./lib/mlx_perso/
MLX_PERSO = ./lib/mlx_perso/mlx_perso.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address
MLX_FLAGS = -framework OpenGL -framework AppKit

PRINT = "make[1]: Nothing to be done for 'all'"

all: $(OBJS_DIR) print_lib LIBFT print_mlx MLX print_mlx_perso MLX_PERSO print_name $(NAME) print_done

print_name:
	@echo "\033[033m➼	\033[033mCompiling $(NAME) ...\033[0m"
	@echo "\033[033m➼	\033[033mCreating $(NAME)'s objetcs\033[0m"

print_lib:
	@echo "\033[033m➼	\033[033mCompiling Libft ...\033[0m"
	@echo "\033[033m➼	\033[033mCreating Libft's objetcs\033[0m"

print_mlx:
	@echo "\033[033m➼	\033[033mCompiling MLX ...\033[0m"
	@echo "\033[033m➼	\033[033mCreating MLX's objetcs\033[0m"

print_mlx_perso:
	@echo "\033[033m➼	\033[033mCompiling MLX_PERSO ...\033[0m"
	@echo "\033[033m➼	\033[033mCreating MLX_PERSO's objetcs\033[0m"

print_done:
	@echo $(PRINT)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o:$(SRCDIR)%.c $(INCS) $(LIB_INCS)
	@echo "\033[038;2;255;153;0m⧖	Creating 	$@\033[0m"
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(INC) -o $@ -c $<

$(NAME): $(OBJS) $(LIBFT) $(MLX) $(MLX_PERSO)
	@echo "\033[033m➼	\033[033mCreating $(NAME)'s executable\033[0m"
	@$(CC) $(CFLAGS) $(MLX_FLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX) $(MLX_PERSO)
	$(eval PRINT ="\033[032m✓	\033[032mDONE !\033[0m")

LIBFT:
	@make -C $(LIBFT_DIR)

MLX:
	@make -C $(MLX_DIR)

MLX_PERSO:
	@make -C $(MLX_PERSO_DIR)

clean:
	@rm -rf $(OBJS_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@make -C $(MLX_PERSO_DIR) clean
	@echo "❌	\033[031mRemouve $(NAME)'s objects\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(MLX_PERSO_DIR) fclean
	@echo "❌	\033[031mRemouve $(NAME)'s executable\033[0m"

re: fclean all

ret : clean test

.PHONY: all fclean clean re MLX LIBFT print_name print_mlx print_done\
	print_lib MLX_PERSO print_mlx_perso
