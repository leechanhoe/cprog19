#include <stdio.h>
#include <string.h>

int main()
{
	char s[] = "language";
	char c = 'g';
	char *p;
	int loc;

	p = strchr(s, c);
	loc = (int)(p - s);
	if(p != NULL)
		printf("첫번째 %c가 %d에서 발견되었음\n", c, loc);
	else
		printf("%c가 발견되지 않았음\n", c);
}
