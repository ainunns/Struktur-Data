/*
    Praktikum 4 Struktur Data
    Author: Ainun Nadhifah Syamsiyah
    Problem: CN - Connected Number
*/

#include <bits/stdc++.h>
using namespace std;
const int MX = 2e5 + 5;
vector<int> v[MX];
bool vis[MX];
int n, x[101], c;
void dfs(int node)
{
    vis[node] = 1;
    for (auto c : v[node])
    {
        if (!vis[c])
            dfs(c);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }
    cin >> c;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if ((x[i] ^ x[j]) % c == 0)
            {
                v[x[i]].push_back(x[j]);
                v[x[j]].push_back(x[i]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[x[i]])
        {
            dfs(x[i]);
            ans++;
        }
    }
    cout << ans << "\n";
}