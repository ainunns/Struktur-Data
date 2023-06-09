/*
    Praktikum Final Struktur Data
    Author: Ainun Nadhifah Syamsiyah
    Problem: J - Zodiak
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD = 1e9 + 9;

ll mul(ll a, ll b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}

ll f(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m;
    cin >> m;
    while (m--)
    {
        ll n;
        cin >> n;
        n = n * (n - 1) / 2;
        cout << "Zodiak found: " << f(2, n) << " signs\n";
    }
    return 0;
}