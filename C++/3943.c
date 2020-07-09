#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAX(A, B) (A > B ? A : B)

long long int search(long long int idx)
{
	int ret = idx;

	while(idx != 1)
	{
		if(idx%2)
		{
			idx = idx*3 + 1;
			if(idx > ret)
				ret = idx;
		}
		else
			idx/=2;
	}

	return ret;

}

int main(void)
{
	int i;
	int n;
	long long int k;
	scanf("%d", &n);

	for(i = 0; i < n; ++i)
	{
		scanf("%lld", &k);
		printf("%lld\n", search(k));
	}
}