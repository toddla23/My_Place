#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct node
{
    int key, hight;
    node* right, *left;

}node;

void initNode(node* n)
{
    n->right = NULL;
    n->left = NULL;
    n->hight = 1;
}

void insertNode(node *T, int newKey)
{

    stack<node*> stack;

    node *n = new node;
    node *p = T;
    node *q = NULL;     //p가 선봉대 q가 후발
   
   while(p != NULL)
   {
        if(newKey == p->key)
            return;
        
        q = p;
        stack.push(q);

        if(newKey < p.key)
            p = p->left;
        else
            p = p->right;
   }

    node *newNode = new node;
    newNode->key = newKey;

    if(T == NULL)
        T = newNode;
    else if(newKey < q->key)
        q->left = newNode;
    else
        q->right = newNode;
    
    while(!stack.empty())
    {
        q = stack.top();
        stack.pop();

        q->hight = 1+ max(q->left->hight, q->right->hight);
        
    }
    
}


int main(void)
{
    

    node * root = new node;

    return 0;
}