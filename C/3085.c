#include<stdio.h>
#include<string.h>
#define max(A, B) (A > B ? A : B)

char arr[55][55];
int len;
int MAX = 1;

void check();
void swap(char *p, char *q);

int main(void)
{
	int n;
	int max = -1, tmp;
	int i, j;
	scanf("%d",&n);
	len = n;
	for(i = 0; i < n; ++i)
		scanf("%s",arr[i]);

	for(i = 0; i < len; ++i)
	{
		for(j = 0; j < len - 1; ++j)
		{
			if(arr[i][j] != arr[i][j+1])
			{
				swap(&arr[i][j], &arr[i][j+1]);
				check();
				swap(&arr[i][j], &arr[i][j+1]);
			}
			if(arr[j][i] != arr[j+1][i])
			{
				swap(&arr[j][i], &arr[j+1][i]);
				check();
				swap(&arr[j][i], &arr[j+1][i]);	
			}
		}
	}
	printf("%d\n", MAX);

	return 0;
}

void swap(char *p, char *q)
{
	char tmp = *p;
	*p = *q;
	*q = tmp;
}

void check()
{
	int count = 1;
	//양 옆
	for (int i = 0; i < len; i++)
	{
		count = 1;
		for (int j = 1; j < len; j++)
		{
			if (arr[i][j - 1] == arr[i][j])
				count++;
			else
			{
				MAX = max(MAX, count);
				count = 1;
			}
		}
		MAX = max(MAX, count);
	}
    
	//위 아래
	for (int i = 0; i < len; i++)
	{
		count = 1;
		for (int j = 0; j < len - 1; j++)
		{
			if (arr[j + 1][i] == arr[j][i])
				count++;
			else
			{
				MAX = max(MAX, count);
				count = 1;
			}
		}
		MAX = max(MAX, count);
	}
}