#include <stdio.h>
#include <math.h>

int main()
{
	double left = -10, right = 10, mid;
	double temp = 10;
	while (fabs(temp) > 1e-5)
	{
		mid = (left + right) / 2;
        temp = 2 * pow(mid, 3) - 4 * pow(mid, 2) + 3 * mid - 6;

        if (temp > 0)
		{
			right = mid;
		}
		else if (temp < 0)
		{
			left = mid;
		}
	}
	printf("The root at (-10,10) is:%lf", mid);
	return 0;
}