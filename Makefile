# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 16:08:00 by ededemog          #+#    #+#              #
#    Updated: 2024/04/25 21:32:46 by ededemog         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	so_long

SRCDIR	:=	src/

OBJDIR	:=	obj/

INCDIR	:=	./inc/mlx/ ./inc/ft_printf/

SRC		:=	so_long.c

OBJ		:=	$(SRC:.c=.o)

SRC		:=	$(addprefix $(SRCDIR),$(SRC))
OBJ		:=	$(addprefix $(OBJDIR),$(OBJ))

PRINTF	:=	inc/ft_printf/libftprintf.a

RED		:=	"\e[1;91m"
GREEN	:=	"\e[1;92m"
RESET	:=	"\e[0m"

ifeq ($(shell uname), Linux)
	MLX		:=	inc/mlx/libmlx_Linux.a
	MLX_FLAGS := -L./inc/mlx -lmlx -L/usr/lib/X11 -lXext -lX11
else
	MLX		:=	inc/mlx/libmlx.a
	MLX_FLAGS := -L./inc/mlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

CC		:=	cc

CFLAGS	:=	-Werror -Wextra -Wall

all:	$(NAME)

$(OBJDIR)%.o:	$(SRCDIR)%.c | $(OBJDIR)
		@$(CC) $(CFLAGS) -I/usr/include -Imlx -O3 -c $< -o $@
		@echo $(GREEN)Compiling $< to $@$(RESET)

$(PRINTF):
			@make -sC inc/ft_printf/
			@echo $(GREEN)ft_printf compiled $(RESET)

$(MLX):
			make -sC inc/mlx/

$(OBJDIR):
			mkdir -p obj/

$(NAME):	$(OBJ) $(PRINTF) $(MLX)
			$(CC) $(OBJ) $(MLX_FLAGS) -L./inc/ft_printf/ -lftprintf -o $(NAME)

clean:
			rm -f $(OBJ)

fclean:
			make -s clean
			make -sC inc/ft_printf fclean
			rm -f $(MLX)
			rm -f $(NAME)

re:
			@make -s fclean
			@make -s all

.PHONY:	all clean fclean re