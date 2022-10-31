#include <stdio.h>
#include <stdbool.h>

//能求得多个鞍点的特殊情况，但懒得把代码重构至1了
int main()
{
    bool isSaddle = false;
    int n, i, j = 0;
    int col[6], z, max, min;
    int a[6][6];
    int k;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 0; i < n; i++)
    {
        max = a[i][0];
        for (j = 0; j < n; j++)
        {
    		if(max < a[i][j])
    		{
                max = a[i][j];
            }
		}
        for (z = 0, k = 0; z < n; z++)
        {
        	if(a[i][z] == max)
    		{
                col[k] = z;
                k++;
            }
		}
        min = max;
        for (j = 0; j < k; j++)
        {
            for (z = 0; z < n; z++)
            {
	    		if(min > a[z][col[j]])
	    		{
	    			break;
				}
			}
			if(z == n)
			{
                printf("%d %d\n", i, col[j]);
                isSaddle = true;
			}
		}
    }
    if(isSaddle == false)
    {
        printf("NONE\n");
    }
	return 0;
}