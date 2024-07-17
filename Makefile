# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 16:08:00 by ededemog          #+#    #+#              #
#    Updated: 2024/07/17 16:51:58 by ededemog         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

SRCDIR := src/
GNLDIR := inc/get_next_line
OBJDIR := obj/
INCDIR := ./inc/mlx/ ./inc/ft_printf/
LIBFT_PATH := ./inc/libft 

SRC := so_long.c free_utils.c input_verif.c keys.c map_display.c map_verif.c \
		moves.c parser.c ../inc/get_next_line/get_next_line.c \
		../inc/get_next_line/get_next_line_utils.c
GNL := get_next_line.c get_next_line_utils.c
OBJ := $(SRC:.c=.o)

SRC := $(addprefix $(SRCDIR),$(SRC))
GNL := $(addprefix $(GNLDIR),$(GNL))
OBJ := $(addprefix $(OBJDIR),$(OBJ))

PRINTF := inc/ft_printf/libftprintf.a
LIBFT := $(LIBFT_PATH)/libft.a 

RED := "\e[1;91m"
GREEN := "\e[1;92m"
RESET := "\e[0m"

ifeq ($(shell uname), Linux)
	INCLUDES = -I ./inc/mlx
	MLX := inc/mlx/libmlx_Linux.a
	MLX_FLAGS := -L./inc/mlx -lmlx -L/usr/lib/X11 -lXext -lX11
else
	INCLUDES = -I ./inc/mlx-mac
	MLX := inc/mlx-mac/libmlx.a
	MLX_FLAGS := -L./inc/mlx-mac -lmlx -framework OpenGL -framework AppKit
endif

CC := gcc

CFLAGS := -Werror -Wextra -Wall -g

all: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -Imlx -O3 -c $< -o $@
	@echo $(GREEN)Compiling $< to $@$(RESET)

$(PRINTF):
	@make -sC inc/ft_printf/
	@echo $(GREEN)ft_printf compiled $(RESET)

$(MLX):
	@make -sC inc/mlx/

$(LIBFT): # Rule to build libft.a
	@make -sC $(LIBFT_PATH)

$(OBJDIR):
	mkdir -p obj

$(NAME): $(OBJ) $(PRINTF) $(MLX) $(LIBFT)
	$(CC) $(OBJ) $(MLX_FLAGS) -L./inc/ft_printf/ -lftprintf -L$(LIBFT_PATH) -lft -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:
	make -s clean
	make -sC inc/ft_printf fclean
	rm -f $(MLX)
	rm -f $(NAME)
	make -sC $(LIBFT_PATH) clean # Clean libft

re:
	@make -s fclean
	@make -s all

.PHONY: all clean fclean re
