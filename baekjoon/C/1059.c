//https://www.acmicpc.net/problem/1059

#include<stdio.h>
#include<algorithm>

using namespace std;

int main(void) {

	int n, t, a=0, b=0;
	int lucky[55];

	scanf("%d", &n);
	for (int i = 0; i < n; i++)	scanf("%d", &lucky[i]);
	scanf("%d", &t);

	sort(lucky, lucky + n);
	for (int i = 0; i < n; i++) {
		if (lucky[i] <= t)
			a = lucky[i];
		if (lucky[i] >= t) {
			b = lucky[i];
			break;
		}
	}

	if (a == b)
		printf("0");
	else
		printf("%d", (t - a - 1)*(b - t) + b - t - 1);


	return 0;
}
