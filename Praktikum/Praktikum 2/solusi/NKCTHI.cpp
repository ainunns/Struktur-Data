/*
    Praktikum 2 Struktur Data
    Author: Ainun Nadhifah Syamsiyah
    Problem: NKCTHI - Nyari Kado Buat Cika
*/

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <climits>
#define ll long long
using namespace std;

ll dist[100005];
vector<ll> leaves;

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

    ll find(ll valueL, ll valueR)
    {
        return __search(_root, valueL, valueR);
    }

    void insert(ll value, ll dis)
    {
        _root = __insert(_root, value, 0, dis);
        _size++;
    }

    void traversePreorder()
    {
        __preorder(_root);
    }

private:
    // Utility Function
    BSTNode *__createNode(ll value, ll currDist, ll dis)
    {
        BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
        newNode->key = value;
        newNode->left = newNode->right = NULL;
        dist[newNode->key] = currDist + dis;
        return newNode;
    }

    ll __search(BSTNode *root, ll valueL, ll valueR)
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
                return tmp;
        }
        return tmp;
    }

    BSTNode *__insert(BSTNode *root, ll value, ll currDist, ll dis)
    {
        if (root == NULL)
            return __createNode(value, currDist, dis);

        if (value < root->key)
            root->left = __insert(root->left, value, dist[root->key], dis);
        else if (value > root->key)
            root->right = __insert(root->right, value, dist[root->key], dis);

        return root;
    }

    void __preorder(BSTNode *root)
    {
        if (root)
        {
            int child = 0;
            if (root->left != NULL)
            {
                child++;
                __preorder(root->left);
            }
            if (root->right != NULL)
            {
                child++;
                __preorder(root->right);
            }

            if (child == 0)
                leaves.push_back(root->key);
        }
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    BST set;
    set.init();

    ll n, r;
    cin >> n >> r;
    set.insert(r, 0);

    for (int i = 1; i < n; i++)
    {
        ll a, w;
        cin >> a >> w;
        set.insert(a, w);
    }

    set.traversePreorder();

    int t;
    cin >> t;
    while (t--)
    {
        ll x;
        cin >> x;
        ll ans = LLONG_MAX;

        for (auto leaf : leaves)
        {
            ll v = leaf;
            ll lca = set.find(min(x, v), max(x, v));
            ans = min(ans, dist[x] + dist[v] - 2 * dist[lca]);
        }
        cout << ans;
        if (t > 0)
            cout << " ";
        else
            cout << "\n";
    }
    return 0;
}