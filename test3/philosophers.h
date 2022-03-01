/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 09:03:10 by hlehmann          #+#    #+#             */
/*   Updated: 2022/02/09 09:11:25 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define PH_ERRMESSAGE "\n\e[1m\e[31mError: Incorrect number of args,\
correct utilisation is :\e[0m\n\
\e[32m./philo [number of philo] [time to die] \
[time to eat] [time to sleep] [optional number of plates]\e[0m\n\n"

# define PH_FORK 1
# define PH_EAT 2
# define PH_SLEEP 3
# define PH_THINK 4

typedef struct s_table	t_table;
typedef struct s_philo	t_philo;

struct s_table
{
	int				nb_philo;
	size_t			ttd;
	size_t			tte;
	size_t			tts;
	int				nb_plates;
	int				end_of_buffet;
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
	t_table			*program;
};

int			ft_exit(t_table *program);
int			ft_free(t_table *program);
//int		is_valid(char *av);
//int		error_check(int ac, char **av);
//int		main(int ac, char **av);
//int		ph_check_end(t_table *program);
void		ph_wait_end_of_buffet(t_table *program);
void		ph_init_philo(t_table *program);
int			set_table(int ac, char **av, t_table *program);
void		print_message(t_philo *philo, char *status);
//void		ph_action(t_philo *philo, int id);
//void		*routine(void *philo_ptr);
int			ph_buffet(t_table *program);
void		ph_usleep(t_table *program, long long time_limit);
long long	ph_get_time(void);
long		ft_atol(const char *str);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);

#endif //PHILOSOPHERS_H
