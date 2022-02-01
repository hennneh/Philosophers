/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 08:28:28 by hlehmann          #+#    #+#             */
/*   Updated: 2022/02/01 09:59:42 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

struct s_table;

typedef struct s_philo
{
	int				fork_one;
	int				fork_two;
	int				id;
	int				nb_food;
	long long		last_meal;
	struct s_table	*table;
}	t_philo;

typedef struct s_table
{
	int				nb_philo;
	int				ttd;
	int				tte;
	int				tts;
	int				nb_meals;
	int				dead;
	int				full;
	long long		start_time;
	pthread_mutex_t	check_meal;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	struct s_philo	philo;
}	t_table;

int		check_input(int argc, char **argv);
int		init_struct(int argc, char **argv, t_table *table);
int		ft_atoi(const char *nptr);
long	ft_atol(char *s);
size_t	ft_strlen(const char *str);

#endif
