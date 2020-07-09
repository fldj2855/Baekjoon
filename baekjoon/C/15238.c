#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
	int n, max = 0;
	char string[1005], ch;
	int alpha['z'-'a'+1] = {0};
	scanf("%d", &n);
	scanf("%s", string);

	for(int i = 0; i < n; ++i)
		alpha[string[i]-'a']++;
	
	max = alpha[0];
	ch = 'a';

	for(int i = 0; i < 'z'-'a'+1; ++i)
	{
		if(max < alpha[i])
		{
			max = alpha[i];
			ch = 'a'+i;
		}
	}

	printf("%c %d\n", ch, max);

	return 0;
}
