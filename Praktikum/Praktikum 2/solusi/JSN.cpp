/*
    Praktikum 2 Struktur Data
    Author: Ainun Nadhifah Syamsiyah
    Problem: JSN - James Suka Nyontek
*/

#include <iostream>
#include <vector>
#include <stdlib.h>
#define ll long long
using namespace std;

const ll MOD = 1e9 + 7;
ll c[55][55];
vector<ll> node;

ll add(ll a, ll b)
{
    return (a % MOD + b % MOD) % MOD;
}

ll mul(ll a, ll b)
{
    return (a % MOD * b % MOD) % MOD;
}

ll f(vector<ll> child)
{
    ll sz = child.size();
    if (sz <= 2)
        return 1;

    vector<ll> left, right;
    for (int i = 1; i < sz; i++)
    {
        if (child[i] < child[0])
            left.push_back(child[i]);
        else
            right.push_back(child[i]);
    }

    return mul(c[sz - 1][left.size()], mul(f(left), f(right)));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i <= 50; i++)
        c[i][0] = c[i][i] = 1;

    for (int i = 2; i <= 50; i++)
        for (int j = 1; j < i; j++)
            c[i][j] = add(c[i - 1][j], c[i - 1][j - 1]);

    int n;
    cin >> n;
    node.resize(n);

    for (int i = 0; i < n; i++)
        cin >> node[i];

    cout << f(node) - 1 << "\n";
    return 0;
}