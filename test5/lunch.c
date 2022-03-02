/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffet.c                      	                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 09:02:36 by hlehmann          #+#    #+#             */
/*   Updated: 2022/02/09 09:02:38 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*static void	action(t_philo *philo, int id)
{
	pthread_mutex_lock(&philo->table->status);
	if (philo->table->end_of_buffet == 1)
	{
		pthread_mutex_unlock(&philo->table->status);
		return ;
	}
	if (id == PH_FORK)
		print_message(philo, "has taken a fork");
	else if (id == PH_EAT)
	{
		print_message(philo, "is eating");
		philo->time_of_last_plate = ft_get_time();
	}
	else if (id == PH_SLEEP)
	{
		print_message(philo, "is sleeping");
		philo->plate_count++;
	}
	else if (id == PH_THINK)
		print_message(philo, "is thinking");
	pthread_mutex_unlock(&philo->table->status);
}*/

static void	*routine(void *philo_ptr)
{
	t_philo	*philo;

	philo = philo_ptr;
	if (philo->seat % 2 == 0)
		ft_usleep(philo->table, philo->table->tte * 1000);
	while (!philo->table->end_of_buffet)
	{
		pthread_mutex_lock(philo->left_fork);
		//action(philo, PH_FORK);
		ft_fork(philo);
		if (philo->left_fork == philo->right_fork)
			break ;
		pthread_mutex_lock(philo->right_fork);
		//action(philo, PH_FORK);
		ft_fork(philo);
		//action(philo, PH_EAT);
		ft_eat(philo);
		ft_usleep(philo->table, philo->table->tte * 1000);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		//action(philo, PH_SLEEP);
		ft_sleep(philo);
		ft_usleep(philo->table, philo->table->tts * 1000);
		//action(philo, PH_THINK);
		ft_think(philo);
	}
	if (philo->left_fork == philo->right_fork)
		pthread_mutex_unlock(philo->right_fork);
	return (NULL);
}

int	lunch(t_table *table)
{
	int		a;
	t_philo	*philo;

	a = 0;
	table->time_at_start = ft_get_time();
	init_philo(table);
	while (a < table->nb_philo)
	{
		philo = &table->philo[a];
		if (pthread_create(&philo->thread_id, NULL, routine, philo))
		{
			pthread_mutex_lock(&table->status);
			table->end_of_buffet = 1;
			pthread_mutex_unlock(&table->status);
			return (1);
		}
		a++;
	}
	waiter(table);
	return (0);
}
