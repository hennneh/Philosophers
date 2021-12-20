#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct	s_table
{
	int				nb_philo;
	int				t2d;
	int				t2e;
	int				t2s;
	int				nb_meals;
	int				full;
	int				dead;
	long long		start_time;
	pthread_mutex_t	*forks;
}	t_table;

typedef struct s_philo
{
	t_table		*table;
	int			id;
	int			meals;
	long long	last_meal;
	long long	current_time;
}	t_philo;

int	ft_init(int argc, char **argv, t_table *table);
int	ft_atoi(const char *nptr);
long	ft_atol(char *s);
size_t	ft_strlen(const char *str);
void	*routine(void *philo);
long long	ft_time(void);

#endif
