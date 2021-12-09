/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:32:57 by hlehmann          #+#    #+#             */
/*   Updated: 2021/12/09 15:57:44 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>		//remove after testing aöksdjföaskjdföajksdöfjkasöldkjfalöskdjflöaskdjfölaskdjf

typedef struct s_t
{
	int				nphil;
	int				t2d;
	int				t2e;
	int				t2s;
	int				nmeal; //how many times to eat aka meals
	struct timeval	stime; //starting time of the program
	pthread_t		*parr; //array for the threads aka philosophers
	pthread_mutex_t	*frk;
}	t_t;

typedef struct s_philo
{
	int	meals_eaten;
	int	last_meal_time;
	struct timeval	currenttime;
	t_t	*t;
}	t_philo;

int		ft_atoi(const char *nptr);
long	ft_atol(char *s);
int		ft_check(int argc, char **argv);
size_t	ft_strlen(const char *str);

#endif
