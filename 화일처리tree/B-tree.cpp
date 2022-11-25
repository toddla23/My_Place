#include <iostream>
#include <vector>
#include <stack>


using namespace std;

typedef struct node
{
    vector<int> K;
    vector<node*> P;

    int n;

}node;

node* getNode

bool searchPath(node* T, int m, int key, stack &s)
{
    if(s == NULL)s = stack<node*> s;
    node* x = T;
    
    do
    {
        int i = 1
        while(i <= x.n && key> x->K[i])
            i = i+1;
        
        if(i <= x.n && key == x->K[i])
            return true;

        s.push(x);
    } while ((x = x.P[i-1]) != NULL);

    return false;
}

void insertKey(node* T, int m,node* x, node* y, int newKey)
{
    int i = x.n;

    while(i >= 1 && newKey < x->K[i])
    {
        x->K[i+1] = x->K[i];
        x->P[i+1] = x->P[i];
        i = i - 1;
    }

    x.K[i] = newKey;
    x->P[i] = y;
    x->n = x->n+1
}

int splitNode(node* T, int m, node* x, node* y, int newKey)
{
    node* tempNode = x;
    insertKey(T, m, tempNode, y, newKey);

    //int centerkey = center key of tempnode // 중앙값 찾는거임
    int centerkey = 0;

    x->n = 0;
    i = 1;
    while(tempNode->K[i] < centerkey)
    {
        x->K[i] = tempNode.k[i];
        x.P[i-1] = tempNode.P[i-1];
        i = i + 1;
        x->n = x->n + 1;
    }
    x->P[i-1] = tempNode->P[i-1];

    node* newNode = getNode();

    i = i + 1;
    while (i <= tempNode.n)
    {
        newNode->K[i] = tempNode.k[i];
        newNode->P[i-1] = tempNode.p[i-1];
        i = i + 1;
        newNode->n = newNode->n + 1;

    }
    newNode->P[i-1] = tempNode->P[i-1];

    return centerkey, newnode
}

void insertBT(node* T, int m, int newKey)
{
    if(T == NULL)
    {
        T = getNode();
        T->K.push_back(newKey);
        T->n = 1;
        return;
    }
    
    stack<node*> s;

    bool found = searchPath(T, m, newKey, NULL);
    if(found == true)
        return;
    
    bool finished = false;

    node* x = stack.top();
    stack.pop();
    y = null;

    do
    {
        if(x.n < m - 1)
        {
            insertKey(T, m, x, y, newKey);
            finished = true;
        }
        else
        {
            newKey, y = splitNode(T, m, x, y, newKey);
            if(!s.empty())
            {    x = s.top(x);
                s.pop();
            }
            else
            {
                T = getNode();
                T.k[1] = newKey;
                T.p[0] = x;
                T.p[1] = y;
                finished = true;
            }

        }

    }while(!finished);

}

deleteBT(node* T, int m, int oldKey)
{
    stack<node*> s;
    bool found, s = searchPath(T, m, oldKey, NULL);

    if(fount == false)
        return;

    x = s.top();
    s.pop();

    if(oldKey is not in terminal node)
    {
        node* internalNode = x;
        i = 
    }


}


int main(void)
{
    node* root = new node;

    root->K.push_back(1);

    cout << root->K[0];


}