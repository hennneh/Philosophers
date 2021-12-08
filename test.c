#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

char *s = "hello kostas";

void	*routine()
{
	int i = 0;
	while (i < 9)
	{
	write(1, &s[i], 1);
	i++;
	}
	return (0);
}

int	main(void)
{
	pthread_t t1;
	pthread_t t2;

	pthread_create(&t1, NULL, &routine, NULL);
	pthread_create(&t2, NULL, &routine, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return (0);
}
