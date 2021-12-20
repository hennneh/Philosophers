#include "philo.h"

long long	ft_log(t_philo *phil)
{
	long long	log;
	long long	ct;

	ct = ft_time();
	log = ct - phil->table->start_time;
	return (log);
}

void	*routine(void *philo)
{
	t_philo	phil;

	phil = *(t_philo *)philo;
	while (phil.table->dead)
	{
		printf("[%lld] %d has started thinking\n", ft_log(&phil), phil.id);
		printf("[%lld] %d has started eating\n", ft_log(&phil), phil.id);
		usleep(phil.table->t2e * 1000);
		printf("[%lld] %d has started sleeping\n", ft_log(&phil), phil.id);
		usleep(phil.table->t2e * 1000);
		phil.table->dead = 0;
	}
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
