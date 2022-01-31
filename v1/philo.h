#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_table
{
	int				nb_philo;
	int				ttd;
	int				tte;
	int				tts;
	int				nb_meals;
	int				dead;
	int				full;
	long long		start_time;
	pthread_mutex_t	check_meal;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	t_philo			philo;
}	t_table;

typedef struct	s_philo
{
	int	fork_one;
	int	fork_two;
	int	id;
	int	nb_food;
	long long	last_meal;
	struct s_table	table;
}	t_philo;

#endif
