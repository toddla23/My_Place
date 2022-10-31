#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

typedef struct node
{
    int key;
    int height;
    int bf;
    struct node* left, *right;

}node;

void checkbalande(node* T, int newKey, string rotateType, node* p, node* q)
{

}

void rotateTree(node* T, string rotateTypq, node* p, node* q)
{

}

node* getAVLNode()
{
    node* n = new node;
    
    return n;
}

// rotate 함수 구해야함
void rotateLL(node * x)
{
    node* temp1 = x->left;
    node* temp2 = x->right;

    int n = x->key;
    x->key = x->left->key;

    x->left = x->left->left;
    temp1->left = temp1->right;
    x->right = temp1;
    x->right->right = temp2;
}

void rotateRR(node * x)
{
    node* temp1 = x->left;
    node* temp2 = x->right;

    int n = x->key;
    x->key = x->right->key;

    x->right = x->right->right;
    temp2->right = temp2->left;
    x->left = temp2;
    x->left->left = temp1;
}

void insertBST(node *T, int newKey)
{
    node* p = T;
    node* q = NULL;
    node* x = NULL;
    node* f = NULL;

    stack<node*> s;

    while(p != NULL)
    {
        if(newKey = p->key)
            return;
        
        q = p;
        s.push(p);

        if(newKey < p->key)
            p = p->left;
        else
            p = p->right;
    }

    node* y = getAVLNode();

    y->key = newKey;

    if(T == NULL)
        T = y;
    else if(newKey < q->key)
        q->left = y;
    else
        q->right = y;

    while(!s.empty())    
    {
        q = s.top();
        s.pop();
        q->height = 1 + max(q->left->height, q->right->height);

        q->bf = q->left->height - q->right->height;

        if(1 < q->bf || q->bf < -1)
        {
            if(x ==NULL)
            {
                x = q;
                f = s.top();

            }
        }
    }

    if(x == NULL)
        return;

    if(1 < x->bf)
    {
        if(x->left->bf < 0)
            rotateLR(x);
        else 
            rotateLL(x);
    }
    else
        if(x->right->bf > 0)
            rotateRL(x);
        else
            rotateRR(x);

}

int main(void)
{


    return 0;
}