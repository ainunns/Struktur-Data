/*
    Praktikum Final Struktur Data
    Author: Ainun Nadhifah Syamsiyah
    Problem: K - Keluarga Miko dan Cika
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool flag;
ll t;

struct BSTNode
{
    BSTNode *left, *right;
    ll key;
};

/* uniqueBST */

struct BST
{
    // Member
    BSTNode *_root;
    unsigned int _size;

    // Function
    void init()
    {
        _root = NULL;
        _size = 0u;
    }

    bool isEmpty()
    {
        return _root == NULL;
    }

    bool find(ll value)
    {
        BSTNode *temp = __search(_root, value);
        if (!temp)
            return false;

        if (temp->key == value)
            return true;
        else
            return false;
    }

    void insert(ll value)
    {
        if (!find(value))
        {
            _root = __insert(_root, value);
            _size++;
        }
    }

    void traversePreorder()
    {
        __preorder(_root);
    }

private:
    // Utility Function
    BSTNode *__createNode(ll value)
    {
        BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
        newNode->key = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    BSTNode *__search(BSTNode *root, ll value)
    {
        while (root != NULL)
        {
            if (value < root->key)
                root = root->left;
            else if (value > root->key)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    BSTNode *__insert(BSTNode *root, ll value)
    {
        if (root == NULL)
            return __createNode(value);

        if (value < root->key)
            root->left = __insert(root->left, value);
        else if (value > root->key)
            root->right = __insert(root->right, value);

        return root;
    }

    void __preorder(BSTNode *root)
    {
        if (root)
        {
            ll sum = root->key;
            flag |= (sum == t);
            if (root->left != NULL && root->right != NULL)
            {
                sum += root->left->key + root->right->key;
                flag |= (sum == t);
                sum -= root->left->key + root->right->key;
            }
            if (root->left != NULL)
            {
                sum += root->left->key;
                if (root->left->left != NULL)
                {
                    sum += root->left->left->key;
                    flag |= (sum == t);
                    sum -= root->left->left->key;
                }
                if (root->left->right != NULL)
                {
                    sum += root->left->right->key;
                    flag |= (sum == t);
                    sum -= root->left->right->key;
                }
                sum -= root->left->key;
            }
            if (root->right != NULL)
            {
                sum += root->right->key;
                if (root->right->left != NULL)
                {
                    sum += root->right->left->key;
                    flag |= (sum == t);
                    sum -= root->right->left->key;
                }
                if (root->right->right != NULL)
                {
                    sum += root->right->right->key;
                    flag |= (sum == t);
                    sum -= root->right->right->key;
                }
                sum -= root->right->key;
            }
            __preorder(root->left);
            __preorder(root->right);
        }
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    BST set;
    set.init();

    int b;
    cin >> b;

    while (b--)
    {
        ll c;
        cin >> c;
        set.insert(c);
    }

    cin >> t;

    flag = false;
    set.traversePreorder();
    cout << t << " ";
    cout << (flag ? "Selamat! Kalian menemukan harta karunnya" : "Tidak ada kombinasi yang tepat! Bikin ulang.") << "\n";
    return 0;
}