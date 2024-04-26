# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 16:08:00 by ededemog          #+#    #+#              #
#    Updated: 2024/04/26 13:14:04 by ededemog         ###   ########.fr        #
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
	INCLUDES = -I ./inc/mlx
	MLX		:=	inc/mlx/libmlx_Linux.a
	MLX_FLAGS := -L./inc/mlx -lmlx -L/usr/lib/X11 -lXext -lX11
else
	INCLUDES = -I ./inc/mlx-mac
	MLX		:=	inc/mlx-mac/libmlx.a
	MLX_FLAGS := -L./inc/mlx-mac -lmlx -framework OpenGL -framework AppKit
endif

CC		:=	cc

CFLAGS	:=	-Werror -Wextra -Wall

all:	$(NAME)

$(OBJDIR)%.o:	$(SRCDIR)%.c | $(OBJDIR)
		@$(CC) $(CFLAGS) $(INCLUDES) -Imlx -O3 -c $< -o $@
		@echo $(GREEN)Compiling $< to $@$(RESET)

$(PRINTF):
			@make -sC inc/ft_printf/
			@echo $(GREEN)ft_printf compiled $(RESET)

$(MLX):
			@make -sC inc/mlx/

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