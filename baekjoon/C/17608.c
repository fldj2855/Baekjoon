#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
	int arr[100005];

	int n;
	int cnt = 1;
	int top = 0;
	scanf("%d", &n);

	for(int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	top = arr[n-1];
	for(int i = n-1; i >= 0; --i)
	{
		if(arr[i] > top)
		{
			cnt++;
			top = arr[i];
		}
	}

	printf("%d", cnt);
}