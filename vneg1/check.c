/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:23:55 by hlehmann          #+#    #+#             */
/*   Updated: 2021/12/09 21:55:44 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isint(int argc, char **argv)
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

int	ft_check(int argc, char **argv)
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
	if (ft_isint(argc, argv))
		return (1);
	return (0);
}

void	ft_init(int argc, char **argv, t_t *t)
{
	t->nb_phil = ft_atoi(argv[1]);
	t->t2d = ft_atoi(argv[2]);
	t->t2e = ft_atoi(argv[3]);
	t->t2s = ft_atoi(argv[4]);
	t->mls = 0;
	t->ded = 0;
	if (argc == 6)
		t->mls = ft_atoi(argv[5]);
	else
		t->mls = -1;
}
