# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/22 22:01:29 by caonguye          #+#    #+#              #
#    Updated: 2024/09/23 00:32:16 by caonguye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC  = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c

OBJ  = $(SRC:.c = .o)

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

AR = ar -rc

RM = rm -rf

LIB = ranlib

all: $(NAME)

clean:
	rm -f$(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re


