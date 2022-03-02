/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init_and_finish.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 09:02:47 by hlehmann          #+#    #+#             */
/*   Updated: 2022/02/09 09:02:49 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ph_check_end(t_table *table)
{
	int			a;
	int			end_with_plates;
	long long	current_time;
	t_philo		*philo;

	a = 0;
	current_time = ft_get_time();
	end_with_plates = table->nb_plates;
	while (a < table->nb_philo)
	{
		philo = &table->philo[a];
		if (table->nb_plates > -1 && philo->plate_count < table->nb_plates)
			end_with_plates = -1;
		if (current_time - philo->time_of_last_plate > (long long)table->ttd)
		{
			table->end_of_buffet = 1;
			print_message(philo, "died");
			return (0);
		}
		a++;
	}
	if (end_with_plates > -1)
		return (0);
	return (1);
}

void	ph_wait_end_of_buffet(t_table *table)
{
	while (1)
	{
		pthread_mutex_lock(&table->status);
		if (!ph_check_end(table))
		{
			table->end_of_buffet = 1;
			pthread_mutex_unlock(&table->status);
			break ;
		}
		pthread_mutex_unlock(&table->status);
	}
}

void	ph_init_philo(t_table *table)
{
	int		a;
	t_philo	*philo;

	a = 0;
	while (a < table->nb_philo)
	{
		philo = &table->philo[a];
		philo->table = table;
		philo->seat = a + 1;
		philo->time_of_last_plate = table->time_at_start;
		philo->life = 1;
		philo->left_fork = &table->forks[a];
		a++;
		philo->right_fork = &table->forks[a % table->nb_philo];
	}
}

int	set_table(int ac, char **av, t_table *table)
{
	int	a;

	table->end_of_buffet = 0;
	table->nb_philo = ft_atol(av[1]);
	if (!table->nb_philo)
		return (1);
	table->ttd = ft_atol(av[2]);
	table->tte = ft_atol(av[3]);
	table->tts = ft_atol(av[4]);
	table->nb_plates = -1;
	if (ac == 6)
		table->nb_plates = ft_atol(av[5]);
	table->forks = ft_calloc(table->nb_philo, sizeof(pthread_mutex_t));
	table->philo = ft_calloc(table->nb_philo, sizeof(t_philo));
	if (!table->forks || !table->philo)
		return (ft_free(table));
	pthread_mutex_init(&table->status, NULL);
	a = 0;
	while (a < table->nb_philo)
	{
		pthread_mutex_init(&table->forks[a], NULL);
		a++;
	}
	return (0);
}
