void Dan(int n)
{
	if(n == 0)
		return;
	else
		printf("3 x %d = %d\n", n, 3*n);
		Dan(n-1);
}

int main()
{
	Dan(9);
	return 0;
}
