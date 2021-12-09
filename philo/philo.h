/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:32:57 by hlehmann          #+#    #+#             */
/*   Updated: 2021/12/09 17:53:46 by hlehmann         ###   ########.fr       */
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
	int				np;
	int				t2d;
	int				t2e;
	int				t2s;
	int				mls; //how many times to eat aka meals
	struct timeval	st; //starting time of the program
	pthread_t		*p; //array for the threads aka philosophers
	pthread_mutex_t	*f;
}	t_t;

typedef struct s_philo
{
	int	meals_eaten;
	int	last_meal_time;
	struct timeval	currenttime;
	t_t	*t;
	int		*id;
}	t_philo;

int		ft_atoi(const char *nptr);
long	ft_atol(char *s);
int		ft_check(int argc, char **argv);
size_t	ft_strlen(const char *str);
void	ft_init(int argc, char **argv, t_t *t);

#endif
