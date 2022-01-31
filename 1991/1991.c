#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
    char key;
    struct Node *lchild;
    struct Node *rchild;
}Node;

Node *genNode();
Node *findNode(Node *, char);
Node *setNode(char, char, char);
void delTree(Node *);

void Preorder(Node *);
void Inorder(Node *);
void Postorder(Node *);

Node *RootNode = NULL;

int main(void)
{
    int N;
    char a, b, c;
    scanf("%d", &N);
    getchar();

    RootNode = genNode();
    RootNode->key = 'A';

    for(int i = 0 ; i < N; ++i)
    {
        scanf("%c %c %c", &a, &b, &c);
        getchar();
        setNode(a, b, c);
    }

    Preorder(RootNode);
    printf("\n");
    Inorder(RootNode);
    printf("\n");
    Postorder(RootNode);

    delTree(RootNode);
}

Node *genNode(){

    Node *newNode = (Node *)malloc(sizeof(Node));
    if(!newNode)
    {
        printf("Memory Error");
        exit(-1);
    }

    memset(newNode, 0, sizeof(Node));

    return newNode;
}

Node *findNode(Node *N, char F)
{
    if(N == NULL)
        return NULL;

    if(N->key == F)
        return N;
    
    Node *RetNode = NULL;

    RetNode = findNode(N->lchild, F);
    if(RetNode)
        return RetNode;

    RetNode = findNode(N->rchild, F);
    if(RetNode)
        return RetNode;

    return NULL;
}

Node *setNode(char RootK, char LK, char RK)
{
    Node *N = findNode(RootNode, RootK);
    if(LK != '.')
    {
        N->lchild = genNode();
        N->lchild->key = LK;   
    }

    if(RK != '.')
    {
        N->rchild = genNode();
        N->rchild->key = RK;
    }
}

void delTree(Node *R)
{
    if(R == NULL)
        return;
    
    delTree(R->lchild);
    delTree(R->rchild);
    free(R);
    return;
}

void Preorder(Node *R)
{
    if(R == NULL)
        return;

    printf("%c", R->key);
    Preorder(R->lchild);
    Preorder(R->rchild);
}

void Inorder(Node *R)
{
    if(R == NULL)
        return;

    Inorder(R->lchild);
    printf("%c", R->key);
    Inorder(R->rchild);
}

void Postorder(Node *R)
{
    if(R == NULL)
        return;

    Postorder(R->lchild);
    Postorder(R->rchild);
    printf("%c", R->key);
}
