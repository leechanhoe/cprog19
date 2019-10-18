#include <stdio.h>
#include <sys/time.h>


int main()
{
	register long sum, i;
	
	struct timeval startTime, endTime;
	double diffTime;

	sum = 0;

	gettimeofday(&startTime, NULL);
	for (i = 0; i < 1000000; i++)
		sum += i;
	sleep(1);
	gettimeofday(&endTime, NULL);
	diffTime = (endTime.tv_sec - startTime.tv_sec) + ((endTime.tv_usec - startTime.tv_usec ) / 1000000);

	printf("sum = %ld\n", sum);
	printf("%lf s\n", diffTime);
	return 0;
}
