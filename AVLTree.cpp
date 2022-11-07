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

void updateNode(node * q)
{
    if(q->left == NULL && q->right != NULL)// bf, height 업데이트
    {
        q->height = 1 + q->right->height;
        q->bf = -(q->right->height + 1);   // 왼쪽이 NULL 이니까 오른쪽 높이 +1가 bf
    }
    else if (q->left != NULL && q->right == NULL)
    {
        q->height = 1 + q->left->height;
        q->bf = q->left->height + 1;      //오른쪽이 NULL 이니까 왼쪽높이 + 1이 bf
    }
    else if(q->left == NULL && q->right == NULL)
    {
        q->height = 0;
        q->bf = 0;
    }
    else
    {
        q->height = 1 + max(q->left->height, q->right->height);
       q->bf = q->left->height - q->right->height; //이건뭐...
    }
}

void inorder(node* T)
{
    if(T != NULL)
    {
        inorder(T->left);
        cout <<"("<< T->key << ", " << T->bf << ", " << T->height<< ")" ;
        inorder(T->right);
    }
}

node* getAVLNode(int newkey)
{
    node* n = new node;
    n->left = n->right = NULL;
    n->bf = 0;
    n->key = newkey;
    n->height = 0;
    
    return n;
}

// rotate 함수 구해야함
void rotateLL(node * x)     // 완성
{
    node* temp1 = x->left;
    node* temp2 = x->right;

    x->left = x->left->left;
    temp1->left = temp1->right;
    temp1->right = x->right;
    x->right = temp1;

    int n = x->key;
    x->key = temp1->key;
    temp1->key = n;
    
    updateNode(x->right);
    updateNode(x);
}

void rotateRR(node* x)     // 완성
{
    node* temp1 = x->left;
    node* temp2 = x->right;

    x->right = x->right->right;
    temp2->right = temp2->left;
    temp2->left = x->left;
    x->left = temp2;

    int n = x->key;
    x->key = temp2->key;
    temp2->key = n;

    updateNode(x->left);
    updateNode(x);
}

void rotateLR(node * x)     //미완
{
    rotateRR(x->left);
    rotateLL(x);
}

void rotateRL(node * x)     //미완
{
    rotateLL(x->right);
    rotateRR(x);
}

node* insertAVL(node *T, int newKey)
{
    node* p = T;
    node* q = NULL;
    node* x = NULL;
    node* f = NULL;


    stack<node*> s;

    while(p != NULL) // 넣을 자리 찾고 지나온거 전부 스택에 저장
    {
        if(newKey == p->key)
        {
            cout << "i <" <<newKey << "> : The key alreadt exists" <<endl;
            inorder(T);
            cout <<endl;
            return T;
        }
        
        q = p;
        s.push(p);

        if(newKey < p->key)
            p = p->left;
        else
            p = p->right;
    }

    node* y = getAVLNode(newKey); // 새 노드 만들기 bf, height = 0

    if(T == NULL) //넣을 자리에 넣기
        T = y;
    else if(newKey < q->key)
        q->left = y;
    else
        q->right = y;


    while(!s.empty())    // 넣었느니까 지나온거 업데이트
    {
        q = s.top();
        s.pop();
        
        updateNode(q);

        if(1 < q->bf || q->bf < -1)
        {
            if(x == NULL)
            {
                x = q;
                cout << x->key << endl;
    
                if(!s.empty())
                    f = s.top();

            }
        }
    }

    //inorder(T); cout << endl;
    
    if(x == NULL)
    {
        cout << "NO ";
        inorder(T);
        cout << endl;
        return T;
    }

    if(1 < x->bf) //rotate도 뭐 그냥 적당히 하면 가능...
    {
        if(x->left->bf < 0)
        {
            rotateLR(x);
            cout << "LR ";
            inorder(T);
            cout << endl;
        }

        else 
        {
            rotateLL(x);
            cout << "LL ";
            inorder(T);
            cout << endl;
        }
    }
    else
    {
        if(x->right->bf > 0)
        {
            rotateRL(x);
            cout << "RL ";
            inorder(T);
            cout << endl;
        }
        else
        {
            rotateRR(x);
            cout << "RR ";
            inorder(T);
            cout << endl;
        }
    }

    return T;
}

node* deleteAVL(node* T, int deleteKey)
{
    node* p = T;
    node* q = NULL;
    node* x = NULL;
    node* f = NULL;

    stack<node*> s;
    
    while(p != NULL && deleteKey != p->key)
    {
        q = p;
        s.push(q);

        if(deleteKey < p->key)
            p = p->left;
        else
            p = p->right;
    }

    if(p == NULL)
    {
        cout << "d <" << deleteKey << "> : The key does not exist";
        return T;
    }
    node* tempnode = NULL;
    if(p->left != NULL && p->right != NULL)
    {
        s.push(p);
        tempnode = p;

        if(p->left->height <= p->right->height)
        {
            p = p->right;
            while(p->left != NULL)
            {
                s.push(p);
                p = p->left;

            }
        }
        else
        {
            p = p->left;
            while(p->right != NULL)
            {
                s.push(p);
                p = p->right;

            }
        }
        tempnode->key = p->key;
        q = s.top();

    }

    if(q->left == NULL && p->right == NULL)
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
            else if(q->left == p)
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

    while(!s.empty())
    {
        q = s.top();
        s.pop();
        q->height = max(q->left->height, q->right->height);
        q->bf = q->left->height - q->right->height;

        if(1 < q->bf || q->bf < -1)
        {
            if(x == NULL)
            {
                x = q;
                f = s.top();

            }

        }
    }

    if(x == NULL)
        return T;

    if(1 < x->bf)
    {
        if(x->left->bf < 0)
            rotateLR(x);
        else
            rotateLL(x);
    }
    else
    {
        if(x->right->bf > 0)
            rotateRL(x);
        else
            rotateRR(x);
    }

    return T;

}


int main(void)
{

    node* root = NULL;

    int n;
    char i;
    
    do
    {
        cin >> i >> n ;
        if(i == 'i')
            root = insertAVL(root, n);
        else if(i == 'd')
            root = deleteAVL(root, n);
        else
            break;

    } while(root != NULL);


    return 0;
}