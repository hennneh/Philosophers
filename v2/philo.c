#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (ft_init(argc, argv, &table))
		return (1);
	printf("time: %lld\n", table.start_time);
	return (0);
}
