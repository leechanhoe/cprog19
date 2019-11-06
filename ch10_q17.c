#include <stdio.h>

void matrix()
{
	int a[3][2] = {{0,1},{1,1},{1,0}};
	int b[2][4] = {{1,1,0,1},{0,1,0,0}};
	int c[3][4];

	int i,j,k;
	int sum;

	for (i = 0;i < 3;i++){
		for (j = 0;j < 4;j++){
			sum = 0;
			for(k = 0;k < 2;k++){
				sum+=a[i][k]*b[k][j];
			}
			c[i][j]=sum;
		}
	}

	for(i=0;i < 3;i++)
	{
		for(j=0;j < 4;j++)
		{
			printf("%d\t", c[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	matrix();
	return 0;
}
		
