#include <iostream>
#include <vector>
#include <stack>
#include <cmath>


using namespace std;

typedef struct node
{
    vector<int> K;
    vector<node*> P;

    int n;

}node;


node* getNode
bool searchPath(node* T, int m, int key, stack &s);
void insertKey(node* T, int m,node* x, node* y, int newKey);
int splitNode(node* T, int m, node* x, node* y, int newKey);

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

void deletekey(node* T, int m, node* x, int oldKey);
int bestSibling(node* T, int m, node* x, node* y);
void redistributeKeys(node* T, int m, node* x, node* y, int bestSibling);
void mergeNode(node* T, int m, node* x, node* y, int bestSibling);


void deleteBT(node* T, int m, int oldKey)
{
    stack<node*> s;
    bool found = searchPath(T, m, oldKey, s);

    if(found == false)
        return;

    node* x = s.top();
    s.pop();

    if(s.size() < T.height()) // old key가 단말노드에 없음
    {
        int i;
        node* internalNode = x;

        for(int n = 0; n < T.n; n++)
            if(T.k[n] == oldKey)
            {
                i = n;
                break;
            }

        bool found2 = searchPath(x->P[i], m, x->K[i], s);

        x = s.top();
        s.pop();
        node* temp = internalNode->K[i];
        internalNode.K[i] = x->K[1];
        x->K[1] = temp;
        
    }
    bool finished = false;
    deleteKey(T, m, x, oldKey);
    node* y;

    if(!s.empty())
    {
        y = s.top();
        s.pop();
    }

    do
    {
        if(isRoot(x) || x->n >= round(m / 2) - 1)
            finished = true;
        else
        {
            int bestSibling = bestSibling(T, m, x, y);

            if(y.P[bestSibling].n > round(m/2) - 1)
            {
                redistributeKeys(T, m, x, y, bestSibling);
                finished = true;

            }
            else
            {
                mergeNode(T, m, x, y, bestSibling);
                x = y;
                if(!s.empty())
                {
                    y = s.top();
                    s.pop();
                }
                else
                    finished = true;
            }

        }

    }while(!finished);

    if(y->n == 0)
    {
        T = y->P[0];
        discard y node;
    }

}

void deletekey(node* T, int m, node* x, int oldKey)
{
    i = 1;
    while(oldKey > x->K[i])
        i = i + 1;
    
    while (i <= x.n)
    {
        x.K[i] = x->K[i+1];
        x->P[i] = x->P[i+1];
        i = i + 1;
    }
    x->n = x->n -1;

}

int bestSibling(node* T, int m, node* x, node* y);
{
    int i = 0;
    while(y->P[i] != x)
        i = i + 1;
    int bestSibling;

    if(i = 0)
        bestSibling = i + 1;
    else if(i == y->n)
        bestSibling = i - 1;
    else if(y->P[i-1].n >= y.P[i+1].n)
        bestSibling = i - 1;
    else
        bestSibling = i + 1

    return bestSibling;
}

void redistributeKeys(node* T, int m, node* x, node* y, int bestSibling)
{
    int i = 0;
    while(y->P[i] != x)
        i = i + 1;
    
    node* bestNode = y->P[bestSibling];

    if(bestSibling < i)
    {
        int lastKey = bestNode.K[bestNode.n];
        insertKey(T, m, null, y->K[i]);
        deletekey(T, m, bestNode, lastKey);
        y->K[i] = lastKey;
    }
    else
    {
        int firstKey = bestNode->K[1];
        insertKey(T, m, x, null, y->K[i+1]);
        deletekey(T, m, bestNode, firstKey);
        y->K[i+1] = firstKey;
    }

}

void mergeNode(node* T, int m, node* x, node* y, int bestSibling)
{
    int i = 0;
    while(y.p[i] != x)
        i = i + 1;
    
    node* bestNode = y->P[bestSibling];

    if(bestSibling > i)
    {
        swap(bestSibling, i);
        swap(bestNode, x);
    }

    besetNode->K[bestNode->n + 1] = y->K[i];
    bestNode->n = bestNode->n + 1;

    int j = 1;

    while(j <= x->n)
    {
        bestNode->k[bestNode->n + 1] = x->K[j];
        bestNode->p[bestNode->n] = x->P[j - 1];
        bestNode->n = bestNode->n + 1;

    }

    bestNode->P[bestNode->n] = x->P[x.n];
    deletekey(T, m, y, y->K[i]);
    discard x node;

}




int main(void)
{
    node* root = new node;

    root->K.push_back(1);

    cout << root->K[0];


}