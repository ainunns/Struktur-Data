#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int danger[n + 1];
    for (int i = 1; i <= n; i++)
        danger[i] = INT_MAX;
    vector<pair<int, int>> road[n + 1];
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        road[u].push_back({v, w});
        road[v].push_back({u, w});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    danger[1] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for (auto i : road[u])
        {
            int v = i.first;
            int w = i.second;
            if (danger[v] > max(danger[u], w))
            {
                danger[v] = max(danger[u], w);
                pq.push({danger[v], v});
            }
        }
    }
    cout << danger[n] << endl;
    return 0;
}