# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 09:02:28 by hlehmann          #+#    #+#              #
#    Updated: 2022/02/09 09:08:20 by hlehmann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = philosophers.c	ph_utils.c	ph_init_and_finish.c	ph_buffet.c
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
