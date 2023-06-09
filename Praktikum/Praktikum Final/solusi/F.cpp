/*
    Praktikum Final Struktur Data
    Author: Ainun Nadhifah Syamsiyah
    Problem: F - Alkae, Kaela, dan Marie Jois
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MX = 1e5 + 4;

map<pair<int, int>, int> mp;
int n, m, co[MX], par[MX], sz[MX];
priority_queue<pair<int, int>> pq[MX];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq2[MX];

int find(int x)
{
    if (par[x] == x)
        return x;
    return par[x] = find(par[x]);
}

void join(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return;
    if (sz[a] < sz[b])
        swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
        sz[i] = 1;
        cin >> co[i];
    }

    while (m--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        if (a > b)
            swap(a, b);
        join(a, b);
        int p = find(a);
        pq2[p].push({w, {a, b}});
        mp[{a, b}] = w;
    }

    for (int i = 1; i <= n; i++)
    {
        int p = find(i);
        pq[p].push({co[i], i});
    }

    int q;
    cin >> q;
    while (q--)
    {
        int qu;
        char c;
        cin >> c >> qu;
        if (c == '!')
        {
            if (qu == 1)
            {
                int a, x;
                cin >> a >> x;
                int p = par[a];
                co[a] = x;
                pq[p].push({x, a});
                while (!pq[p].empty() && pq[p].top().first != co[pq[p].top().second])
                    pq[p].pop();
            }
            else if (qu == 2)
            {
                int a, b, x;
                cin >> a >> b >> x;
                if (a > b)
                    swap(a, b);
                int p = par[a];
                pq2[p].push({x, {a, b}});
                mp[{a, b}] = x;
                while (!pq2[p].empty() && pq2[p].top().first != mp[pq2[p].top().second])
                    pq2[p].pop();
            }
        }
        else if (c == '?')
        {
            if (qu == 1)
            {
                int a;
                cin >> a;
                int p = find(a);
                if (pq2[p].empty())
                    cout << "0\n";
                else
                    cout << pq2[p].top().first << "\n";
            }
            else if (qu == 2)
            {
                int a, b;
                cin >> a >> b;
                if (a > b)
                    swap(a, b);

                int x = find(a), y = find(b);
                if (x == y)
                    cout << "0\n";
                else
                    cout << pq[x].top().first + pq[y].top().first << "\n";
            }
        }
    }
    return 0;
}