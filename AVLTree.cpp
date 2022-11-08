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

node* Gp;
node* Gq;

void updateNode(node * q);


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
node* rotateLL(node* parent)
{
    node * child = parent->left;
    parent->left = child->right;
    child->right = parent;

    updateNode(child->left);
    updateNode(child->right);
    updateNode(child);

    return child;
}

node* rotateRR(node* parent)
{
    node * child = parent->right;
    parent->right = child->left;
    child->left = parent;

    updateNode(child->left);
    updateNode(child->right);
    updateNode(child);

    return child;
}

node* rotateLR(node * parent)     //미완
{
    parent->left = rotateRR(parent->left);
    parent = rotateLL(parent);
    return parent;
}

node* rotateRL(node * parent)     //미완
{
    parent->right = rotateLL(parent->right);
    parent = rotateRR(parent);
    return parent;
}

void updateNode(node * q)
{   
    if(q == NULL)
        return;

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

node* insertBST(node* T, int newKey)
{
    node* p = T;
    node* q = NULL;
    
    while(p != NULL) // 넣을 자리 찾고 넣음
    {
        if(newKey == p->key)
        {
            cout << "i <" <<newKey << "> : The key alreadt exists" <<endl;
            inorder(T);
            cout <<endl;
            return T;
        }
        
        q = p;

        if(newKey < p->key)
            p = p->left;
        else
            p = p->right;
    }

    node* Gp = getAVLNode(newKey); // 새 노드 만들기 bf, height = 0

    if(T == NULL) //넣을 자리에 넣기
        T = Gp;
    else if(newKey < q->key)
        q->left = Gp;
    else
        q->right = Gp;

    return T;
}


void checkbalande(node* T, int newKey, string &rotateType)
{
    Gp = T;
    
    node* x = NULL;
    node* f = NULL;

    stack<node*> s;

    while(Gp->key != newKey) // 넣을 자리 찾고 지나온거 전부 스택에 저장
    {   
        Gq = Gp;
        s.push(Gp);

        if(newKey < Gp->key)
            Gp = Gp->left;
        else
            Gp = Gp->right;
    }

    while(!s.empty())    // 넣었느니까 지나온거 업데이트
    {
        Gq = s.top();
        s.pop();
        updateNode(Gq);

        if(1 < Gq->bf || Gq->bf < -1)
        {
            if(x == NULL)
            {
                x = Gq;    
                if(!s.empty())
                    f = s.top();

                break;

            }
        }
    }

    if(x == NULL)
    {
        rotateType = "NO";
        Gp = NULL;
        Gq = NULL;
        return;
    }

    if(x != NULL)
    {
        Gp = x;
        Gq = f;
    }
    if(1 < x->bf)
    {
        if(x->left->bf < 0)
            rotateType = "LR";

        else
            rotateType = "LL";
    }
    else
    {
        if(x->right->bf > 0)
            rotateType = "RL";
        else
            rotateType = "RR";
    }

}

void rotateTree(node* T, string rotateType, node* p, node* q)
{                    

    if(rotateType != "NO")
    {

        if(q == NULL)
        {
            if(rotateType == "LL")
                Gp = rotateLL(p);
            else if(rotateType == "RR")
                Gp = rotateRR(p);
            else if(rotateType == "LR")
                Gp = rotateLR(p);
            else
                Gp = rotateRL(p);
            
        }
        else
        {
            if(q->left == p)
            {
                if(rotateType == "LL")
                    q->left = rotateLL(p);
                else if(rotateType == "RR")
                    q->left = rotateRR(p);
                else if(rotateType == "LR")
                    q->left = rotateLR(p);
                else
                    q->left = rotateRL(p);
            }
            else
            {
                if(rotateType == "LL")
                    q->right = rotateLL(p);
                else if(rotateType == "RR")
                    q->right = rotateRR(p);
                else if(rotateType == "LR")
                    q->right = rotateLR(p);
                else
                    q->right = rotateRL(p);
            }
            
            node* tmp = T;
            while(tmp->key != q->key) // root 부터 rotate 한 친구까지 update
            {   
                updateNode(tmp);

                if(tmp->key < Gp->key)
                    tmp = tmp->left;
                else
                    tmp = tmp->right;
            }
        }
    }
}

node* insertAVL(node *T, int newKey)
{
    string rotateType;

    T = insertBST(T, newKey);

    checkbalande(T, newKey, rotateType);
    cout << rotateType << " ";

    rotateTree(T, rotateType, Gp, Gq);


    if(Gq != NULL || rotateType == "NO")
        return T;
    else
        return Gp;

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
        
        inorder(root);
        cout <<endl;

    } while(root != NULL);


    return 0;
}