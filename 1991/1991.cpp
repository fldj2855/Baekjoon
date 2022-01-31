#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

typedef struct Node {
    char key;
    struct Node *lchild;
    struct Node *rchild;
}Node;

class BinTree{
private:
    Node *Root;
public:
    BinTree() {
        this->Root = genNode();
        this->Root->key = 'A';
    };
    ~BinTree() {};

    Node *getRoot()
    {
        return this->Root;
    }
    Node *genNode()
    {
        Node *newNode = new Node;
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

    void setNode(char RootK, char LK, char RK)
    {
        
        Node *N = findNode(this->Root, RootK);


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

        cout << R->key;
        Preorder(R->lchild);
        Preorder(R->rchild);
    }

    void Inorder(Node *R)
    {
        if(R == NULL)
            return;

        Inorder(R->lchild);
        cout << R->key;
        Inorder(R->rchild);
    }

    void Postorder(Node *R)
    {
        if(R == NULL)
            return;

        Postorder(R->lchild);
        Postorder(R->rchild);
        cout << R->key;
    }
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    BinTree *BT = new BinTree();

    char a, b, c;
    int N;
    cin >> N;

    for(int i = 0; i < N; ++i)
    {
        cin >> a >> b >> c;
        BT->setNode(a, b, c);
    }

    BT->Preorder(BT->getRoot());
    cout << endl;
    BT->Inorder(BT->getRoot());
    cout << endl;
    BT->Postorder(BT->getRoot());

    BT->delTree(BT->getRoot());
    delete BT;

    return 0;
}