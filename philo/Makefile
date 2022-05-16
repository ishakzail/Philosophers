# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: izail <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/16 07:41:26 by izail             #+#    #+#              #
#    Updated: 2022/05/16 07:41:28 by izail            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

HEADER = philo.h

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC =	philo.c utils.c init.c \
	
OBJ = $(SRC:%.c=%.o)

OBJ_B = $(SRC_B:%.c=%.o)

all: $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

bonus : $(NAME_BONUS)

clean:
	@rm -f *.o 

fclean: clean
	@rm -f philo

re: fclean all