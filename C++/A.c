#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct T
{
	int score;
	int time;

}T;

int main(void)
{
	int n, o;
	int final = 0;
	T *ar;
	int T_leng = 0;
	scanf("%d", &n);

	ar = (T *)malloc(sizeof(T) * (n));

	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &o);
		if(o == 1)
		{
			T_leng++;
			scanf("%d %d", &ar[T_leng].score, &ar[T_leng].time);
			ar[T_leng].time--;
			if(!ar[T_leng].time)
			{
				final += ar[T_leng].score;
				T_leng--;
			}
		}
		else
		{
			ar[T_leng].time--;
			if(!ar[T_leng].time)
			{
				final += ar[T_leng].score;
				T_leng--;
			}
		}
	}

	printf("%d", final);
}