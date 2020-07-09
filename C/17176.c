#include <stdio.h>
#include <string.h>

int dp[55];
int dp2[55];

int main()
{
	int n;
	int k;
	char ch;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &k);
		dp[k]++;
	}

	getchar();

	for (int i = 0; i < n; ++i) {
		scanf("%c", &ch);
		if ('a' <= ch && ch <= 'z')	dp2[ch - 70]++;
		else if ('A' <= ch && ch <= 'Z')	dp2[ch - 64]++;
		else if (ch == ' ')	dp2[0]++;
	}

	for (int i = 0; i < 55; ++i) {
		if (dp[i] != dp2[i]) {
			printf("n");
			return 0;
		}
	}
	printf("y");
	return 0;
}