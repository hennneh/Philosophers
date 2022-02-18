#include "philo.h"

void	naptime(t_philo *philo, int sleep)
{
	long long		start;
	struct timeval	time;

	gettimeofday(&time, NULL);
	start = (time.tv_sec * 1000 + time.tv_usec / 1000);
	while (get_start_time() - start < (long long)sleep)
	{
		if (philo->table->nb_philo < 100)
			usleep(100);
		else
			usleep(1000);
	}
}

void	fork_action(t_philo *philo)
{
	long long	ct;

	pthread_mutex_lock(&philo->table->status);
	if (philo->table->full == 1)
	{
		pthread_mutex_unlock(&philo->table->status);
		return ;
	}
	ct = get_start_time() - philo->table->start_time;
	printf("%lld %d has taken a fork\n", ct, philo->number);
	pthread_mutex_unlock(&philo->table->status);
}

void	food_action(t_philo *philo)
{
	long long	ct;

	pthread_mutex_lock(&philo->table->status);
	if (philo->table->full == 1)
	{
		pthread_mutex_unlock(&philo->table->status);
		return ;
	}
	ct = get_start_time() - philo->table->start_time;
	printf("%lld %d is eating\n", ct, philo->number);
	philo->last_meal = get_start_time();
	pthread_mutex_unlock(&philo->table->status);
}

void	bed_action(t_philo *philo)
{
	long long	ct;

	pthread_mutex_lock(&philo->table->status);
	if (philo->table->full == 1)
	{
		pthread_mutex_unlock(&philo->table->status);
		return ;
	}
	ct = get_start_time() - philo->table->start_time;
	printf("%lld %d is sleeping\n", ct, philo->number);
	philo->nb_meals++;
	pthread_mutex_unlock(&philo->table->status);
}

void	thought_action(t_philo *philo)
{
	long long	ct;

	pthread_mutex_lock(&philo->table->status);
	if (philo->table->full == 1)
	{
		pthread_mutex_unlock(&philo->table->status);
		return ;
	}
	ct = get_start_time() - philo->table->start_time;
	printf("%lld %d is thinking\n", ct, philo->number);
	pthread_mutex_unlock(&philo->table->status);
}
