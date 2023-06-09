/*
    Praktikum 2 Struktur Data
    Author: Ainun Nadhifah Syamsiyah
    Problem: FS - Find the Subtree
*/

#include <iostream>
#include <stdlib.h>
#include <climits>
#define ll long long
using namespace std;

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

    pair<ll, ll> find(ll valueL, ll valueR)
    {
        return __search(_root, valueL, valueR);
    }

    void insert(ll value)
    {
        _root = __insert(_root, value);
        _size++;
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

    pair<ll, ll> __search(BSTNode *root, ll valueL, ll valueR)
    {
        ll level = 0, tmp = 0;
        while (root != NULL)
        {
            tmp = root->key;
            if (valueR < root->key)
                root = root->left;
            else if (valueL > root->key)
                root = root->right;
            else
                return {tmp, level};
            level++;
        }
        return {tmp, level};
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
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    BST set;
    set.init();

    int n;
    cin >> n;
    while (n--)
    {
        ll a;
        cin >> a;
        set.insert(a);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        ll mx = LLONG_MIN, mi = LLONG_MAX;
        while (x--)
        {
            ll a;
            cin >> a;
            mx = max(mx, a);
            mi = min(mi, a);
        }
        pair<ll, ll> ans = set.find(mi, mx);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}