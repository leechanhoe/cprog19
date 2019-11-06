#include <stdio.h>
#define STUDENTS 5


int get_average(int scores[],int n)
{
	int sum = 0;

	for (int i = 0; i < n; i++)
		sum += scores[i];
	return sum / n;
}

int main()
{
	int scores[STUDENTS] = { 1,2,3,4,5 };
	int avg;

	avg = get_average(scores, STUDENTS);
	printf("평균은 %d입니다.\n", avg);
	return 0;
}
