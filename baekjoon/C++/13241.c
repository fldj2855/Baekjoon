#include<stdio.h>
#include<string.h>
#include<stdlib.h>

long long int gcd(long long int a, long long int b)
{
	long long int n;
	while(b)
	{
		n = a%b;
		a = b;
		b = n;
	}
	return a;
}

int main(void)
{
	long long int a, b;
	scanf("%lld %lld", &a, &b);
	printf("%lld\n", a*b/gcd(a, b));
	return 0;
}