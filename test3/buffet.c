/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_buffet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 09:02:36 by hlehmann          #+#    #+#             */
/*   Updated: 2022/02/09 09:02:38 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_message(t_philo *philo, char *status)
{
	long long	current_time;

	current_time = ph_get_time() - philo->program->time_at_start;
	printf("%llu %d %s\n", current_time, philo->seat, status);
}

static void	ph_action(t_philo *philo, int id)
{
	pthread_mutex_lock(&philo->program->status);
	if (philo->program->end_of_buffet == 1)
	{
		pthread_mutex_unlock(&philo->program->status);
		return ;
	}
	if (id == PH_FORK)
		print_message(philo, "has taken a fork");
	else if (id == PH_EAT)
	{
		print_message(philo, "is eating");
		philo->time_of_last_plate = ph_get_time();
	}
	else if (id == PH_SLEEP)
	{
		print_message(philo, "is sleeping");
		philo->plate_count++;
	}
	else if (id == PH_THINK)
		print_message(philo, "is thinking");
	pthread_mutex_unlock(&philo->program->status);
}

static void	*routine(void *philo_ptr)
{
	t_philo	*philo;

	philo = philo_ptr;
	if (philo->seat % 2 == 0)
		ph_usleep(philo->program, philo->program->tte * 1000);
	while (!philo->program->end_of_buffet)
	{
		pthread_mutex_lock(philo->left_fork);
		ph_action(philo, PH_FORK);
		if (philo->left_fork == philo->right_fork)
			break ;
		pthread_mutex_lock(philo->right_fork);
		ph_action(philo, PH_FORK);
		ph_action(philo, PH_EAT);
		ph_usleep(philo->program, philo->program->tte * 1000);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		ph_action(philo, PH_SLEEP);
		ph_usleep(philo->program, philo->program->tts * 1000);
		ph_action(philo, PH_THINK);
	}
	if (philo->left_fork == philo->right_fork)
		pthread_mutex_unlock(philo->right_fork);
	return (NULL);
}

int	ph_buffet(t_table *program)
{
	int		a;
	t_philo	*philo;

	a = 0;
	program->time_at_start = ph_get_time();
	ph_init_philo(program);
	while (a < program->nb_philo)
	{
		philo = &program->philo[a];
		if (pthread_create(&philo->thread_id, NULL, routine, philo))
		{
			pthread_mutex_lock(&program->status);
			program->end_of_buffet = 1;
			pthread_mutex_unlock(&program->status);
			return (1);
		}
		a++;
	}
	ph_wait_end_of_buffet(program);
	return (0);
}
