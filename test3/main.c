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

static int	is_valid(char *av)
{
	int	a;

	a = 0;
	if (!av || !av[a])
		return (1);
	while (av[a])
	{
		if (av[a] < '0' || av[a] > '9')
			return (1);
		a++;
	}
	return (0);
}

static int	error_check(int ac, char **av)
{
	int	a;

	a = 1;
	if (ac < 5 || ac > 6)
	{
		write (2, PH_ERRMESSAGE, 181);
		return (1);
	}
	while (av[a])
	{
		if (is_valid(av[a]) == 1)
			return (1);
		a++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_table	table;

	if (!error_check(ac, av))
	{
		if (set_table(ac, av, &table) == 1)
			return (1);
		if (ph_buffet(&table) == 1)
			return (ft_exit(&table));
	}
	else
		return (1);
	return (ft_exit(&table) * 0);
}
