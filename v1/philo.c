/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 08:28:08 by hlehmann          #+#    #+#             */
/*   Updated: 2022/02/01 10:19:01 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (check_input(argc, argv))
		return (1);
	if (init_struct(argc, argv, &table))
		return (1);
	printf("%lld\n", table.start_time);
//	if (start_threads(&table))
//		return (1);
	return (0);
}
