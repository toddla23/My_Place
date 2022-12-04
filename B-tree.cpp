#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <fstream>


using namespace std;

typedef struct node
{
    vector<int> K;
    vector<node*> P;

    int n;

}node;

void printTree(node* T);

node* getNode();
bool searchPath(node* T, int m, int key, stack<node*> &s);
void insertKey(node* T, int m,node* x, node* y, int newKey);
node* splitNode(node* T, int m, node* x, node* y, int& newKey);

node* getNode()
{
    node* newnode = new node;

    

    for(int i = 0; i < 4; i ++)
    {
        newnode->K.push_back(-1);
        newnode->P.push_back(NULL);
    }
    newnode->n = 0;
}

node* insertBT(node* T, int m, int newKey)
{
    if(T == NULL)
    {
        T = getNode();
        T->K[1] = newKey;
        T->n = 1;
        return T;
    }
    
    stack<node*> s;

    bool found = searchPath(T, m, newKey, s);

    if(found == true)
        return T;
    
    bool finished = false;

    node* x = s.top();
    s.pop();
    node* y = NULL;
    
    do
    {
        if(x->n < m - 1)
        {
/*             cout << "insert node :" << x->K[1] << endl;
            
            if(T->P[1] != NULL && newKey == 403)
            {
                cout << "x key :" <<T->P[1]->K[1] << endl;
                cout << "x.n :" << T->P[1]->n << endl;
                cout << "y key :" << y->K[1] << endl;
            } */

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
                T->n = T->n + 1;
                finished = true;

            }

        }
/*         if(T->P[1] != NULL && newKey == 403)
        {
            cout << "x key :" <<T->P[1]->K[1] << endl;
            cout << "x.n :" << T->P[1]->n << endl;
            cout << "y key :" << y->K[1] << endl;
        } */

    }while(!finished);
    

    return T;
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
        if(i <= x->n && key == x->K[i])
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

    x->K[i + 1] = newKey; //바꿈 다시 바뀌면 문제 있는거임
    x->P[i + 1] = y;        // 여기도 바꿈 다시바뀌면 문제있는거
    x->n = x->n+1;
}

node* splitNode(node* T, int m, node* x, node* y, int &newKey)
{
    node* tempNode = new node;
    tempNode->K = x->K;
    tempNode->K.push_back(-1);
    tempNode->n = x->n;
    tempNode->P = x->P;
    tempNode->P.push_back(NULL);

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

void deleteKey(node* T, int m, node* x, int oldKey);
int bestSibling(node* T, int m, node* x, node* y);
void redistributeKeys(node* T, int m, node* x, node* y, int bestSibling);
void mergeNode(node* T, int m, node* x, node* y, int bestSibling);
bool isRoot(node* T);

int getheight(node* T)
{
    
    int height = 1;
    while(T->P[0] != NULL)
    {
        T = T->P[0];
        height++;
    }
    return height;
}


node* deleteBT(node* T, int m, int oldKey)
{
    stack<node*> s;
    bool found = searchPath(T, m, oldKey, s);

    if(found == false)
        return T;

    node* x = s.top();
    s.pop();

    
    
    if(s.size() + 1 < getheight(T)) // old key를 내부노드에서 발견
    {
        node* internalNode = x; 

        s.push(x);
        int i = 0;
        for(i = 1; i < x->n; i ++)
        {
            if(x->K[i] == oldKey)
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

    if(x != NULL && y != NULL)
    {
        cout << "x key: " << x->K[1] << endl;
        cout << "y key: " << y->K[1] << endl;
    }
    do
    {
        if(x == T || x->n >= round(m / 2) - 1)
            finished = true;
        else
        {
            int bestsibling = bestSibling(T, m, x, y);
            if(y->P[bestsibling]->n > round(m/2) - 1)
            {
                redistributeKeys(T, m, x, y, bestsibling);
                finished = true;

            }
            else
            {
                mergeNode(T, m, x, y, bestsibling);
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

    if(y != NULL && y->n == 0)
    {
        T = y->P[0];
        delete x;
    }

    return T;
}

void deleteKey(node* T, int m, node* x, int oldKey)
{
    int i = 1;
    while(oldKey > x->K[i])
        i = i + 1;
    
    while (i <= x->n)
    {
        x->K[i] = x->K[i+1];
        x->P[i] = x->P[i+1];
        i = i + 1;
    }
    x->n = x->n -1;

}

int bestSibling(node* T, int m, node* x, node* y)
{
    int i = 0;

    while(y->P[i] != x)
        i = i + 1;
    int bestsibling;

    if(i == 0)
        bestsibling = i + 1;
    else if(i == y->n)
        bestsibling = i - 1;
    else if(y->P[i-1]->n >= y->P[i+1]->n)
        bestsibling = i - 1;
    else
        bestsibling = i + 1;

    return bestsibling;
}


void redistributeKeys(node* T, int m, node* x, node* y, int bestSibling)
{
    int i = 0;

    while(y->P[i] != x)
        i = i + 1;
    
    node* bestNode = y->P[bestSibling];

    if(bestSibling < i)
    {
        int lastKey = bestNode->K[bestNode->n];
        insertKey(T, m, x, NULL, y->K[i]);
        x->P[1] = x->P[0];
        x->P[0] = bestNode->P[bestNode->n];
        bestNode->P[bestNode->n] = NULL;

        deleteKey(T, m, bestNode, lastKey);
        y->K[i] = lastKey;
    }
    else
    {
        int firstKey = bestNode->K[1];
        insertKey(T, m, x, NULL, y->K[i+1]);
        deleteKey(T, m, bestNode, firstKey);
        y->K[i+1] = firstKey;
    }

}

void mergeNode(node* T, int m, node* x, node* y, int bestsibling)
{
    int i = 0;
    while(y->P[i] != x)
        i = i + 1;
    
    node* bestNode = y->P[bestsibling];


    if(bestsibling > i)
    {

        node* tmpnode = x;
        x = bestNode;
        bestNode = tmpnode;

        int tmp = i;
        i = bestsibling;
        bestsibling = tmp;
    }

    bestNode->K[bestNode->n + 1] = y->K[i];
    bestNode->n = bestNode->n + 1;

    int j = 1;

    while(j <= x->n)
    {
        bestNode->K[bestNode->n + 1] = x->K[j];
        bestNode->P[bestNode->n] = x->P[j - 1];
        bestNode->n = bestNode->n + 1;

        j = j + 1;

    }

    bestNode->P[bestNode->n] = x->P[x->n];
    deleteKey(T, m, y, y->K[i]);
    delete x;

}



int asd = 0;
void printTree(node* T)
{

    if(T != NULL)
    {
        int i = 0;
        printTree(T->P[i]);
        for(i = 1; i < T->n + 1; i++)
        {
/*             for(int j = 1; j < T->n + 1; j++)
            {
                cout << "[" << T->K[j] << "] ";
            }
            cout <<endl; */

            cout << "[" <<T->K[i]  << "]";

            printTree(T->P[i]);
        }

    }
}




int main(void)
{
    
    ifstream ifs("BT-input.txt"); // 여기에 파일 경로 넣어주세요

    node* root = NULL;
    char com;
    int k;

    while(!ifs.eof())
    {        
        ifs >> com >> k ;

        if(com == 'i')
        {
            root = insertBT(root, 3, k);
            printTree(root);
            cout << endl;
        }
        else if(com == 'd')
        {
            root = deleteBT(root, 3, k);
            printTree(root);
            cout << endl;
        }
        
    }

/* 
    while(com != 'q')
    {
        cin >> com >> k;
        if(com == 'i')
        {
            root = insertBT(root, 3, k);
            printTree(root);
            cout << endl;
        }
        else if(com == 'd')
        {
            root = deleteBT(root, 3, k);
            printTree(root);
            cout << endl;
        }
    } */


    

}