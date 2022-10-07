#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct node
{
    int key, height;
    struct node *right, *left;

}node;

void initNode(node* n)
{
    n->right = NULL;
    n->left = NULL;
    n->height = 0;
}

void inorder(node* T)
{
    if(T != NULL)
    {
        inorder(T->left);
        cout << "["<< T->key << ", " <<T->height << "]";
        inorder(T->right);
    }
}


node* insertBST(node *T, int newKey)
{
    stack<node*> stack;

    node *p = T;
    node *q = NULL;     //p가 선봉대 q가 후발

    while(p != NULL)
    {
        if(newKey == p->key)
        {
            cout << "i <" << newKey <<"> : The key already exists" << endl;
            return T;
        }
        q = p;
        stack.push(q);

        if(newKey < p->key)
            p = p->left;
        else
            p = p->right;
    }
    

    node *newNode = new node;
    //newNode->left = newNode->right = NULL;
    initNode(newNode);
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

        cout << q->key << ", ";

        if(q->left == NULL && q->right != NULL)
            q->height = 1 + q->right->height;
        else if (q->left != NULL && q->right == NULL)
            q->height = 1 + q->left->height;
        else
            q->height = 1 + max(q->left->height, q->right->height);
        
    }

    inorder(T);
    cout << endl;
    
    return T;
}

node* deleteBST(node *T, int deleteKey)
{
    node *p = T;
    node *q = NULL;
    stack<node*> stack;

    while(p != NULL && deleteKey != p->key)
    {
        q = p;
        stack.push(q);
        
        if(deleteKey < p->key)
            p = p->left;
        else
            p = p->right;
    }

    if(p == NULL)
    {
        cout << "d <" << deleteKey << "> : The key does not exist" << endl;
        return T;
    }

    if(p->left != NULL && p->right != NULL)
    {
        stack.push(p);
        node *tempNode = p;
        
        if(p->left->height <= p->right->height)
        {
            p = p->right;

            while(p->left != NULL)
            {
                stack.push(p);
                p = p->left;
            }
        }
        else
        {
            p = p->left;

            while (p->right != NULL)
            {
                stack.push(p);
                p = p->right;
            }   
        }

        tempNode->key = p->key;
        q = stack.top();
    }

    if(p->left == NULL && p->right == NULL)
    {
        if(q == NULL)
            T = NULL;
        else if(q->left == p)
            q->left = NULL;
        else
            q->right = NULL;
    }
    else
    {
        if(p->left != NULL)
        {
            if(q == NULL)
                T = T->left;
            else if (q->left == p)
                q->left = p->left;
            else
                q->right = p->left;
        }
        else
        {
            if(q == NULL)
                T = T->right;
            else if(q->left == p)
                q->left = p->right;
            else
                q->right = p->right;
        }
    }

    delete p;

    while(!stack.empty())
    {
        q = stack.top();
        stack.pop();
        
        cout << q->key << ", ";

        if(q->left == NULL && q->right != NULL)
            q->height = 1 + q->right->height;
        else if (q->left != NULL && q->right == NULL)
            q->height = 1 + q->left->height;
        else if (q->left == NULL && q->right == NULL)
            q->height = 0;
        else
            q->height = 1 + max(q->left->height, q->right->height);
    }

    inorder(T);
    cout << endl;

    return T;
}

int main(void)
{
    node * T = NULL;
    char a;
    int n;

    while(a != 'q')
    {
        cin >> a >> n;
        if(a == 'i')
            T = insertBST(T, n);
        else if(a == 'd')
            T = deleteBST(T, n);
        else
            cout << "Wrong input" << endl;
        cout << T->key << ", " << T->height <<endl;
    }

    return 0;
}