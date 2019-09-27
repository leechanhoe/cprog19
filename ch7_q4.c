#include <stdio.h>
 
 int main(void)
{
    int i = 2,j = 1;
	
	while(i < 10)
    {
    	j = 1;
        while(j < 10)
        {
            printf("%d x %d = %d\n", i, j, i*j);
            j++;
        }
        i += 2;
    }
    return 0;
}
