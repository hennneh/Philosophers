/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:18:45 by hlehmann          #+#    #+#             */
/*   Updated: 2022/03/03 15:52:19 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	ft_check_args(void)
{
	printf("Error: Arguments\n");
}

int	ft_start_philo(t_arg *args)
{
	int	i;

	i = 0;
	args->start_time = ft_time();
	while (i < args->nbr_philo)
	{
		args->philo.philo_ind = i;
		args->pid_philo[i] = fork();
		if (args->pid_philo[i] == -1)
		{
			while (--i >= 0)
				kill(args->pid_philo[i], SIGKILL);
			return (1);
		}
		else if (args->pid_philo[i] == 0)
		{
			ft_init_philo(args);
			ft_routine(args);
		}
		i++;
	}
	sem_wait(args->stop);
	return (0);
}

static void	ft_kill_philosophers(t_arg *args)
{
	int	i;

	i = 0;
	while (i < args->nbr_philo)
	{
		kill(args->pid_philo[i], SIGKILL);
		i++;
	}
}

static int	ft_check_valid(int argc, char **argv)
{
	size_t	i;

	if (argc < 5 || argc > 6)
	{
		ft_check_args();
		return (1);
	}
	i = 1;
	while (argv[i])
	{
		if (!ft_is_digit(argv[i]) || (!ft_atoi(argv[i])))
		{
			printf("Invalid argument\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_arg	args;

	if (ft_check_valid(argc, argv))
		return (1);
	if (ft_init_args(&args, argc, argv) == 1)
		return (1);
	if (ft_start_philo(&args))
		return (1);
	ft_kill_philosophers(&args);
	return (0);
}
