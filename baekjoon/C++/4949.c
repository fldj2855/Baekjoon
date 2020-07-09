#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node
{
	char data;
	struct Node *next;
}Node;

typedef struct Stack
{
	int Current_Count;
	Node headerNode;
}Stack;

void push(Stack *pStack, char s);
int pop(Stack *pStack, char s);
void delete(Stack *pStack);
Stack *createStack();

int main(void) 
{
	Stack *pStack = NULL;
	char str[101];
	int flag;
	pStack = createStack();

	while(1)
	{
		gets(str);
		if(!strcmp(str, "."))
			break;
		flag = 0;
		for(int i = 0; i < strlen(str); ++i)
		{
			if(str[i] == '(' || str[i] == '[')
				push(pStack, str[i]);
			else if(str[i] == ')' || str[i] == ']')
			{
				if(pop(pStack, str[i]))
				{
					printf("no\n");
					flag = 1;
					break;
				}
			}
		}
		if(!flag && pStack->Current_Count)
			printf("no\n");
		else if(!flag)
			printf("yes\n");

		memset(str, 0, sizeof(str));
		pStack->Current_Count = 0;
		delete(pStack);
	}

	free(pStack);

	return 0;
}

Stack *createStack()
{
	Stack *ret = NULL;
	ret = (Stack *)malloc(sizeof(Stack));
	ret->Current_Count = 0;

	return ret;
}

void push(Stack *pStack, char s)
{
	Node *pre = NULL;
	Node *new = NULL;
	int n;

	pre = (&(pStack->headerNode))->next;

	new = (Node *)malloc(sizeof(Node));
	memset(new, 0, sizeof(Node));

	new->data = s;
	new->next = pre;

	(&(pStack->headerNode))->next = new;
	pStack->Current_Count++;
}

int pop(Stack *pStack, char s)
{
	if(!pStack->Current_Count)
		return 1;
	Node *pre = NULL;
	Node *victim = NULL;    // free
	pre = &(pStack->headerNode);

	victim = pre->next;
	pre = victim->next;

	if(s == ')')
	{
		if(victim->data != '(')
			return 1;
	}
	else if(s == ']')
	{
		if(victim->data != '[')
			return 1;
	}

	victim->data = 0;
	victim->next = NULL;
	free(victim);
	victim = NULL;

	(&(pStack->headerNode))->next = pre;
    pStack->Current_Count--;

    return 0;
}

void delete(Stack *pStack)
{
	for(Node *p = (&(pStack->headerNode))->next; p; p=p->next)
		free(p);
	(&(pStack->headerNode))->next = NULL;
}