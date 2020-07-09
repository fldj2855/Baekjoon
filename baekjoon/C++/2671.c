#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char string[155];
int len;

int check(int idx)
{
	int i = idx;
	if(idx == len)
		return 1;
	if(idx > len)
		return 0;

	if(idx <= len-3 && !strncmp(string+idx,"100", 3))
	{
		// printf("100~1~ : %s\n", string+idx);
		for(i = idx+3; string[i] != '1'; ++i)
			if(i >= len)
				return 0;
		// printf("1~ : %s\n", string+i);
		for( ; string[i] != '0'; ++i)
		{
			if(i == len)
				return 1;
		}


		if(!strncmp(string+i, "01", 2))
		{
			// printf("end : %s\n", string+i);
			return check(i);
		}
		else if(!strncmp(string+i-2, "1100", 4))
		{
			// printf("end : %s\n", string+i-1);
			return check(i-1);	
		}

		return 0;
	}
	else if(idx <= len-1 && !strncmp(string+idx, "01", 2))
	{
		return check(idx+2);
	}

	return 0;

}

int main(void)
{
	scanf("%s", string);
	len = strlen(string);

	if(check(0))
		printf("SUBMARINE\n");
	else
		printf("NOISE\n");
	
	return 0;
}