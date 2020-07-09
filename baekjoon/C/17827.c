#include<stdio.h>

int main(void)
{
	int arr[200005];

	int n, m, v;
	int q;
	int i;

	scanf("%d %d %d", &n, &m, &v);v--;

	for(i = 0; i < n; ++i)
		scanf("%d", &arr[i]);
	
	for(i = 0; i < m; ++i)
	{
		scanf("%d", &q);
		if(q >= n)
		{
			printf("%d\n", arr[v + (q-v) % (n-v)]);
		}
		else
		{
			printf("%d\n", arr[q]);
		}
	}

	return 0;
}