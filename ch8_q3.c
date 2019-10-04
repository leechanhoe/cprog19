#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int i;

	srand((unsigned)time(NULL));
	for (i = 0; i < 10; i++)
		printf("%d\n", 1 + rand() % 100);

	return 0;
}
