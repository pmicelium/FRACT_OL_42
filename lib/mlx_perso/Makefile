NAME = mlx_perso.a

SRCS_DIR = ./srcs/
SRCS_NAME = $(shell ls $(SRCS_DIR) | grep -E ".c")
SRCS = $(addprefix $(SRCDIR), $(SRCS_NAME))
INC = ./includes/
INCS = ./includes/mlx_perso.h ./includes/mlx_define.h
OBJS_DIR = ./objs/
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(OBJS_DIR) $(NAME)

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)
#	@echo "\033[033m➼	\033[033mCreating mlx_win's objects\033m"

$(OBJS_DIR)%.o:$(SRCS_DIR)%.c $(INCS)
	@echo "\033[038;2;255;153;0m⧖	Creating	$@\033[0m"
	@$(CC) $(CFLAGS) -I$(INC) -o $@ -c $<

$(NAME) : $(OBJS)
	@echo "\033[032m✓	\033[0m\033[032mmlx_perso's objects created\033[0m"
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\033[032m✓	\033[0m\033[032mmlx_perso created\033[0m"

clean :
	@rm -rf $(OBJS_DIR)
	@echo "\033[36m❌	\033[0m\033[31mmlx_perso's objets removed\033[0m"

fclean : clean
	@rm -rf $(NAME)
	@echo "\033[036m❌	\033[0m\033[31mmlx_perso removed"

re : fclean all

.PHONY : all clean fclean re
