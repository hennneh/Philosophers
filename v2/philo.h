#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct	s_table
{
	int				nb_philo;
	int				t2d;
	int				t2e;
	int				t2s;
	int				nb_meals;
	long long		start_time;
	struct timeval	time;
	pthread_mutex_t	*forks;
}	t_table;

int	ft_init(int argc, char **argv, t_table *table);
int	ft_atoi(const char *nptr);
long	ft_atol(char *s);
size_t	ft_strlen(const char *str);

#endif
