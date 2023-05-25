/*
    Praktikum 4 Struktur Data
    Author: Ainun Nadhifah Syamsiyah
    Problem: AHOCK - A Hunt for Shocker
*/

#include <bits/stdc++.h>
using namespace std;
int cnt[1001];
bool connected[1001][1001];
int main()
{
    int n;
    cin >> n;
    string s;
    while (cin >> s)
    {
        if (s == "Yee!")
            break;
        int a = 0, b;
        for (auto c : s)
        {
            a = 10 * a + (c - '0');
        }
        cin >> b;
        // cout << a << " " << b << "\n";
        if (connected[a][b] && connected[b][a])
            continue;
        connected[a][b] = connected[b][a] = true;
        cnt[a]++;
        cnt[b]++;
    }
    int mx = INT_MIN, mi = INT_MAX, idxmx = INT_MAX, idxmi = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        if (mx < cnt[i])
        {
            mx = cnt[i];
            idxmx = i;
        }
    }
    for (int i = n; i >= 1; i--)
    {
        if (mi > cnt[i])
        {
            mi = cnt[i];
            idxmi = i;
        }
    }
    cout << idxmi << " Targetnya\n";
    cout << idxmx << " Paling Bahaya\n";
    return 0;
}