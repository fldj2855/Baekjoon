#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define PUSH '+'
#define POP '-'

typedef struct Node
{
	int data;
	struct Node *next;
}Node;

typedef struct Stack
{
	int Call_time;
	Node headerNode;
}Stack;

void push(Stack *pStack);
int pop(Stack *pStack, int s);
Stack *createStack();

int D = 1;
char BIT[200005];
int BIT_len = 0;

int main(void) 
{
	Stack *pStack = NULL;
	int s;
	int n;

	pStack = createStack();

	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &s);
		// printf("[*] pStack->Call_time : %d\n", pStack->Call_time);
		// printf("[*] pStack->Current_Count : %d\n", pStack->Current_Count);
		// printf("[*] s : %d\n\n", s);
		if(s > pStack->Call_time)
		{
			while(s > pStack->Call_time)
			{
				push(pStack);
			}
			pop(pStack, s);
		}
		else
		{
			if(pop(pStack, s))
				return 0;
		}
	}

	printf("%s", BIT);

	return 0;
}

Stack *createStack()
{
	Stack *ret = NULL;
	ret = (Stack *)malloc(sizeof(Stack));
	if(ret == NULL)
		while(1);

	ret->Call_time = 0;

	return ret;
}

void push(Stack *pStack)
{
	Node *pre = NULL;
	Node *new = NULL;
	int n;

	pre = (&(pStack->headerNode))->next;

	new = (Node *)malloc(sizeof(Node));
	if(new == NULL)
		while(1);

	new->data = D++;
	new->next = pre;

	(&(pStack->headerNode))->next = new;
	pStack->Call_time++;

	BIT[BIT_len++] = PUSH;
	BIT[BIT_len++] = '\n';
}

int pop(Stack *pStack, int s)
{
	Node *pre = NULL;
	Node *victim = NULL;    // free
	pre = &(pStack->headerNode);

	victim = pre->next;
	pre = victim->next;

	// printf("[*] pop %d\n", victim->data);
	if(victim->data != s)
	{
		printf("NO");
		return 1;
	}
	victim->data = 0;
	victim->next = NULL;
	free(victim);
	victim = NULL;

	(&(pStack->headerNode))->next = pre;

	BIT[BIT_len++] = POP;
	BIT[BIT_len++] = '\n';

	return 0;
}