#include <stdio.h>
#include <pthread.h>

void	*routine()
{
	printf("hello world\n");
	return (0);
}

int	main(void)
{
	pthread_t t1;

	pthread_create(&t1, NULL, &routine, NULL);
	pthread_join(t1, NULL);
	return (0);
}
