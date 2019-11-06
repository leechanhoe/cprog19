#include <stdio.h>
#include<string.h>
#include <ctype.h>
#define SIZE 26

void main()
{
	int count[SIZE] = {0};
	char str[] = "The worst things to eat before you sleep";

	for (int i = 0;str[i] != '\0';i++)
	{
		if (islower(str[i]))
			str[i] = toupper(str[i]);
		count[str[i] - 'A']++;
	}

	for (int i = 0;i < SIZE;i++)
		printf("%c 의 사용횟수 = %d\n", i + 'A', count[i]);
}
