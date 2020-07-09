#include <stdio.h>
#include <stdlib.h>

int prime[1000005];
char n[105];
void eratos(int n)
{
	int i, j;
	prime[1] = 1;
	for (i = 2; i <= n; i++) {
		if (prime[i] == 0) {
			for (j = i * 2; j <= n; j += i) {  // i의 제곱부터 n까지 i씩 증가 
				prime[j] = 1;       // i의 배수 제거하기
			}
		}
	}
}

int mod(char *S, int p)
{
	// S는 수를 문자열로 표현한 것, 1324 -> "1324"
	int ret = 0;
	for (int i = 0; S[i] != NULL && S[i] != ' '; i++) ret = (ret * 10 + (S[i] - '0')) % p;
	return ret;
}

int main()
{

	int m;
	
	scanf("%s %d",n,&m);
	eratos(1000005);
	
	for (int i = 2; i <= m; ++i) {
		if (!prime[i]) {
			if (!mod(n, i)) {
				printf("BAD %d", i);
				return 0;
			}
		}
	}
	printf("GOOD");
	
	return 0;
}