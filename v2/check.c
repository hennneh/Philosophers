#include "philo.h"

int	ft_isint(int argc, char **argv)
{
	long	nbr;
	int		i;

	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) > 10)
			return (1);
		nbr = ft_atol(argv[i]);
		if (nbr > 2147483647 || nbr < 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check(int argc, char **argv)
{
	int	i;
	int	j;

	j = 1;
	if (argc < 5 || argc > 6)
		return (1);
	while (j < argc)
	{
		i = 0;
		while (argv[j][i])
		{
			if (argv[j][i] < 48 || argv[j][i] > 57)
				return (1);
			i++;
		}
		j++;
	}
	if (ft_isint(argc, argv))
		return (1);
	return (0);
}

long long	ft_time(struct timeval *time)
{
	long long	nbr;

	nbr = time->tv_sec;
	nbr *= 1000;
	nbr += (time->tv_usec / 1000);
	return (nbr);
}

int	ft_init(int argc, char **argv, t_table *table)
{
	if (ft_check(argc, argv))
		return (1);
	table->nb_philo = ft_atoi(argv[1]);
	table->t2d = ft_atoi(argv[2]);
	table->t2e = ft_atoi(argv[3]);
	table->t2s = ft_atoi(argv[4]);
	if (argc == 6)
		table->nb_meals = ft_atoi(argv[5]);
	else
		table ->nb_meals = -1;
	gettimeofday(&table->time, NULL);
	table->start_time = ft_time(&table->time);
	return (0);
}
