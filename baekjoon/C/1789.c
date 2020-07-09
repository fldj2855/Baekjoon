#include<stdio.h>
#include<math.h>

int main(void)
{
	unsigned long long int S;
	int cnt = 0;
	unsigned long long int i;
	scanf("%lld", &S);
	for(i = 1; i*i < S; ++i);
	for( ; i*(i+1)/2 <= S; ++i);
	printf("%lld", i-1);
	return 0;
}