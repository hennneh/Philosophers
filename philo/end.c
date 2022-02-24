#include "philo.h"

int	check_status(t_table *table)
{
	long long	ct;
	int			i;
	int			end;
	t_philo		*philo;

	i = 0;
	ct = get_start_time();
	end = table->nb_meals;
	while (i < table->nb_philo)
	{
		philo = &table->philo[i];
		if (table->nb_meals > -1 && philo->nb_meals < table->nb_meals)
			end = -1;
		if (ct - philo->last_meal > (long long)table->ttd)
		{
			table->full = 1;
			ct = ct - philo->table->start_time;
			printf("%lld %d died\n", ct, philo->number);
			return (1);
		}
		i++;
	}
	if (end > -1)
		return (1);
	return (0);
}
