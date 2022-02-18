/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 08:28:15 by hlehmann          #+#    #+#             */
/*   Updated: 2022/02/09 09:29:09 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_start_time(void)
{
	struct timeval	s_time;
	long long		return_time;

	gettimeofday(&s_time, NULL);
	return_time = s_time.tv_sec * 1000 + s_time.tv_usec / 1000;
	return (return_time);
}

int	init_struct(int argc, char **argv, t_table *table)
{
	int	i;

	table->nb_philo = ft_atoi(argv[1]);
	table->ttd = ft_atoi(argv[2]);
	table->tte = ft_atoi(argv[3]);
	table->tts = ft_atoi(argv[4]);
	if (argc == 6)
		table->nb_meals = ft_atoi(argv[5]);
	table->full = 0;
	table->forks = malloc(table->nb_philo * sizeof(pthread_mutex_t));
	table->philo = malloc(table->nb_philo * sizeof(t_philo));
	pthread_mutex_init(&table->status, NULL);
	i = 0;
	while (i < table->nb_philo)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
	return (0);
}

static int	ft_is_int(int argc, char **argv)
{
	long	nbr;
	int		i;

	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) > 10)
			return (1);
		nbr = ft_atol(argv[i]);
		if (nbr > 2147483647 || nbr < 0)
			return (1);
		i++;
	}
	return (0);
}

static int	check_value(int argc, char **argv)
{
	if (ft_atoi(argv[1]) < 2)
		return (1);
	if (ft_atoi(argv[2]) < 0)
		return (1);
	if (ft_atoi(argv[3]) < 0)
		return (1);
	if (ft_atoi(argv[4]) < 0)
		return (1);
	if (argc == 6)
	{
		if (ft_atoi(argv[5]) < 1)
			return (1);
	}
	return (0);
}

int	check_input(int argc, char **argv)
{
	int	i;
	int	j;

	j = 1;
	if (argc < 5 || argc > 6)
		return (1);
	while (j < argc)
	{
		i = 0;
		while (argv[j][i])
		{
			if (argv[j][i] < 48 || argv[j][i] > 57)
				return (1);
			i++;
		}
		j++;
	}
	if (ft_is_int(argc, argv))
		return (1);
	if (check_value(argc, argv))
		return (1);
	return (0);
}
