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
node* rotateLL(node * parent)     // 완성
{
    node* child = parent->right;
    parent->right = child->left;
    child->left = parent;

    return child;
}

node* rotateRR(node* parent)     // 완성
{
    node* child = parent->left;
    parent->left = child->right;
    child->right = parent;

    return child;
}

node* insertAVL(node *node, int key)
{

    if(node == NULL)
		return(getAVLNode(key));

	if(key < node->key)
		node->right = insertAVL(node->right, key);
	else if(key > node->key)
		node->left = insertAVL(node->left, key);
	else 
		return node;

	if(node->bf > 1 && key < node->left->key)
		retun 

	

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