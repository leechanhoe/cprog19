#include <stdio.h>

int main()
{
	char src[] = "abc";
	char dst[100];
	int i;	
	printf("원본 문자열=%s\n", src);
	for(i = 0;src[i]!='\0';i++)
		dst[i] = src[i];
	dst[i] = '\0';
	printf("복사된 문자열=%s\n", dst);
}
