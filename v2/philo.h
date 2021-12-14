#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

struct timeval
{
	time_t		tv_sec;
	suseconds_t	tv_usec;
};

typedef struct	s_table
{
	int				nb_philo;
	int				t2d;
	int				t2e;
	int				t2s;
	int				nb_meals;
	long long		start_time;
	struct timeval	time;
}	t_table;
