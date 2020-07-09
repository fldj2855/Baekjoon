#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

int cnt, mod;
int N, K;
node *head;
node *search;
int tmp = 0;
int add_node(node *head, int value);
int delete_node(node *head, int value);

int main(void)
{
	int i, j;
	int k;
	scanf("%d %d", &N, &K);
	mod = cnt = N;

	head = (node *)malloc(sizeof(node));
	if(head == NULL){return -1;}
	search = head;

	for(int i = 1; i <= N; ++i)
		add_node(head, i);

	printf("<");
	while(cnt--)
	{
		for(int i = 0; i < K; ++i)
			search = search->next;
		tmp = search->data;
		printf("%d", tmp);
		if(cnt > 0)
			printf(", ");
	}
	printf(">");

	return 0;
}

int add_node(node *head, int value)
{
	node *p = NULL;
	p = head;
	while(p->next)
		p = p->next;

	p->next = (node *)malloc(sizeof(node));
	if(p->next == NULL){return -1;}
	p->next->data = value;

	if(value == N)
		p->next->next = head->next;

	return 0;
}


int delete_node(node *head, int value)
{
	node *pre = NULL;
	node *nex = NULL;

	pre = head;
	nex = head->next;

	while(nex->data != value && nex->next != NULL)
	{
		pre = pre->next;
		nex = nex->next;
	}

	nex = nex->next;
	pre->next->data = 0;
	pre->next->next = 0;
	free(pre->next);
	pre->next = nex;

	return 0;
}