#include "philo.h"

static int	ft_is_int(int argc, char **argv)
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

int	ft_check_value(int argc, char **argv)
{
	if (ft_atoi(argv[1]) < 2)
		return (1);
	if (ft_atoi(argv[2]) < 0)
		return (1);
	if (ft_atoi(argv[3]) < 0)
		return (1);
	if (ft_atoi(argv[4]) < 0)
		return (1);
	if (argc == 6)
	{
		if (ft_atoi(argv[5]) < 1)
			return (1);
	}
	return (0);
}

int	check_input(int argc, char **argv)
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
	if (ft_is_int(argc, argv))
		return (1);
	if (ft_check_value(argc, argv))
		return (1);
	return (0);
}
