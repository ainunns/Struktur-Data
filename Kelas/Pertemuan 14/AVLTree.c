#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct AVLNode_t
{
    int data;
    struct AVLNode_t *left, *right;
    int height;
} AVLNode;

typedef struct AVL_t
{
    AVLNode *_root;
    unsigned int _size;
} AVL;

void avl_init(AVL *avl)
{
    avl->_root = NULL;
    avl->_size = 0u;
}

bool avl_isEmpty(AVL *avl)
{
    return avl->_root == NULL;
}

int _getHeight(AVLNode *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

int _getBalanceFactor(AVLNode *node)
{
    if (node == NULL)
        return 0;
    return _getHeight(node->left) - _getHeight(node->right);
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

AVLNode *_rightRotate(AVLNode *pivotNode)
{
    AVLNode *newParrent = pivotNode->left;
    pivotNode->left = newParrent->right;
    newParrent->right = pivotNode;

    pivotNode->height = max(_getHeight(pivotNode->left), _getHeight(pivotNode->right)) + 1;
    newParrent->height = max(_getHeight(newParrent->left), _getHeight(newParrent->right)) + 1;

    return newParrent;
}

AVLNode *_leftCaseRotate(AVLNode *node)
{
    return _rightRotate(node);
}

AVLNode *_leftRotate(AVLNode *pivotNode)
{
    AVLNode *newParrent = pivotNode->right;
    pivotNode->right = newParrent->left;
    newParrent->left = pivotNode;

    pivotNode->height = max(_getHeight(pivotNode->left), _getHeight(pivotNode->right)) + 1;
    newParrent->height = max(_getHeight(newParrent->left), _getHeight(newParrent->right)) + 1;

    return newParrent;
}

AVLNode *_rightCaseRotate(AVLNode *node)
{
    return _leftRotate(node);
}

AVLNode *_leftRightRotate(AVLNode *node)
{
    node->left = _leftRotate(node->left);
    return _rightRotate(node);
}

AVLNode *_rightLeftRotate(AVLNode *node)
{
    node->right = _rightRotate(node->right);
    return _leftRotate(node);
}

AVLNode *_avl_createNode(int value)
{
    AVLNode *newNode = (AVLNode *)malloc(sizeof(AVLNode));
    newNode->data = value;
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

AVLNode *_search(AVLNode *root, int value)
{
    while (root != NULL)
    {
        if (value < root->data)
            root = root->left;
        else if (value > root->data)
            root = root->right;
        else
            return root;
    }
    return root;
}

bool avl_find(AVL *avl, int value)
{
    AVLNode *temp = _search(avl->_root, value);
    if (temp == NULL)
        return false;

    if (temp->data == value)
        return true;
    else
        return false;
}

AVLNode *_insert_AVL(AVL *avl, AVLNode *node, int value)
{
    if (node == NULL)
        return _avl_createNode(value);
    if (value < node->data)
        node->left = _insert_AVL(avl, node->left, value);
    else if (value > node->data)
        node->right = _insert_AVL(avl, node->right, value);

    node->height = 1 + max(_getHeight(node->left), _getHeight(node->right));

    int balanceFactor = _getBalanceFactor(node);
    if (balanceFactor > 1 && value < node->left->data)
        return _leftCaseRotate(node);
    if (balanceFactor >= 1 && value > node->left->data)
        return _leftRightRotate(node);
    if (balanceFactor < -1 && value > node->right->data)
        return _rightCaseRotate(node);
    if (balanceFactor <= -1 && value < node->right->data)
        return _rightLeftRotate(node);  

    return node;
}

void avl_insert(AVL *avl, int value)
{
    if (!_search(avl->_root, value))
    {
        avl->_root = _insert_AVL(avl, avl->_root, value);
        avl->_size++;
    }
}

AVLNode *_findMinNode(AVLNode *node)
{
    AVLNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    return currNode;
}

AVLNode *_remove_AVL(AVLNode *node, int value)
{
    if (node == NULL)
        return node;

    if (value > node->data)
        node->right = _remove_AVL(node->right, value);
    else if (value < node->data)
        node->left = _remove_AVL(node->left, value);
    else
    {
        AVLNode *temp;
        if ((node->left == NULL) || (node->right == NULL))
        {
            temp = NULL;
            if (node->left == NULL)
                temp = node->right;
            else if (node->right == NULL)
                temp = node->left;

            if (temp == NULL)
            {
                temp = node;
                node = NULL;
            }
            else
                *node = *temp;

            free(temp);
        }
        else
        {
            temp = _findMinNode(node->right);
            node->data = temp->data;
            node->right = _remove_AVL(node->right, temp->data);
        }
    }

    if (node == NULL)
        return node;

    node->height = 1 + max(_getHeight(node->left), _getHeight(node->right));

    int balanceFactor = _getBalanceFactor(node);
    if (balanceFactor > 1 && _getBalanceFactor(node->left) >= 0)
        return _leftCaseRotate(node);
    if (balanceFactor > 1 && _getBalanceFactor(node->left) < 0)
        return _leftRightRotate(node);
    if (balanceFactor < -1 && _getBalanceFactor(node->right) <= 0)
        return _rightCaseRotate(node);
    if (balanceFactor < -1 && _getBalanceFactor(node->right) > 0)
        return _rightLeftRotate(node);

    return node;
}

void avl_remove(AVL *avl, int value)
{
    if (avl_find(avl, value))
    {
        avl->_root = _remove_AVL(avl->_root, value);
        avl->_size--;
    }
}

void avl_inorder(AVLNode *root)
{
    if (root)
    {
        avl_inorder(root->left);
        printf("node: %d pada height: %d\n", root->data, root->height);
        avl_inorder(root->right);
    }
}

void avl_postorder(AVLNode *root)
{
    if (root)
    {
        avl_postorder(root->left);
        avl_postorder(root->right);
        printf("%d ", root->data);
    }
}

void avl_preorder(AVLNode *root)
{
    if (root)
    {
        printf("%d ", root->data);
        avl_preorder(root->left);
        avl_preorder(root->right);
    }
}

int main()
{
    AVL avlku;
    avl_init(&avlku);
    avl_insert(&avlku, 3);
    avl_insert(&avlku, 5);
    avl_insert(&avlku, 8);
    avl_insert(&avlku, 20);
    avl_insert(&avlku, 18);
    avl_insert(&avlku, 13);
    avl_insert(&avlku, 10);

    printf("root: %d\n\n", avlku._root->data);

    printf("inorder:\n");
    avl_inorder(avlku._root);
    printf("\n");
    return 0;
}