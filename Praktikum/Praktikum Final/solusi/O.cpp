/*
    Praktikum Final Struktur Data
    Author: Ainun Nadhifah Syamsiyah
    Problem: O - Membuat Peta Harta Karun
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    int matrix[n + 1][n + 1];
    memset(matrix, 0, sizeof(matrix));

    while (m--)
    {
        int x, y;
        cin >> y >> x;

        queue<pair<pair<int, int>, int>> q;
        q.push({{x, y}, 1});
        matrix[x][y] = 1;
        while (!q.empty())
        {
            pair<pair<int, int>, int> p = q.front();
            q.pop();
            int i = p.first.first;
            int j = p.first.second;
            int dist = p.second;
            if (dist == 4)
                continue;
            if (i - 1 >= 1)
            {
                if (matrix[i - 1][j] == 0)
                    matrix[i - 1][j] = dist + 1;
                else
                    matrix[i - 1][j] = min(matrix[i - 1][j], dist + 1);
                q.push({{i - 1, j}, dist + 1});
            }
            if (i + 1 <= n)
            {
                if (matrix[i + 1][j] == 0)
                    matrix[i + 1][j] = dist + 1;
                else
                    matrix[i + 1][j] = min(matrix[i + 1][j], dist + 1);
                q.push({{i + 1, j}, dist + 1});
            }
            if (j - 1 >= 1)
            {
                if (matrix[i][j - 1] == 0)
                    matrix[i][j - 1] = dist + 1;
                else
                    matrix[i][j - 1] = min(matrix[i][j - 1], dist + 1);
                q.push({{i, j - 1}, dist + 1});
            }
            if (j + 1 <= n)
            {
                if (matrix[i][j + 1] == 0)
                    matrix[i][j + 1] = dist + 1;
                else
                    matrix[i][j + 1] = min(matrix[i][j + 1], dist + 1);
                q.push({{i, j + 1}, dist + 1});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}