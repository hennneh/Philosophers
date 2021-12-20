#include "philo.h"

void	*routine(void *philo)
{
	t_philo	phil;

	phil = *(t_philo *)philo;
	printf("phils id: %d\n", phil.id);
	while (phil.table->dead)
	{
		printf("%d has started eating\n", phil.id);
		usleep(phil.table->t2e * 1000);
		printf("%d has started sleeping\n", phil.id);
		usleep(phil.table->t2e * 1000);
		printf("%d has started thinking\n", phil.id);
		phil.table->dead = 0;
	}
//	printf("test\n");
//	printf("id: %d\n", ((t_philo *)philo)->id);
	return (0);
}

int	main(int argc, char **argv)
{
	t_table	table;

	table.dead = 1;
	if (ft_init(argc, argv, &table))
		return (1);
	while (table.dead)
	{
		usleep(1000);
	}
	return (0);
}
