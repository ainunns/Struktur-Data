#include <bits/stdc++.h>
using namespace std;
typedef struct bstNode
{
    int key;
    struct bstNode *left, *right;
} BSTNode;

typedef struct bst
{
    BSTNode *_root;
    int _size;
} BST;

void bst_init(BST *bst)
{
    bst->_root = NULL;
    bst->_size = 0;
}

bool bst_isEmpty(BST *bst)
{
    return bst->_root == NULL;
}

BSTNode *__createNode(int val)
{
    BSTNode *newNode = (BSTNode *)malloc(sizeof(bstNode));
    newNode->key = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode *__search(BSTNode *root, int val)
{
    while (root != NULL)
    {
        if (val < root->key)
            root = root->left;
        else if (val > root->key)
            root = root->right;
        else
            return root;
    }
    return root;
}

bool bst_find(BST *bst, int val)
{
    BSTNode *tmp = __search(bst->_root, val);
    if (tmp == NULL)
        return false;
    if (tmp->key == val)
        return true;
    return false;
}

BSTNode *__insert(BSTNode *root, int val)
{
    if (root == NULL)
        return __createNode(val);

    if (val < root->key)
        root->left = __insert(root->left, val);
    else if (val > root->key)
        root->right = __insert(root->right, val);

    return root;
}

void bst_insert(BST *bst, int val)
{
    if (!bst_find(bst, val))
    {
        bst->_root = __insert(bst->_root, val);
        bst->_size++;
    }
}

BSTNode *__findMinNode(BSTNode *node)
{
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    return currNode;
}

BSTNode *__remove(BSTNode *root, int val)
{
    if (root == NULL)
        return NULL;

    if (val > root->key)
        root->right = __remove(root->right, val);
    else if (val < root->key)
        root->left = __remove(root->left, val);
    else
    {
        if (root->left == NULL)
        {
            BSTNode *rightChild = root->right;
            free(root);
            return rightChild;
        }
        else if (root->right == NULL)
        {
            BSTNode *leftChild = root->left;
            free(root);
            return leftChild;
        }
        BSTNode *tmp = __findMinNode(root->right);
        root->key = tmp->key;
        root->right = __remove(root->right, tmp->key);
    }
    return root;
}

void bst_remove(BST *bst, int val)
{
    if (bst_find(bst, val))
    {
        bst->_root = __remove(bst->_root, val);
        bst->_size--;
    }
}

void __inorder(BSTNode *root)
{
    if (root)
    {
        __inorder(root->left);
        cout << root->key << " ";
        __inorder(root->right);
    }
}

void bst_inorder(BST *bst)
{
    __inorder(bst->_root);
}

void __postorder(BSTNode *root)
{
    if (root)
    {
        __postorder(root->left);
        __postorder(root->right);
        cout << root->key << " ";
    }
}

void bst_postorder(BST *bst)
{
    __postorder(bst->_root);
}

void __preorder(BSTNode *root)
{
    if (root)
    {
        cout << root->key << " ";
        __preorder(root->left);
        __preorder(root->right);
    }
}

void bst_preorder(BST *bst)
{
    __preorder(bst->_root);
}

int main()
{
    BST set;
    bst_init(&set);

    bst_insert(&set, 6);
    bst_insert(&set, 1);
    bst_insert(&set, 8);
    bst_insert(&set, 12);
    bst_insert(&set, 1);
    bst_insert(&set, 3);
    bst_insert(&set, 7);

    bst_inorder(&set);
    puts("");

    bst_remove(&set, 8);
    bst_remove(&set, 6);
    bst_inorder(&set);
    puts("");

    return 0;
}