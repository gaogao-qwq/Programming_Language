#include <stdio.h>

float polya(float n, float x);

int main()
{
	float n, x;
	printf("Please enter var n and x:");
	scanf("%f%f", &n, &x);
	printf("P%d(%d) = %f", (int)n, (int)x, polya(n, x));
	return 0;
}

float polya(float n, float x)
{
	if (n == 0)
	{
		return 1;
	}
	if (n == 1)
	{
		return x;
	}
	if (n > 1)
	{
		return ((2 * n - 1) * x * polya((n - 1), x) - (n - 1) * polya((n - 2), x)) / n;
	}
}