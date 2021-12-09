/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:23:55 by hlehmann          #+#    #+#             */
/*   Updated: 2021/12/09 14:37:21 by hlehmann         ###   ########.fr       */
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
