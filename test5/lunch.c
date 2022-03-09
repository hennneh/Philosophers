/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 09:02:36 by hlehmann          #+#    #+#             */
/*   Updated: 2022/03/09 10:49:42 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	*routine(void *philo_ptr)
{
	t_philo	*philo;

	philo = philo_ptr;
	if (philo->seat % 2 == 0)
		ft_usleep(philo->table, philo->table->tte * 1000);
	while (!philo->table->end_of_buffet)
	{
		pthread_mutex_lock(philo->left_fork);
		ft_fork(philo);
		if (philo->left_fork == philo->right_fork)
			break ;
		pthread_mutex_lock(philo->right_fork);
		ft_fork(philo);
		ft_eat(philo);
		ft_usleep(philo->table, philo->table->tte * 1000);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		ft_sleep(philo);
		ft_usleep(philo->table, philo->table->tts * 1000);
		ft_think(philo);
	}
	if (philo->left_fork == philo->right_fork)
		pthread_mutex_unlock(philo->right_fork);
	return (NULL);
}

int	lunch(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = 0;
	table->time_at_start = ft_get_time();
	init_philo(table);
	while (i < table->nb_philo)
	{
		philo = &table->philo[i];
		if (pthread_create(&philo->thread_id, NULL, routine, philo))
		{
			pthread_mutex_lock(&table->status);
			table->end_of_buffet = 1;
			pthread_mutex_unlock(&table->status);
			return (1);
		}
		i++;
	}
	waiter(table);
	return (0);
}
