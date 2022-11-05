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
    temp2->right = x->right;
    x->right = temp1;
    int n = x->key;
    x->key = temp1->key;
    temp1->key = n;
}

void rotateRR(node * x)     // 완성
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
}

void rotateLR(node * x)     //미완
{
    node* temp1 = x->left;
    node* temp2 = x->left->right;
    node* temp3 = x->right;

    int n = x->key;
    x->key = x->left->key;
    x->left->key = n;

    x->left->right = NULL;
    x->right = temp2;
    x->right->right = x->right->left;
    
}

void rotateRL(node * x)     //미완
{
    
}


void insertAVL(node *T, int newKey)
{
    node* p = T;
    node* q = NULL;
    node* x = NULL;
    node* f = NULL;

    stack<node*> s;

    while(p != NULL) // 넣을 자리 찾고 지나온거 전부 스택에 저장
    {
        if(newKey == p->key)
            return;
        
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
        q->height = 1 + max(q->left->height, q->right->height); // height 업데이트인데 수정 필요할 수도?

        if(q->left == NULL)     // bf 업데이트
            q->bf = q->right->height + 1;   // 왼쪽이 NULL 이니까 오른쪽 높이 +1가 bf
        else if(q->right == NULL)
            q->bf = -(q->left->height + 1);      //오른쪽이 NULL 이니까 왼쪽높이 + 1이 bf
        else
            q->bf = q->left->height - q->right->height; //이건뭐...

        s.pop();
        q->height = 1 + max(q->left->height, q->right->height); // height 업데이트인데 수정 필요할 수도?

        if(q->left == NULL)     // bf 업데이트
            q->bf = q->right->height + 1;   // 왼쪽이 NULL 이니까 오른쪽 높이 +1가 bf
        else if(q->right == NULL)
            q->bf = (q->left->height + 1);      //오른쪽이 NULL 이니까 왼쪽높이 + 1이 bf
        else
            q->bf = q->left->height - q->right->height; //이건뭐...

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
        return;

    if(1 < x->bf) //rotate도 뭐 그냥 적당히 하면 가능...
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

}

void deleteAVL(node* T, int deleteKey)
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
        return;
    
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
        return;

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
}


int main(void)
{

    node* root = NULL;

    insertAVL(root, 10);
    insertAVL(root, 20);
    insertAVL(root, 0);


    return 0;
}