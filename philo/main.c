/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 08:28:08 by hlehmann          #+#    #+#             */
/*   Updated: 2022/02/18 16:12:22 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philo_ptr)
{
	t_philo	*philo;

	philo = philo_ptr;
	if (philo->number % 2 == 0)
		naptime(philo, philo->table->tte);
	while (!philo->table->full)
	{
		pthread_mutex_lock(&philo->fork_one);
		fork_action(philo);
		pthread_mutex_lock(&philo->fork_two);
		fork_action(philo);
		food_action(philo);
		naptime(philo, philo->table->tte);
		pthread_mutex_unlock(&philo->fork_one);
		pthread_mutex_unlock(&philo->fork_two);
		bed_action(philo);
		naptime(philo, philo->table->tts);
		thought_action(philo);
	}
	printf("test %d\n", philo->number);
	return (NULL);
}

void	init_philo(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = 0; while (i < table->nb_philo)
	{
		philo = &table->philo[i];
		philo->table = table;
		philo->number = i + 1;
		philo->last_meal = table->start_time;
		philo->alive = 1;
		philo->nb_meals = 0;
		philo->fork_one = table->forks[i];
		i++;
		philo->fork_two = table->forks[i % table->nb_philo];
	}
}

void	wait_until_full(t_table *table)
{
	/*Üusleep(10000000);
	printf("waiting in main\n");
	printf("start time is: %lld\n", table->start_time);*/
	while (1)
	{
		pthread_mutex_lock(&table->status);
		if (check_status(table))
		{
			table->full = 1;
			pthread_mutex_unlock(&table->status);
			break ;
		}
		pthread_mutex_unlock(&table->status);
	}
}

int	start_threads(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = 0;
	init_philo(table);
	table->start_time = get_start_time();
	while (i < table->nb_philo)
	{
		philo = &table->philo[i];
		if (pthread_create(&philo->thread_id, NULL, routine, philo))
		{
			pthread_mutex_lock(&table->status);
			table->full = 1;
			pthread_mutex_unlock(&table->status);
			return (1);
		}
		i++;
	}
	wait_until_full(table);
	return (0);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (check_input(argc, argv))
	{
		printf("Error: Input\n");
		return (1);
	}
	if (init_struct(argc, argv, &table))
		return (1);
	if (start_threads(&table))
		return (1);
	return (0);
}
