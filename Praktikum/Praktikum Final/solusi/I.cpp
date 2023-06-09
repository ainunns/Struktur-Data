/*
    Praktikum Final Struktur Data
    Author: Ainun Nadhifah Syamsiyah
    Problem: I - Namanya juga Usaha
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> road[n];
    int u, v;
    while (cin >> u >> v)
    {
        if (u == v && u == -1)
            break;
        road[u].push_back(v);
    }
    for (int i = 0; i < n; i++)
    {
        int danger[n], vis[n];
        for (int i = 0; i < n; i++)
        {
            vis[i] = 0;
            danger[i] = 1e9;
        }
        queue<int> q;
        q.push(i);
        danger[i] = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto v : road[u])
            {
                if (!vis[v])
                {
                    vis[v] = 1;
                    danger[v] = danger[u] + 1;
                    q.push(v);
                }
            }
        }
        if (danger[i] == 0)
            cout << "gak bisa pulang mamah\n";
        else
            cout << danger[i] << "\n";
    }
    return 0;
}