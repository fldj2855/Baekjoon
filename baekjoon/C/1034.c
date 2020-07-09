#include<stdio.h>
#include<string.h>

int main(void)
{
	int N, M;
	int bit_count;
	int same = 0;
	int ANS = 0, K;
	char LAMP[50][51]={'\0'};

	scanf("%d %d", &N, &M);

	for(int i = 0; i < N; ++i)
		scanf("%s", LAMP[i]);

	scanf("%d", &K);

	for(int i = 0; i < N; ++i)
	{
		bit_count = 0;
		same = 0;
		
		for(int j = 0; j < M; ++j)
		{
			if(LAMP[i][j]=='0')
				bit_count++;
		}

		if(bit_count <= K && !((K-bit_count)%2))
		{
			for(int j = 0; j < N; ++j)
				if(!strcmp(LAMP[i], LAMP[j]))
					same++;
		
			if(same > ANS)
				ANS = same;
		}
	}

	printf("%d\n", ANS);

	return 0;
}