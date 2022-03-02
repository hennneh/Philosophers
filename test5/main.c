/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 09:03:03 by hlehmann          #+#    #+#             */
/*   Updated: 2022/02/09 09:03:05 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_free(t_table *table)
{
	if (table->forks)
		free (table->forks);
	if (table->philo)
		free (table->philo);
	return (1);
}

int	ft_exit(t_table *table)
{
	int		a;
	t_philo	*philo;

	a = 0;
	while (a < table->nb_philo)
	{
		philo = &table->philo[a];
		pthread_join(philo->thread_id, NULL);
		a++;
	}
	a = 0;
	while (a < table->nb_philo)
	{
		pthread_mutex_destroy(&table->forks[a]);
		a++;
	}
	pthread_mutex_destroy(&table->status);
	return (ft_free(table));
}

static int	is_valid(char *argv)
{
	int	a;

	a = 0;
	if (!argv || !argv[a])
		return (1);
	while (argv[a])
	{
		if (argv[a] < '0' || argv[a] > '9')
			return (1);
		a++;
	}
	return (0);
}

static int	error_check(int argc, char **argv)
{
	int	a;

	a = 1;
	if (argc < 5 || argc > 6)
	{
		write (2, "Error: Input\n", 13);
		return (1);
	}
	while (argv[a])
	{
		if (is_valid(argv[a]) == 1)
			return (1);
		a++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (!error_check(argc, argv))
	{
		if (set_table(argc, argv, &table) == 1)
			return (1);
		if (lunch(&table) == 1)
			return (ft_exit(&table));
	}
	else
		return (1);
	return (ft_exit(&table) * 0);
}
