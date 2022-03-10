/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 09:02:47 by hlehmann          #+#    #+#             */
/*   Updated: 2022/03/09 10:49:35 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	print_message(t_philo *philo, char *status)
{
	long long	current_time;

	current_time = ft_get_time() - philo->table->time_at_start;
	printf("%lld %d %s\n", current_time, philo->seat, status);
}

static int	check_end(t_table *table)
{
	int			i;
	int			end_with_plates;
	long long	current_time;
	t_philo		*philo;

	i = 0;
	current_time = ft_get_time();
	end_with_plates = table->nb_plates;
	while (i < table->nb_philo)
	{
		philo = &table->philo[i];
		if (table->nb_plates > -1 && philo->plate_count < table->nb_plates)
			end_with_plates = -1;
		if (current_time - philo->time_of_last_plate > (long long)table->ttd)
		{
			table->end_of_buffet = 1;
			print_message(philo, "died");
			return (0);
		}
		i++;
	}
	if (end_with_plates > -1)
		return (0);
	return (1);
}

void	waiter(t_table *table)
{
	while (1)
	{
		pthread_mutex_lock(&table->status);
		if (!check_end(table))
		{
			table->end_of_buffet = 1;
			pthread_mutex_unlock(&table->status);
			break ;
		}
		pthread_mutex_unlock(&table->status);
	}
}

void	init_philo(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < table->nb_philo)
	{
		philo = &table->philo[i];
		philo->table = table;
		philo->seat = i + 1;
		philo->time_of_last_plate = table->time_at_start;
		philo->life = 1;
		philo->left_fork = &table->forks[i];
		i++;
		philo->right_fork = &table->forks[i % table->nb_philo];
	}
}

int	set_table(int argc, char **argv, t_table *table)
{
	int	i;

	table->end_of_buffet = 0;
	table->nb_philo = ft_atol(argv[1]);
	if (!table->nb_philo)
		return (1);
	table->ttd = ft_atol(argv[2]);
	table->tte = ft_atol(argv[3]);
	table->tts = ft_atol(argv[4]);
	table->nb_plates = -1;
	if (argc == 6)
		table->nb_plates = ft_atol(argv[5]);
	table->forks = ft_calloc(table->nb_philo, sizeof(pthread_mutex_t));
	table->philo = ft_calloc(table->nb_philo, sizeof(t_philo));
	if (!table->forks || !table->philo)
		return (ft_free(table));
	pthread_mutex_init(&table->status, NULL);
	i = 0;
	while (i < table->nb_philo)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
	return (0);
}
