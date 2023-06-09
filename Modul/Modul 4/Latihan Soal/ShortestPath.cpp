/*
    Tugas Pengganti Sesi Lab Modul 3
    Author: Ainun Nadhifah Syamsiyah - 5025221053
    Description:
        1. Menerima input n berupa jumlah vertex
        2. Menerima input edge berupa pasangan vertex (nama vertex angka 0 hingga n-1)
        3. Menerima input dua vertex, vertex awal dan vertex tujuan
        4. Memberi output jarak terdekat vertex awal dengan vertex tujuan (jarak berupa banyak edge yang menghubungkan)
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << "Shortest Path between 2 nodex in unweighted and undirected graph" << endl;

    int n, m;
    cout << "Input number of nodes and edges separated by a space: ";
    cin >> n >> m;

    vector<vector<int>> adj(n);
    cout << "Input edges separated by a space: " << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int source, destination;
    cout << "Input source and destination separated by a space: ";
    cin >> source >> destination;

    vector<int> dist(n, INT_MAX);
    dist[source] = 0;

    vector<bool> visited(n, false);
    visited[source] = true;

    queue<int> q;
    q.push(source);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                dist[v] = dist[u] + 1;
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << "Shortest path from " << source << " to " << destination << " is " << dist[destination] << endl;
    return 0;
}