#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int prime[5000];
bool isPrime[5000];
int N = 50;
int len;

void SetPrime();

int main(){
    SetPrime();
    int i;
    for (i = 0; i < len; ++i)
    {
        printf("%d\n", prime[i]);
    }
    return 0;
}

void SetPrime(){
    len = 0;
    memset(isPrime, true, sizeof(isPrime));
    for (int i = 2; i <= N; i++)
    {
		if(isPrime[i])
		{
            prime[len++] = i;
            for (int j = i + i; j <= N; j += i)
                isPrime[j] = false;
		}
	}
}