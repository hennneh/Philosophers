/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:32:57 by hlehmann          #+#    #+#             */
/*   Updated: 2022/01/31 14:20:01 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>		//remove after testing aöksdjföaskjdföajksdöfjkasöldkjfalöskdjflöaskdjfölaskdjf

struct	s_table;

typedef struct s_philo
{
	int				fork_one;
	int				fork_two;
	int				nb_meals;
	int				id;
	long long		last_meal;
	pthread_t		thread_id;
	struct s_table	table;
}	t_philo;

typedef struct s_table
{
	int				nb_phil;
	int				t2die;
	int				t2eat;
	int				t2sleep;
	int				nb_meals;
	long long		start_time;
	int				dead;
	int				full;
	pthread_mutex_t	*fork;
	pthread_mutex_t	check_meal;
	t_philo			*philo;
}	t_table;

int		ft_atoi(const char *nptr);
long	ft_atol(char *s);
int		ft_check(int argc, char **argv);
size_t	ft_strlen(const char *str);
void	init_struct(int argc, char **argv, t_table *table);

#endif
