# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/14 02:47:46 by pmiceli           #+#    #+#              #
#    Updated: 2018/01/29 21:44:36 by pmiceli          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCDIR = ./srcs/
SRCNAMES = main.c loop_hook.c destroy_fract.c fps/fps.c event/key_fonct.c\
		   event/mouse_fonct.c event/motion_notify.c draw/draw_map.c\
		   draw/choice/display_choice.c draw/choice/motion_choice.c\
		   draw/choice/mouse_choice.c draw/mandelbrot/draw_mandelbrot.c\
		   draw/check_draw.c draw/mandelbrot/key_mandel.c\
		   draw/mandelbrot/mouse_mandel.c

SRC = $(addprefix $(SRCDIR), $(SRCNAMES))
INC = ./includes/
INCS = ./includes/mlx_win.h ./includes/mlx_win.h ./srcs/draw/mandelbrot/mandelbrot.h\
	   ./srcs/draw/choice/choice.h ./srcs/event/event.h ./srcs/fps/fps.h

OBJS_DIR = ./objs/
OBJS = $(addprefix $(OBJS_DIR), $(SRCNAMES:.c=.o))

LIBFT_DIR = ./libft/
LIBFT = ./libft/libft.a
MLX_DIR = ./minilibx_macos/
MLX = ./minilibx_macos/libmlx.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
MLX_FLAGS = -framework OpenGL -framework AppKit

PRINT = "make[1]: Nothing to be done for 'all'"

all: $(OBJS_DIR) print_lib LIBFT print_mlx MLX print_fdf $(NAME) print_done

print_fdf :
	@echo "\033[033m➼	\033[033mCompiling $(NAME) ...\033[0m"
	@echo "\033[033m➼	\033[033mCreating $(NAME)'s objetcs\033[0m"

print_lib :
	@echo "\033[033m➼	\033[033mCompiling Libft ...\033[0m"
	@echo "\033[033m➼	\033[033mCreating Libft's objetcs\033[0m"

print_mlx :
	@echo "\033[033m➼	\033[033mCompiling MLX ...\033[0m"
	@echo "\033[033m➼	\033[033mCreating MLX's objetcs\033[0m"

print_done :
	@echo $(PRINT)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o:$(SRCDIR)%.c $(INCS)
	@echo "\033[038;2;255;153;0m⧖	Creating 	$@\033[0m"
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(INC) -o $@ -c $<

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@echo "\033[033m➼	\033[033mCreating $(NAME)'s executable\033[0m"
	@$(CC) $(CFLAGS) $(MLX_FLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX)
	$(eval PRINT ="\033[032m✓	\033[032mDONE !\033[0m")

LIBFT:
	@make -C $(LIBFT_DIR)

MLX:
	@make -C $(MLX_DIR)

clean:
	@rm -rf $(OBJS_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@echo "❌	\033[031mRemouve $(NAME)'s objects\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "❌	\033[031mRemouve $(NAME)'s executable\033[0m"

re: fclean all

ret : clean test

.PHONY: all fclean clean re MLX LIBFT print_fdf print_mlx print_done\
	print_lib
