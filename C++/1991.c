#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int preorder(char *Node, int idx);
int inorder(char *Node, int idx);
int postorder(char *Node, int idx);

int main(void)
{
	char Node[30][2];
	char P, c1, c2;
	int n;

	scanf("%d", &n);
	getchar();

	for(int i = 0; i < n; ++i)
	{
		scanf("%c %c %c", &P, &c1, &c2);
		Node[2*(P-'A'+1)] = c1;
		Node[2*(P-'A'+1) + 1] = c1;
	}


	return 0;
}

int preorder(char *Node, int idx)
{

}

int inorder(char *Node, int idx)
{

}

int postorder(char *Node, int idx)
{

}