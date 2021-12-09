#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

int	main(void)
{
	struct timeval tyme;

	gettimeofday(&tyme, NULL);
	printf("%ld\n", tyme.tv_sec);
	printf("%d\n", tyme.tv_usec);
	sleep(1);
	gettimeofday(&tyme, NULL);
	printf("%ld\n", tyme.tv_sec);
	printf("%d\n", tyme.tv_usec);
	sleep(1);
	gettimeofday(&tyme, NULL);
	printf("%ld\n", tyme.tv_sec);
	printf("%d\n", tyme.tv_usec);
	sleep(1);
	gettimeofday(&tyme, NULL);
	printf("%ld\n", tyme.tv_sec);
	printf("%d\n", tyme.tv_usec);
	return (0);
}
