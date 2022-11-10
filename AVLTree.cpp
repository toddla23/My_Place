#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <fstream>

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

void inorder1(node* T)
{   
    if(T != NULL)
    {   
        inorder1(T->left);
        cout <<"("<< T->key << ", " << T->bf<< ") ";
        inorder1(T->right);
    }
}

int inThere(node* T, int key)
{
    node* p = T;
    node* q = NULL;
    while(p != NULL) // 넣을 자리 찾고 넣음
    {
        if(key == p->key)
            return 1;
        
        q = p;

        if(key < p->key)
            p = p->left;
        else
            p = p->right;
    }
    if(p == NULL)
        return 0;
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
            return T;
        
        
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


    if(p->left != NULL && p->right != NULL)
    {
        stack.push(p);
        node *tempNode = p;
        
        if(p->left->height <= p->right->height)
        {
            p = p->right;

            while(p->left != NULL)
            {
                Gq = p;
                stack.push(p);
                p = p->left;
            }
        }
        else
        {
            p = p->left;

            while (p->right != NULL)
            {   
                Gq = p;
                stack.push(p);
                p = p->right;
            }   

        }
        
        tempNode->key = p->key;
        updateNode(tempNode);
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

    Gq = q;

    return T;
}


void checkbalande(node* T, int Key, string &rotateType)
{
    Gp = T;
    
    node* x = NULL;
    node* f = NULL;
    node* tmp = Gq;

    stack<node*> s;
    
    while(Gp->key != Key) // 넣을 자리 찾고 지나온거 전부 스택에 저장
    {   

        Gq = Gp;
        s.push(Gp);
        if(Key < Gp->key)
            Gp = Gp->left;
        else
            Gp = Gp->right;
    }
    
    if(tmp != NULL)
        s.push(tmp);
/*     if(Gp != NULL)
        cout <<"{" <<Gp->key << "}" << endl; */

    while(!s.empty())    // 넣었느니까 지나온거 업데이트
    {
        Gq = s.top();
        s.pop();
        //cout << "[" << Gq->key << "]";
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
    //cout <<endl;
/*     if(f == NULL)
        cout  << "not exists f" << endl;
 */
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
/*             inorder(Gp);
            cout <<endl; */
        }
        else
        {
            //cout << "[" << p->key << ", " << q->key <<"]" <<endl;
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

            while(tmp->key != p->key) // root 부터 rotate 한 친구까지 update
            {
                //cout << "[" << tmp->key << "]";
                updateNode(tmp);
                if(tmp->key < p->key)
                    tmp = tmp->right;
                else if (tmp->key > p->key)
                    tmp = tmp->left;
                
            }
            //cout <<endl;
        }
    }
    updateNode(T);
}

node* insertAVL(node *T, int newKey)
{
    string rotateType;
    if(inThere(T, newKey) == 1)
    {
        cout << "i " << newKey << " : The key already exists" << endl;
        inorder1(T);
        cout <<endl;
        return T;

    }
    else
    {
        T = insertBST(T, newKey);

        checkbalande(T, newKey, rotateType);
        

        rotateTree(T, rotateType, Gp, Gq);
        cout << rotateType << " ";

    }


    if(Gq != NULL || rotateType == "NO")
    {
        inorder1(T);
        cout << endl;
        return T;
    }
    else
    {
        inorder1(Gp);
        cout << endl;
        return Gp;
    }

}

node* deleteAVL(node* T, int deleteKey)
{
    string rotateType = "NO";

    if(inThere(T, deleteKey) == 0)
    {
        cout << "d " << deleteKey << " : The key does not exist" << endl;
        inorder1(T);
        cout << endl;
        return T;
    }
    else
    {
        T = deleteBST(T, deleteKey);
        if(Gq != NULL)
        {
            updateNode(Gq);
            //cout <<Gq->key << ", " << Gq->bf << ", " << Gq->height <<endl;                                 //Gq가 내가 삭제한 노드의 부모노드임...
            checkbalande(T, Gq->key, rotateType);
            rotateTree(T, rotateType, Gp, Gq);
        }

        cout << rotateType << " ";
    }
/*     inorder(T);
    cout <<endl; */

/*     if(Gq != NULL)
        cout << "Gq : "<< Gq->key << ", " << Gq->bf << ", " << Gq->height <<endl;
    else
        cout <<"Gq == NULL" <<endl;
    if(Gp != NULL)
        cout << "Gp : "<< Gp->key << ", " << Gp->bf << ", " << Gp->height <<endl;
    else
        cout <<"Gp == NULL" <<endl; */

    

     if(Gq == NULL && rotateType != "NO")
    {
        inorder1(Gp);
        cout << endl;
        return Gp;

    }
    else
    {
        inorder1(T);
        cout << endl;
        return T;
    }


}


int main(void)
{
    ifstream ifs("AVL-input.txt");

    node* root = NULL;

    int n;
    char i;
    
    
    while(!ifs.eof())
    {
        ifs >> i >> n ;
        if(i == 'i')
            root = insertAVL(root, n);
        else if(i == 'd')
            root = deleteAVL(root, n);
        else
            break;
    }


/*     do
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

    } while(root != NULL); */


    return 0;
}