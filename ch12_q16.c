#include <stdio.h>

int main(int argc, char* argv[])
{
	int i, j, result;
	
	if(argc < 3) {
		printf("Usage: ./multi 3 100\n");
		return 0;
	}
	
	i = atoi(argv[1]);
	j = atoi(argv[2]);
	result = i * j;

	printf("%d\n", result);

	return 0;
}
