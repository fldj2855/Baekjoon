#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node
{
	int value;
	struct Node *next;
}Node;

Node *head = NULL;
Node *tail = NULL;

int N;
int cnt;

int push();
int pop();
int addNode(int value);

int main(void)
{
	scanf("%d", &N);
	cnt = N-1;

	head = (Node *)malloc(sizeof(Node));
	tail = head;

	for(int i = 1; i <= N; ++i)
		addNode(i);

	while(cnt != 0)
	{
		pop();push();
		cnt--;
	}
	printf("%d", tail->value);

	return 0;
}

int addNode(int value)
{
	tail->next = (Node *)malloc(sizeof(Node));

	if(! tail->next)
		return -1;

	tail = tail->next;
	tail->value = value;


	return 0;

}

int push()
{
	Node *p = NULL;

	p = head->next->next;

	tail->next = head->next;
	tail = tail->next;
	tail->next = NULL;

	head->next = p;
	return 0;
}

int pop()
{
	Node *prev = NULL;
	Node *p = NULL;
	prev = head->next;	// free!
	p = head->next->next;
	head->next = p;
	
	prev->next = NULL;
	// printf("%d ", prev->value);
	free(prev);

	return 0;
}