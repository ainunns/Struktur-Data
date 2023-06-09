/*
    Praktikum Final Struktur Data
    Author: Ainun Nadhifah Syamsiyah
    Problem: Q - Makan Apa Hari Ini
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll v;
    cin >> v;

    string s[v + 1];
    ll p[v + 1];
    for (int i = 1; i <= v; i++)
    {
        cin >> s[i] >> p[i];
    }

    ll e;
    cin >> e;
    vector<pair<ll, ll>> adj[v + 1];
    for (int i = 0; i < e; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    ll dist[v + 1];
    dist[0] = 0;
    for (int i = 1; i <= v; i++)
    {
        dist[i] = INT_MAX;
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 0});
    while (!pq.empty())
    {
        ll u = pq.top().second;
        pq.pop();

        for (auto i : adj[u])
        {
            ll v = i.first;
            ll w = i.second;

            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    ll d;
    cin >> d;

    ll ans = LLONG_MAX;
    string ans_s = "";
    for (int i = 1; i <= v; i++)
    {
        if (d >= dist[i] && ans > p[i] && dist[i] != INT_MAX)
        {
            ans = p[i];
            ans_s = s[i];
        }
    }
    cout << "hari ini makan di " << ans_s << "\n";

    return 0;
}