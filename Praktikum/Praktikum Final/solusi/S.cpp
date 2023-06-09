/*
    Praktikum Final Struktur Data
    Author: Ainun Nadhifah Syamsiyah
    Problem: S - Alice in Numberland
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n, k;
    cin >> n >> k;
    ll a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ll len[n + 1] = {0}, p[11];
    map<ll, ll> rem[11];
    p[0] = 1;
    for (int i = 1; i <= 10; i++)
    {
        p[i] = (p[i - 1] * 10) % k;
    }
    for (int i = 1; i <= n; i++)
    {
        ll x = a[i];
        while (x > 0)
        {
            len[i]++;
            x /= 10;
        }
        rem[len[i]][a[i] % k]++;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            ll r = (a[i] * p[j]) % k, xr = (k - r) % k;
            ans += rem[j][xr];
            if (len[i] == j && (r + a[i] % k) % k == 0)
                ans--;
        }
    }
    cout << ans << "\n";
    return 0;
}
