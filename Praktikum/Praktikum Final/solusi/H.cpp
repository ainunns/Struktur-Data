/*
    Praktikum Final Struktur Data
    Author: Ainun Nadhifah Syamsiyah
    Problem: H - All BST
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> v;
vector<string> vs;

/* Node structure */

struct BSTNode
{
    BSTNode *left, *right;
    ll key, level;
};

/* uniqueBST */

struct BST
{
    // Member
    BSTNode *_root;
    unsigned ll _size;

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

    BSTNode *find(ll value)
    {
        BSTNode *temp = __search(_root, value);
        if (!temp)
            return NULL;

        if (temp->key == value)
            return temp;
        else
            return NULL;
    }

    void insert(ll value, ll dis)
    {
        if (find(value) == NULL)
        {
            _root = __insert(_root, value, 1);
            _size++;
        }
    }

    void remove(ll value)
    {
        if (find(value) != NULL)
        {
            _root = __remove(_root, value);
            _size++;
        }
    }

    void traverseInorder()
    {
        __inorder(_root);
    }

    void traversePreorder()
    {
        __preorder(_root);
    }

    void traversePostorder()
    {
        __postorder(_root);
    }

private:
    // Utility Function
    BSTNode *__createNode(ll value, ll lv)
    {
        BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
        newNode->key = value;
        newNode->left = newNode->right = NULL;
        newNode->level = lv;
        return newNode;
    }

    BSTNode *__search(BSTNode *root, ll value)
    {
        while (root != NULL)
        {
            if (value < root->key)
            {
                vs.push_back("L");
                root = root->left;
            }
            else if (value > root->key)
            {
                vs.push_back("R");
                root = root->right;
            }
            else
            {
                vs.push_back("S");
                return root;
            }
        }
        return root;
    }

    BSTNode *__insert(BSTNode *root, ll value, ll lv)
    {
        if (root == NULL)
            return __createNode(value, lv);

        if (value < root->key)
            root->left = __insert(root->left, value, lv + 1);
        else if (value > root->key)
            root->right = __insert(root->right, value, lv + 1);

        return root;
    }

    BSTNode *__findMinNode(BSTNode *node)
    {
        BSTNode *currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;

        return currNode;
    }

    BSTNode *__remove(BSTNode *root, ll value)
    {
        if (root == NULL)
            return NULL;

        if (value > root->key)
            root->right = __remove(root->right, value);
        else if (value < root->key)
            root->left = __remove(root->left, value);
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

            BSTNode *temp = __findMinNode(root->right);
            root->key = temp->key;
            root->right = __remove(root->right, temp->key);
        }
        return root;
    }

    void __inorder(BSTNode *root)
    {
        if (root)
        {
            __inorder(root->left);
            v.push_back(root->key);
            __inorder(root->right);
        }
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

    void __preorder(BSTNode *root)
    {
        if (root)
        {
            cout << root->key << " ";
            __preorder(root->left);
            __preorder(root->right);
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    BST bst;
    bst.init();

    string cmd;
    while (cin >> cmd)
    {

        if (cmd == "IN")
        {
            ll x;
            cin >> x;
            bst.insert(x, 0);
        }
        else if (cmd == "FD")
        {
            int x;
            cin >> x;
            BSTNode *temp = bst.find(x);
            if (!temp)
                cout << "no " << x << endl;
            else
                cout << "on level " << temp->level << endl;
        }
        else if (cmd == "RK")
        {
            int x;
            cin >> x;
            x--;
            v.clear();
            bst.traverseInorder();
            if (x >= (int)v.size())
                cout << -1 << endl;
            else
                cout << v[x] << endl;
        }
        else if (cmd == "PH")
        {
            int x;
            cin >> x;
            vs.clear();
            BSTNode *temp = bst.find(x);
            if (!temp)
                cout << "no " << x << endl;
            else
            {
                for (int i = 0; i < (int)vs.size(); i++)
                {
                    cout << vs[i];
                }
                cout << endl;
            }
        }
        else if (cmd == "STOP")
        {
            cout << "done" << endl;
            break;
        }
    }
    return 0;
}