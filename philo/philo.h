/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:32:57 by hlehmann          #+#    #+#             */
/*   Updated: 2021/12/09 13:18:59 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>		//remove after testing aöksdjföaskjdföajksdöfjkasöldkjfalöskdjflöaskdjfölaskdjf

typedef struct s_t
{
	int				p; //number of philosophers
	int				ttd; //time to die
	int				tte; //time to eat
	int				tts; //time to sleep
	int				m; //how many times to eat aka meals
	struct timeval	st; //starting time of the program
	struct timeval	ct; //current time
	pthread_t		*gl; //guest list or array for threads aka philosophers
	pthread_mutex_t	*f; //array of mutex which will act as forks
}	t_t;

int	ft_atoi(const char *nptr);

#endif
