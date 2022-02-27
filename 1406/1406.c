#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node {
	char ch;
	struct Node* prev;
	struct Node* next;
} Node;

char str[100005], cmd[2];

Node *newNode()
{
    Node *ret = malloc(sizeof(Node));
    memset(ret, 0, sizeof(Node));

    return ret;
}

int main(void) {
	Node* head;
	int t;
	scanf("%s", str);

	int len = strlen(str);

	Node* tmp = newNode();
	tmp->ch = str[0];

	head = tmp;
	Node* cur = tmp;

	for (int i = 1; i <= len; i++)
    {
		tmp = newNode();
		tmp->ch = str[i];
		tmp->prev = cur;
		cur->next = tmp;
		cur = tmp;
	}
	
	scanf("%d\n", &t);
	while(t--)
    {
		scanf("%s", cmd);
		if(cmd[0] == 'P')
        {
			scanf("%s", cmd);

			tmp = newNode();
			tmp->ch = cmd[0];
			tmp->prev = cur->prev;
			tmp->next = cur;
			
			if(cur->prev)
				cur->prev->next = tmp;
			else head = tmp;

			cur->prev = tmp;
		}
		else if(cmd[0] == 'L')
        {
			if(cur->prev)
				cur = cur->prev;
		}
		else if(cmd[0] == 'D')
        {
			if(cur->next)
				cur = cur->next;
		}
		else if(cmd[0] == 'B')
        {
			if(!(cur->prev))
				continue;

			if(cur->prev->prev)
            {
				cur->prev->prev->next = cur;
				cur->prev = cur->prev->prev;
			}
			else
            {
				cur->prev = NULL;
				head = cur;
			}
		}
	}

	for (Node* p = head; p->ch; p = p->next)
		printf("%c", p->ch);
	
	return 0;
}