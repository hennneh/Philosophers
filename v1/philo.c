/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 08:28:08 by hlehmann          #+#    #+#             */
/*   Updated: 2022/02/01 14:16:38 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (check_input(argc, argv))
		return (1);
	if (init_struct(argc, argv, &table))
		return (1);
	printf("%lld\n", table.start_time);
	if (start_threads(&table))
		return (1);
	return (0);
}