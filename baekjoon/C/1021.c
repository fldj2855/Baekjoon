#include<stdio.h>
#include<stdlib.h>

typedef struct Queue
{
	int *Queue;
	int front;
	int rear;
	int Queue_size;
}Queue;

void pop(Queue *pQueue);
void Left(Queue *pQueue);
void Right(Queue *pQueue);
int findidx(Queue *pQueue, int data);

int main(void)
{
	setvbuf(stdin, 0, 2, 0);
	setvbuf(stdout, 0, 2, 0);

	Queue Q = {NULL, 0, 0};
	int n, m;
	int pop_list[51]={0};
	int pop_list_len = 0;
	int res=0;
	int tmp;

	scanf("%d %d", &n, &m);

	Q.Queue = (int *)malloc(sizeof(int)*(n+1));
	Q.Queue_size = n+1;

	for(int i = 1; i<=n; ++i)
	{
		Q.rear = (Q.rear+1)%Q.Queue_size;
		Q.Queue[Q.rear] = i;
	}

	while(m--)
		scanf("%d", &pop_list[pop_list_len++]);
	
	pop_list_len=0;
	while(pop_list[pop_list_len] != 0){
		tmp = findidx(&Q, pop_list[pop_list_len])-1;
		int t=tmp;
		int f = Q.front;
		int r = Q.rear;
		if(f < r)
		{
			if(r-t < t-f)
			{
				for(int i = 0; i < r-t; ++i)
					Right(&Q);
				pop(&Q);
				res += r-t;
			}
			else
			{
				for(int i = 0; i < t-f; ++i)
					Left(&Q);
				pop(&Q);
				res += t-f;	
			}
		}
		else
		{
			if(t < f)
			{
				if(r-t < (t+Q.Queue_size-f))
				{
					for(int i = 0; i < r-t; ++i)
						Right(&Q);
					pop(&Q);
					res += r-t;
				}
				else
				{
					for(int i = 0; i < t+Q.Queue_size-f; ++i)
						Left(&Q);
					pop(&Q);
					res += t+Q.Queue_size-f;
				}
			}
			else
			{
				if(r+Q.Queue_size-t < t-f)
				{
					for(int i = 0; i < r+Q.Queue_size-t; ++i)
						Right(&Q);
					pop(&Q);
					res += r+Q.Queue_size-t;
				}
				else
				{
					for(int i = 0; i < t-f; ++i)
						Left(&Q);
					pop(&Q);
					res += t-f;
				}
			}
		}
		pop_list_len++;
	}

	printf("%d\n", res);

	free(Q.Queue);

	return 0;
}


void pop(Queue *pQueue)
{
	pQueue->front = (pQueue->front+1)%pQueue->Queue_size;
	pQueue->Queue[pQueue->front] = 0;
}

void Left(Queue *pQueue)
{
	int tmp;
	pQueue->front = (pQueue->front+1)%pQueue->Queue_size;
	tmp = pQueue->Queue[pQueue->front];
	pQueue->Queue[pQueue->front] = 0;

	pQueue->rear = (pQueue->rear+1)%pQueue->Queue_size;
	pQueue->Queue[pQueue->rear] = tmp;
}

void Right(Queue *pQueue)
{
	int tmp;
	tmp = pQueue->Queue[pQueue->rear];
	pQueue->Queue[pQueue->rear] = 0;
	pQueue->rear = (pQueue->rear-1+pQueue->Queue_size) % pQueue->Queue_size;

	pQueue->Queue[pQueue->front] = tmp;
	pQueue->front = (pQueue->front-1+pQueue->Queue_size) % pQueue->Queue_size;
}

int findidx(Queue *pQueue, int data)
{
	for(int cnt = 0; cnt < pQueue->Queue_size; ++cnt)
	{
		if(pQueue->Queue[cnt] == data)
			return cnt;
	}
}