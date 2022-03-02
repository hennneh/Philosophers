/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:43:00 by hlehmann          #+#    #+#             */
/*   Updated: 2022/03/02 09:43:03 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void ft_fork(t_philo *philo)
{
    long long   current_time;

    pthread_mutex_lock(&philo->table->status);
    if (philo->table->end_of_buffet == 1)
    {
        pthread_mutex_unlock(&philo->table->status);
        return ;
    }
    current_time = ft_get_time() - philo->table->time_at_start;
    printf("%lld %d has taken a fork\n", current_time, philo->seat);
    pthread_mutex_unlock(&philo->table->status);
}

void ft_eat(t_philo *philo)
{
    long long   current_time;

    pthread_mutex_lock(&philo->table->status);
    if (philo->table->end_of_buffet == 1)
    {
        pthread_mutex_unlock(&philo->table->status);
        return ;
    }
    current_time = ft_get_time() - philo->table->time_at_start;
    printf("%lld %d is eating\n", current_time, philo->seat);
    philo->time_of_last_plate = ft_get_time();
    pthread_mutex_unlock(&philo->table->status);
}

void ft_sleep(t_philo *philo)
{
    long long   current_time;

    pthread_mutex_lock(&philo->table->status);
    if (philo->table->end_of_buffet == 1)
    {
        pthread_mutex_unlock(&philo->table->status);
        return ;
    }
    current_time = ft_get_time() - philo->table->time_at_start;
    printf("%lld %d is sleeping\n", current_time, philo->seat);
    philo->plate_count++;
    pthread_mutex_unlock(&philo->table->status);
}

void ft_think(t_philo *philo)
{
    long long   current_time;

    pthread_mutex_lock(&philo->table->status);
    if (philo->table->end_of_buffet == 1)
    {
        pthread_mutex_unlock(&philo->table->status);
        return ;
    }
    current_time = ft_get_time() - philo->table->time_at_start;
    printf("%lld %d is thinking\n", current_time, philo->seat);
    pthread_mutex_unlock(&philo->table->status);
}
