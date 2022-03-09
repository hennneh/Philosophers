/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 09:03:10 by hlehmann          #+#    #+#             */
/*   Updated: 2022/03/09 10:49:59 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_table	t_table;
typedef struct s_philo	t_philo;

struct s_table
{
	int				nb_philo;
	int				nb_plates;
	int				end_of_buffet;
	size_t			ttd;
	size_t			tte;
	size_t			tts;
	long long		time_at_start;
	pthread_mutex_t	*forks;
	pthread_mutex_t	status;
	t_philo			*philo;
};

struct s_philo
{
	int				seat;
	int				plate_count;
	int				life;
	long long		time_of_last_plate;
	pthread_t		thread_id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_table			*table;
};

int			ft_exit(t_table *table);
int			ft_free(t_table *table);
void		waiter(t_table *table);
void		init_philo(t_table *table);
int			set_table(int ac, char **av, t_table *table);
int			lunch(t_table *table);
void		ft_usleep(t_table *table, long long time_limit);
long long	ft_get_time(void);
long		ft_atol(const char *str);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
void		ft_fork(t_philo *philo);
void		ft_eat(t_philo *philo);
void		ft_sleep(t_philo *philo);
void		ft_think(t_philo *philo);

#endif
