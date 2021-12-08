/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:32:57 by hlehmann          #+#    #+#             */
/*   Updated: 2021/12/08 13:33:01 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>

typedef struct s_t
{
	int	philos;
	int	cycles;
	int	tts;
	int	tte;
	int	ttd;
	int	eaten;
	float	time;
}	t_t;

int	ft_atoi(const char *nptr);

#endif
