/*
    Praktikum 4 Struktur Data
    Author: Ainun Nadhifah Syamsiyah
    Problem: CNP - Cika Nemu Papan
*/

#include <bits/stdc++.h>
using namespace std;
bool vis[10];
vector<int> v[10];
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
    int n;
    cin >> n;
    while (n--)
    {
        string a, b, dum;
        cin >> a >> dum >> b;
        pair<int, int> posA = {a[0] - 'A' + 1, a[1] - '0'};
        pair<int, int> posB = {b[0] - 'A' + 1, b[1] - '0'};
        v[(posA.second - 1) * 3 + posA.first].push_back((posB.second - 1) * 3 + posB.first);
        v[(posB.second - 1) * 3 + posB.first].push_back((posA.second - 1) * 3 + posA.first);
    }
    int ans = 36;
    for (int i = 1; i <= 9; i++)
    {
        for (int j = i + 1; j <= 9; j++)
        {
            memset(vis, false, sizeof(vis));
            dfs(i);
            ans -= (vis[i] && vis[j]);
        }
    }
    cout << ans << "\n";
}