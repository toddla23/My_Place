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

node* Gp; // rotateTree의 리턴으로 사용할 p
node* Gq; // rotateTree의 리턴으로 사용할 q

void updateNode(node * q);


void inorder(node* T)   // (key, bf, height)를  inorder로 출력
{
    if(T != NULL)
    {
        inorder(T->left);
        cout <<"("<< T->key << ", " << T->bf << ", " << T->height<< ")" ;
        inorder(T->right);
    }
}

void inorder1(node* T)  // (key, bf)를  inorder로 출력
{   
    if(T != NULL)
    {   
        inorder1(T->left);
        cout <<"("<< T->key << ", " << T->bf<< ") ";
        inorder1(T->right);
    }
}

int inThere(node* T, int key)       // key를 가진 node가 있는지 알아봄 있으면 1 없으면 0
{
    node* p = T;
    node* q = NULL;
    while(p != NULL)
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

node* getAVLNode(int newkey)        // Node를 생성및 초기화
{
    node* n = new node;
    n->left = n->right = NULL;
    n->bf = 0;
    n->key = newkey;
    n->height = 0;
    
    return n;
}

// rotate 함수 구해야함
node* rotateLL(node* parent)  //rotate LL을 시행후 roate한 node를 반환
{
    node * child = parent->left;
    parent->left = child->right;
    child->right = parent;

    updateNode(child->left);
    updateNode(child->right);
    updateNode(child);

    return child;
}

node* rotateRR(node* parent)    //rotate RR을 시행후 roate한 node를 반환
{
    node * child = parent->right;
    parent->right = child->left;
    child->left = parent;

    updateNode(child->left);
    updateNode(child->right);
    updateNode(child);

    return child;
}

node* rotateLR(node * parent)   //회전할 node의 왼쪽 자식 노드를 rotate RR을 시행후 rotate할 node 를 ratate LL 시행후 반환
{
    parent->left = rotateRR(parent->left);
    parent = rotateLL(parent);
    return parent;
}

node* rotateRL(node * parent)       //회전할 node의 오른쪽 자식 노드를 rotate LL을 시행후 rotate할 node 를 ratate RR 시행후 반환
{
    parent->right = rotateLL(parent->right);
    parent = rotateRR(parent);
    return parent;
}

void updateNode(node * q)
{   
    if(q == NULL)
        return;

    if(q->left == NULL && q->right != NULL)// 왼쪽이 NULL이니까 bf = -(오른쪽 높이 +1)
    {
        q->height = 1 + q->right->height;
        q->bf = -(q->right->height + 1);
    }
    else if (q->left != NULL && q->right == NULL) //오른쪽이 NULL 이니까 bf = 왼쪽높이 + 1
    {
        q->height = 1 + q->left->height;
        q->bf = q->left->height + 1;     
    }
    else if(q->left == NULL && q->right == NULL)  //왼쪽 오른쪽 둘다 NULL인 경우에는 bf, height = 0
    {
        q->height = 0;
        q->bf = 0;
    }
    else  //둘다 NULL이 아닌 경우 bf = (왼쪽 - 오른쪽)
    {
        q->height = 1 + max(q->left->height, q->right->height); 
       q->bf = q->left->height - q->right->height;
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

    while(p != NULL && deleteKey != p->key)     // stack에 지나온것 저장하고 deleteg할 node를 p에 저장
    {
        q = p;
        stack.push(q);
        
        if(deleteKey < p->key)
            p = p->left;
        else
            p = p->right;
    }


    if(p->left != NULL && p->right != NULL)     // 왼쪽과 오른쪽이 NULL이 아닌 경우 그중 높이가 더 높은쪽의 node를 가져옴
    {
        stack.push(p);
        node *tempNode = p;
        
        if(p->left->height <= p->right->height)     // 오른쪽이 더 크거나 같을때에 오른쪽의 가장 왼쪽 node를 가져옴 지나온건 stack에 저장
        {
            p = p->right;

            while(p->left != NULL)
            {
                Gq = p;
                stack.push(p);
                p = p->left;
            }
        }
        else        // 왼쪽 더 클때에 왼쪽의 가장 오른쪽 node를 가져옴 지나온건 stack에 저장
        {
            p = p->left;

            while (p->right != NULL)
            {   
                Gq = p;
                stack.push(p);
                p = p->right;
            }   

        }
        
        tempNode->key = p->key;         //가져온 node의 key와 바꿀 node의 키값 바꿈
        updateNode(tempNode);       // 바꾼 친구 업데이트
        q = stack.top();        // q는 바꾼 노드의 부모노드
    }

    if(p->left == NULL && p->right == NULL)     //왼쪽 오른쪽 모두 NULL인 경우에 그냥 제거
    {
        if(q == NULL)
            T = NULL;
        else if(q->left == p)
            q->left = NULL;
        else
            q->right = NULL;
    }
    else            // 둘중 하나만 없는경우
    {
        if(p->left != NULL)         // 오른쪽이 없는 경우 왼쪽에있는 노드를 원래 있던 노드에 붙여넣음
        {
            if(q == NULL)
                T = T->left;
            else if (q->left == p)
                q->left = p->left;
            else
                q->right = p->left;
        }
        else         // 왼쪽이 없는 경우 오른쪽에있는 노드를 원래 있던 노드에 붙여넣음
        {
            if(q == NULL)
                T = T->right;
            else if(q->left == p)
                q->left = p->right;
            else
                q->right = p->right;
        }
    }
    delete p;       //p 삭제

    Gq = q;         // 삭제한 노드의 부모 노드를 받아옴

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
    
    if(tmp != NULL)     //deletekey할때 key값을 찾고 그 것을 stack에 저장을 안해줘서 따로 저장하는 곳
        s.push(tmp);
/*     if(Gp != NULL)
        cout <<"{" <<Gp->key << "}" << endl; */

    while(!s.empty())    // 넣었느니까 지나온거 업데이트
    {
        Gq = s.top();
        s.pop();
        //cout << "[" << Gq->key << "]";
        updateNode(Gq);

        if(1 < Gq->bf || Gq->bf < -1) // 지나온곳 업데이트 중 bf가 2이상 or -1 이하면 멈춤
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
    if(x == NULL)   // 삽입, 삭제한 부분부터 root까지의 node중 bf가 2이상 or -2 이하인 곳이 없음
    {
        rotateType = "NO";
        Gp = NULL;
        Gq = NULL;
        return;
    }

    if(x != NULL)// 삽입, 삭제한 부분부터 root까지의 node중 bf가 2이상 or -2 이하인 곳이 있음
    {
        Gp = x;
        Gq = f;
    }
    if(1 < x->bf)   // bf와 자식노드의 유무에 맞춰서 roataeType 결정
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
    if(rotateType != "NO") // NO 면 바꿀것 없음
    {

        if(q == NULL)       // rotate할 node가 root인 경우
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
        else        // rotate할 node가 root가 아닌 경우
        {
            //cout << "[" << p->key << ", " << q->key <<"]" <<endl;
            if(q->left == p)  // 부모노드를 알아도 그 자식 노드가 왼쪽인지 오른쪽인지에 따라 rotate한것을 붙여줄 곳이 다르기에 이거 결정
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

            node* tmp = T;  //tmp = root

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
    updateNode(T); //root 업데이트
}

node* insertAVL(node *T, int newKey)
{
    string rotateType;
    if(inThere(T, newKey) == 1)     // newkey가 있는 지 확인 있으면 아래 출력
    {
        cout << "i " << newKey << " : The key already exists" << endl;
        inorder1(T);
        cout <<endl;
        return T;

    }
    else // 없으면 삽입 시작
    {
        T = insertBST(T, newKey);

        checkbalande(T, newKey, rotateType); //벨런스 체크 rotateType과 Gq, Gp 리턴인데 Gq와 Gp는 checkbalance의 리턴을 전역변수으로 처리
        

        rotateTree(T, rotateType, Gp, Gq); // Gp가 rotate필요한 부분, Gq가 그 부분의 부모노드
        cout << rotateType << " ";

    }


    if(Gq != NULL || rotateType == "NO") //출력
    {
        inorder1(T);
        cout << endl;
        return T;
    }
    else //rotate를 해야할 부분이 부모노드인 경우 return T를 하면 rotate한 것이 아닌 이전의 것으로 나와 Gp를 리턴해야함
    {
        inorder1(Gp);
        cout << endl;
        return Gp;
    }

}

node* deleteAVL(node* T, int deleteKey)
{
    string rotateType = "NO";

    if(inThere(T, deleteKey) == 0) //deleteKey가 있는지 판단 없으면 아래 출력
    {
        cout << "d " << deleteKey << " : The key does not exist" << endl;
        inorder1(T);
        cout << endl;
        return T;
    }
    else // 있으면 삭제 시작
    {
        T = deleteBST(T, deleteKey);
        if(Gq != NULL)
        {
            updateNode(Gq);
            //cout <<Gq->key << ", " << Gq->bf << ", " << Gq->height <<endl;                                 //Gq가 내가 삭제한 노드의 부모노드임...
            checkbalande(T, Gq->key, rotateType);       //벨런스 체크 rotateType과 Gq, Gp 리턴인데 Gq와 Gp는 checkbalance의 리턴을 전역변수으로 처리
            rotateTree(T, rotateType, Gp, Gq);     // Gp가 rotate필요한 부분, Gq가 그 부분의 부모노드
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

    

     if(Gq == NULL && rotateType != "NO")   //rotate를 해야할 부분이 부모노드인 경우 return T를 하면 rotate한 것이 아닌 이전의 것으로 나와 Gp를 리턴해야함
    {
        inorder1(Gp);
        cout << endl;
        return Gp;

    }
    else //아니면 T 리턴
    {
        inorder1(T);
        cout << endl;
        return T;
    }


}


int main(void)
{
    ifstream ifs("AVL-input.txt"); // 여기에 파일 경로 넣어주세요

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

    } while(root != NULL); */  //여기는 하나씩 입력할때 쓰는 곳 입니다. 위에있는 while 블록 주석처리 후 사용하면됩니다.


    return 0;
}