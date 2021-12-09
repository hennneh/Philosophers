/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:35:53 by hlehmann          #+#    #+#             */
/*   Updated: 2021/12/09 11:48:28 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check(int argc, char **argv)
{
	int	i;
	int	j;

	j = 1;
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
	return (0);
}

int	ft_init(int argc, char **argv, t_t *t)
{
	if (argc < 5 || argc > 6)
		return (1);
	if (ft_check(argc, argv))
		return (1);
	t->p = ft_atoi(argv[1]);
	t->ttd = ft_atoi(argv[2]);
	t->tte = ft_atoi(argv[3]);
	t->tts = ft_atoi(argv[4]);
	if (argc == 6)
		t->m = ft_atoi(argv[5]);
	else
		t->m = -1;
	return (0);
}

void	*routine(void *t)
{
	printf("test\n");
	sleep(1);
	printf("clemens\n");
	((t_t *)t)->p = 9;
	return (0);
}

void	ft_create(t_t *t)
{
	int	i;

	i = 0;
	t->gl = malloc(sizeof(pthread_t) * t->p);
	while (i < t->p)
	{
		pthread_create(&t->gl[i], NULL, &routine, t);
		i++;
	}
	i = 0;
	t->f = malloc(sizeof(pthread_mutex_t) * t->p);
	while (i < t->p)
	{
		
	}
	i = 0;
	while (i < t->p)
	{
		pthread_join(t->gl[i], NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_t	t;

	if (ft_init(argc, argv, &t))
		return (1);
	printf("reached ft_create\n");
	ft_create(&t);
	return (0);
}
