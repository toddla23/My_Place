#include <iostream>
#include <cstdlib>

#define MAX(a, b) (a)

using namespace std;

typedef struct AVLNode
{
    int key;
    int height;
    int bf;
    struct AVLNode* left, *right;
}AVLNode;

int get_height(AVLNode* node)
{
    int height = 0;
    if (node != NULL)
        height = 1+ max(get_height(node->left), get_height(node->right));

    return height;
}

int get_balance(AVLNode* node)
{
    if(node == NULL)
        return 0;

    return get_height(node->left) - get_height(node->right);
}

AVLNode* create_ndoe(int key)
{
    AVLNode* node = new AVLNode;
    node->left = node->right = NULL;
    node->key = key;
    node->bf = 0;
    node->height = 0;

    return node;
}

AVLNode* rotate_right(AVLNode* parent)
{
    AVLNode * child = parent->left;
    parent->left = child->right;
    child->right = parent;

    return child;
}

AVLNode* rotate_left(AVLNode* parent)
{
    AVLNode * child = parent->right;
    parent->right = child->left;
    child->left = parent;

    return child;
}

AVLNode* insert(AVLNode* node, int key)
{
    if(node == NULL)
        return create_ndoe(key);

    if(key < node->key)
        node->left = insert(node->left, key);
    else if(key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    int balance = get_balance(node);

    if(balance > 1 && key < node->left->key)
        return rotate_right(node);
    
    if(balance < -1 && key < node->right->key)
        return rotate_left(node);

    if(balance > 1 && key > node->left->key)
    {
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }

    if(balance < -1 && key > node->right->key)
    {
        node->right = rotate_left(node->right);
        return rotate_left(node);
    }

    return node;
}

int main(void)
{
    AVLNode* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 10);

    return 0;
}