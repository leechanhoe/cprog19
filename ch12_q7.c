#include <stdio.h>
#include <string.h>

int main()
{
	char dst[12] = "Hello";
	char src[6] = "World";
	strcat(dst, src);
	fputs(dst, stdout);
}
