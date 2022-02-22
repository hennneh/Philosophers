# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 09:02:28 by hlehmann          #+#    #+#              #
#    Updated: 2022/02/22 14:10:40 by hlehmann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = main.c	utils.c	init_and_finish.c	buffet.c
OBJS = $(SRCS:.c=.o)
HEAD = philosophers.h

CC = gcc
CF = -Wall -Wextra -Werror
CI = -I
CS = -g -fsanitize=address
CG = -g3

RM = rm -rf

all: ${NAME}

$(NAME): $(OBJS) $(HEAD) Makefile
	$(CC) $(CF) $(OBJS) -o $(NAME)

%.o: %.c $(HEAD) Makefile
	$(CC) -c $(CF) $< -o $@


clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
