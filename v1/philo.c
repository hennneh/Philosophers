#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (check_input(argc, argv))
		return (1);
	if (init_struct(argc, argv, &table))
		return (1);
	if (start_threads(&table))
		return (1);
	return (0);
}
