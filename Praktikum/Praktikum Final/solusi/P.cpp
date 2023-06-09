/*
    Praktikum Final Struktur Data
    Author: Ainun Nadhifah Syamsiyah
    Problem: P - Dayat And Venturians
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m;
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
char mp[101][101], rm[101][101];

bool check(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y)
{
    if (mp[x][y] == 'O')
        rm[x][y] = 'O';
    mp[x][y] = 'X';
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (!check(nx, ny) || mp[nx][ny] == 'X')
            continue;
        dfs(nx, ny);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> mp[i][j];
            rm[i][j] = mp[i][j];
            if (rm[i][j] == 'O')
                rm[i][j] = 'X';
        }

    for (int i = 0; i < n; i++)
    {
        if (mp[i][0] != 'X')
            dfs(i, 0);
        if (mp[i][m - 1] != 'X')
            dfs(i, m - 1);
    }

    for (int i = 0; i < m; i++)
    {
        if (mp[0][i] != 'X')
            dfs(0, i);
        if (mp[n - 1][i] != 'X')
            dfs(n - 1, i);
    }

    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
            if (mp[i][j] == '^')
                dfs(i, j);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << rm[i][j];
        cout << endl;
    }

    return 0;
}