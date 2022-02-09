# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 09:02:28 by hlehmann          #+#    #+#              #
#    Updated: 2022/02/09 09:02:29 by hlehmann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = philo

#//////////////////////////////////////////////////////////////////////////////
#		ALL FILES
#//////////////////////////////////////////////////////////////////////////////

SRCS = philosophers.c	ph_utils.c	ph_init_and_finish.c	ph_buffet.c
OBJS = $(SRCS:.c=.o)
HEAD = philosophers.h

#//////////////////////////////////////////////////////////////////////////////
#		COMMAND SHORTCUTS
#//////////////////////////////////////////////////////////////////////////////

CC = gcc
CF = -Wall -Wextra -Werror
CI = -I
CS = -g -fsanitize=address
CG = -g3

RM = rm -rf

#//////////////////////////////////////////////////////////////////////////////
#		RULES
#//////////////////////////////////////////////////////////////////////////////

all: ${NAME}

# Binary creation rules

$(NAME): $(OBJS) $(HEAD) Makefile
	$(CC) $(CF) $(OBJS) -o $(NAME)

%.o: %.c $(HEAD) Makefile
	$(CC) -c $(CF) $< -o $@


# Mandatory Rules

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
