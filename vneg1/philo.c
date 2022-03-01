/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:35:53 by hlehmann          #+#    #+#             */
/*   Updated: 2022/01/31 14:17:28 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *t)
{
	printf("test\n");
	sleep(1);
	printf("clemens\n");
	((t_t *)t)->np = 9;
	return (0);
}

void	ft_create(t_t *t)
{
	int	i;

	i = 0;
	t->p = malloc(sizeof(pthread_t) * t->np);
	t_philo	phil;
	phil.meals_eaten = 0;
	phil.last_meal_time = t->st;
	phil.t = t;
	while (i < t->np)
	{
		phil.id = malloc(sizeof(int));
		*phil.id = i;
		pthread_create(&t->p[i], NULL, &routine, &phil);
		i++;
	}
	i = 0;
	t->f = malloc(sizeof(pthread_mutex_t) * t->np);
	while (i < t->np)
	{
		pthread_mutex_init(&t->f[i], NULL);
		i++;
	}
	i = 0;
	while (i < t->np)
	{
		pthread_join(t->p[i], NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (check_input(argc, argv))
		return (1);
	init_struct(argc, argv, &table);
	create_threads(&table);
	return (0);
}