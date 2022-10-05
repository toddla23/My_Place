#include <stack>
#include <iostream>
#include <vector>

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

void insertNode(node *root, int key)
{

    stack<int> s;

    node* n = new node;
    node * p = root;
    
}


int main(void)
{
    

    node * root = new node;

    return 0;
}