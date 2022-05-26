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

SRC =	philo.c utils.c utils2.c init.c action.c check.c routine.c\
	
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -f *.o 

fclean: clean
	@rm -f philo

re: fclean all