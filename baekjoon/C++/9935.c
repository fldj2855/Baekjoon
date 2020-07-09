#include<stdio.h>
#include<string.h>

int main(void)
{
	char string[1000005];
	char stack[1000005];
	int stack_len = 0;
	char bomb[37];
	int bomb_len;
	int string_len;
	int i, j, flag;

	scanf("%s", string);
	scanf("%s", bomb);

	string_len = strlen(string);
	bomb_len = strlen(bomb);

	for(i = 0; i < string_len; ++i)
	{
		flag = 0;
		stack[stack_len++] = string[i];
		if(stack[stack_len-1] == bomb[bomb_len-1])
		{
			if(stack_len >= bomb_len)
			{
				if(!strncmp((stack + stack_len - bomb_len), bomb ,bomb_len))
					flag = 1;
			}

			if(flag)
				stack_len -= bomb_len;
		}
	}

	if(stack_len <= 1)
	{
		printf("FRULA");
		return 0;
	}

	for(i = 0; i < stack_len; ++i)
		printf("%c", stack[i]);
}