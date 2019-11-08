#include <string.h>
#include <stdio.h>

int main()
{
	char s[] = "language";
	char c = 'g';
	char *p;

	p = strchr(s, c);
	for(p;*p != '\0';p++)
	{
		if (*p == c)
			printf("Found at %d\n", p - s);
	}
}
