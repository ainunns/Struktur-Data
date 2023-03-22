#include <bits/stdc++.h>
using namespace std;
long long cnt;
typedef struct bstNode
{
    long long key, child;
    struct bstNode *left, *right;
} BSTNode;

typedef struct bst
{
    BSTNode *_root;
    long long _size;
} BST;

BSTNode *__createNode(long long val)
{
    BSTNode *newNode = (BSTNode *)malloc(sizeof(bstNode));
    newNode->key = val;
    newNode->child = 0;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void bst_init(BST *bst)
{
    bst->_root = NULL;
    bst->_size = 0;
}

long long bst_find(BST *bst, long long val)
{
    BSTNode *root = bst->_root;
    long long sum = 0;
    bool ada = false;
    while (root != NULL)
    {
        // cout << "key skrg: " << root->key << " size skrg: " << root->child << "\n";
        if (val >= root->key)
            sum += root->child + 1;
        if (val == root->key)
            ada = true;
        if (val < root->key)
            root = root->left;
        else if (val > root->key)
            root = root->right;
        else
            break;
    }
    return (ada ? sum : -1);
}

BSTNode *__insert(BSTNode *root, long long val)
{
    if (root == NULL)
        return __createNode(val);

    if (val < root->key)
    {
        root->child++;
        root->left = __insert(root->left, val);
    }
    else if (val > root->key)
        root->right = __insert(root->right, val);

    return root;
}

void bst_insert(BST *bst, long long val)
{
    bst->_root = __insert(bst->_root, val);
    bst->_size++;
}

int main()
{
    BST avl;
    bst_init(&avl);

    int q;
    cin >> q;

    while (q--)
    {
        long long x, k;
        cin >> x >> k;

        if (x == 1)
        {
            bst_insert(&avl, -k);
        }
        else if (x == 2)
        {
            long long idx = bst_find(&avl, -k);
            if (idx != -1)
                cout << idx << "\n";
            else
                cout << "Data tidak ada\n";
        }
    }
    return 0;
}