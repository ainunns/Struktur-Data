/*
    Praktikum 4 Struktur Data
    Author: Ainun Nadhifah Syamsiyah
    Problem: PBJ - Pemerintah Buat Jembatan
*/

#include <bits/stdc++.h>
using namespace std;
const int MX = 2e3 + 3;
int n, m, vis[MX];
vector<int> v[MX];
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
    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            ans++;
            dfs(i);
        }
    }
    cout << ans - 1 << "\n";
    return 0;
}