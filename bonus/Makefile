# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 11:18:02 by hlehmann          #+#    #+#              #
#    Updated: 2022/03/02 11:18:04 by hlehmann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

INC 	= includes/philo_bonus.h

SRC		=	src/philo_bonus.c\
			src/actions.c\
			src/init.c\
			src/time_libc.c\

CC 		= gcc

FLAGS	= -Wall -Wextra -Werror -pthread

OBJS 	= $(SRC:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

all: $(NAME) $(OBJS) $(INC)

%.o: %.c $(INC)
		$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
