#include <iostream>
#include <vector>
#include <cmath>
#include <stack>



using namespace std;

typedef struct node
{
    vector<int> K;
    vector<node*> P;

    int n;

}node;


node* getNode();
bool searchPath(node* T, int m, int key, stack<node*> &s);
void insertKey(node* T, int m,node* x, node* y, int newKey);
node* splitNode(node* T, int m, node* x, node* y, int& newKey);

node* getNode()
{
    node* newnode = new node;
    newnode->K.push_back(NULL);
    newnode->n = 0;
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

    bool found = searchPath(T, m, newKey, s);
    if(found == true)
        return;
    
    bool finished = false;

    node* x = s.top();
    s.pop();
    node* y = NULL;

    do
    {
        if(x->n < m - 1)
        {
            insertKey(T, m, x, y, newKey);
            finished = true;
        }
        else
        {
            y = splitNode(T, m, x, y, newKey);
            if(!s.empty())
            {    
                x = s.top();
                s.pop();
            }
            else
            {
                T = getNode();
                T->K[1] = newKey;
                T->P[0] = x;
                T->P[1] = y;
                finished = true;
            }

        }

    }while(!finished);

}

bool searchPath(node* T, int m, int key, stack<node*> &s)
{
    /* if(s.empty())
        s = stack<node*> s; */
        
    node* x = T;
    
    bool pass;
    do
    {
        int i = 1;
        while(i <= x->n && key > x->K[i])
            i = i+1;
        
        s.push(x);
        if(i <= x->n && key == x->K[i-1])
            return true;

        x = x->P[i-1];

        pass = x != NULL;
    }while(pass);

    return false;
}

void insertKey(node* T, int m, node* x, node* y, int newKey)
{
    int i = x->n;

    while(i >= 1 && newKey < x->K[i])
    {
        x->K[i+1] = x->K[i];
        x->P[i+1] = x->P[i];
        i = i - 1;
    }

    x->K[i+1] = newKey; //바꿈 다시 바뀌면 문제 있는거임
    x->P[i] = y;
    x->n = x->n+1;
}

node* splitNode(node* T, int m, node* x, node* y, int &newKey)
{
    node* tempNode = new node;
    tempNode->K = x->K;
    tempNode->n = x->n;
    tempNode->P = x->P;

    insertKey(T, m, tempNode, y, newKey);

    int tmp = (tempNode->n / 2) + 1;
    int centerkey = tempNode->K[tmp]; // 중앙값 찾는거임

    newKey = centerkey;
    
    x->n = 0;
    int i = 1;
    while(tempNode->K[i] < centerkey)
    {
        x->K[i] = tempNode->K[i];
        x->P[i-1] = tempNode->P[i-1];
        i = i + 1;
        x->n = x->n + 1;
    }
    x->P[i-1] = tempNode->P[i-1];

    node* newNode = getNode();

    i = i + 1;
    while (i <= tempNode->n)
    {
        newNode->K[newNode->n + 1] = tempNode->K[i];
        newNode->P[newNode->n] = tempNode->P[i - 1];
        i = i + 1;
        newNode->n = newNode->n + 1;

    }
    newNode->P[newNode->n] = tempNode->P[i-1];

    delete tempNode;

    return newNode;
}

void deletekey(node* T, int m, node* x, int oldKey);
int bestSibling(node* T, int m, node* x, node* y);
void redistributeKeys(node* T, int m, node* x, node* y, int bestSibling);
void mergeNode(node* T, int m, node* x, node* y, int bestSibling);

int getheight(node* T)
{
    int height = 1;
    while(T->P.size() != 0)
    {
        T = T->P[0];
        height++;
    }
}


void deleteBT(node* T, int m, int oldKey)
{
    stack<node*> s;
    bool found = searchPath(T, m, oldKey, s);

    if(found == false)
        return;

    node* x = s.top();
    s.pop();

    int i = 0;
    if(s.size() < getheight(T)) // old key가 단말노드에 없음
    {
        node* internalNode = x; 

        s.push(x);

        for(int n = 0; n < T->n; n++)
            if(T->K[n] == oldKey)
            {
                i = n;
                break;
            }

        bool found2 = searchPath(x->P[i], m, x->K[i], s);

        x = s.top();
        s.pop();

        int temp = internalNode->K[i];
        internalNode->K[i] = x->K[1];
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