# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 15:53:33 by ededemog          #+#    #+#              #
#    Updated: 2023/12/16 20:10:10 by ededemog         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
EXEC = prog
SRCS = ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
		ft_isprint.c ft_strchr.c ft_strrchr.c ft_strlen.c ft_tolower.c \
		ft_toupper.c ft_strdup.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_strlcpy.c ft_bzero.c ft_memset.c ft_memcpy.c \
		ft_putnbr_fd.c ft_memmove.c ft_strnstr.c ft_strlcat.c ft_calloc.c \
		ft_strncmp.c ft_strmapi.c ft_memchr.c ft_memcmp.c ft_substr.c \
		ft_striteri.c ft_itoa.c ft_strjoin.c ft_split.c ft_strtrim.c

BONUS	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c

MAIN	=	main.c

OBJB	=	$(BONUS:.c=.o)

OBJM	=	$(MAIN:.c=.o)

TNAME	= 	test

OBJS 	= 	$(SRCS:.c=.o)

NAME	= 	libft.a

CC		= 	clang
CFLAGS	= 	-Wall -Wextra -Werror

AR		= 	ar rc

RM		= 	rm -f

.c.o:
			$(CC) $(CFLAGS) -o $(<:.c=.o) -c $<

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

test:		$(NAME) bonus
			$(CC) $(CFLAGS) -o $(TNAME) $(MAIN) -L. -lft

ifneq ($(shell uname), Darwin)
breaker:
			$(CC) -nostartfiles -shared -fPIC -ldl $(CFLAGS) -o libft.so $(SRCS) $(BONUS)
else
breaker:
			$(CC) -dynamiclib $(CFLAGS) -o libft.so $(SRCS) $(BONUS) -L../obj -lmalloc
endif

all:		$(NAME)

bonus:		$(OBJB)
			$(AR) $(NAME) $(OBJB)

clean:
			$(RM) $(OBJS) $(OBJM) $(OBJB)

fclean:		clean
			$(RM) $(NAME) $(TNAME)

re:			fclean all

.PHONY:		all clean fclean re test