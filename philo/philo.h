/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:32:57 by hlehmann          #+#    #+#             */
/*   Updated: 2021/12/08 16:38:32 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
/*
typedef struct s_p
{
	int	lm; //time since last meal
	int	te; //times eaten
	int	tn; //threadnumber
	pthread_mutex_t	f; //fork
	t_p *nl; //next element in the linked list
}	t_p;
*/

typedef struct s_t
{
	int	p; //number of philosophers
	int	ttd; //time to die
	int	tte; //time to eat
	int	tts; //time to sleep
	int	m; //how many times to eat aka meals
//	float	st; //start time of the program
//	t_l	pl; //linked list with the philosophers
	pthread_t	*gl; //guest list or array for threads
	pthread_mutex_t	*f; //array of mutex which will act as forks
}	t_t;

int	ft_atoi(const char *nptr);

#endif
