/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 08:41:31 by hlehmann          #+#    #+#             */
/*   Updated: 2022/02/09 08:41:32 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_info	input;

	if (ingredients_check(argc, argv, &input))
		return (1);
	if (catering_check(&input))
		return (2);
	dinner_init(&input);
	if (clean_table(&input))
		return (3);
	return (0);
}
