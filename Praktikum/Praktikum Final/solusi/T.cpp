/*
    Praktikum Final Struktur Data
    Author: Ainun Nadhifah Syamsiyah
    Problem: T - Tujuan Hidup Lapet
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, e;
    cin >> n >> e;
    vector<int> adj[n + 1];
    int visited[n + 1] = {0}, dist[n + 1], prev[n + 1];
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dist[1] = 1;
    for (int i = 2; i <= n; i++)
        dist[i] = INT_MAX;
    queue<int> q;
    q.push(1);
    prev[1] = -1;
    visited[1] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = 1;
                dist[v] = dist[u] + 1;
                prev[v] = u;
                q.push(v);
            }
        }
    }
    if (dist[n] == INT_MAX)
        cout << "RIP LAPET 2023\n";
    else
    {
        cout << dist[n] << "\n";
        stack<int> ans;
        while (prev[n] != -1)
        {
            ans.push(n);
            n = prev[n];
        }
        cout << 1;
        while (!ans.empty())
        {
            cout << " " << ans.top();
            ans.pop();
        }
        cout << "\n";
    }
    return 0;
}
