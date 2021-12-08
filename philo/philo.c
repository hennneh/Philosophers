/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:35:53 by hlehmann          #+#    #+#             */
/*   Updated: 2021/12/08 13:42:42 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init(int argc, char **argv, t_t *t)
{
	if (argc < 6 || argc > 7)
		return (1);
	t->philos = ft_atoi(argv[1]);
	return (0);
}

int	main(int argc, char **argv)
{
	t_t	t;

	if (ft_init(argc, argv, &t))
		return (1);
	return (0);
}
