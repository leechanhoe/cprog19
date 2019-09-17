#include <stdio.h>
#include <sys/time.h>

#define MAX_LIMIT 100

int main()
{
	struct timeval t_start, t_end;
	int i, cnt;

	gettimeofday(&t_start, NULL);

	i = 0;
	cnt = 0;

	while (i < MAX_LIMIT) {
		if ((i % 2) == 0)
			cnt++;
		i++;
	}
	printf("even numbers = %d\n", cnt);

	gettimeofday(&t_end, NULL);

	printf("%f usec\n", (t_end.tv_sec - t_start.tv_sec + (t_end.tv_usec - t_start.tv_usec/ 1.0)));
	return 0;
}

