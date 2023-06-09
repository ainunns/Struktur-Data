/*
    Praktikum 1 Struktur Data
    Author: Ainun Nadhifah Syamsiyah
    Problem: PULU - Tumpuccan Si Luccman
*/

#include <bits/stdc++.h>
using namespace std;
int dp[100001][3], a[100001][3];
int main()
{
    int t[3];
    for (int i = 0; i < 3; i++)
        cin >> t[i];
    for (int i = 0; i < 3; i++)
    {
        for (int j = t[i]; j >= 1; j--)
            cin >> a[j][i];
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 1; j <= t[i]; j++)
            dp[j][i] = dp[j - 1][i] + a[j][i];
    }
    int ans = 0;
    for (int i = 1; i <= t[0]; i++)
    {
        bool flag[3] = {0};
        for (int j = 1; j <= 2; j++)
        {
            int l = 1, r = t[j], mid;
            while (l <= r)
            {
                mid = (l + r) / 2;
                if (dp[mid][j] == dp[i][0])
                {
                    flag[j] = true;
                    break;
                }
                else if (dp[mid][j] > dp[i][0])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }
        if (flag[1] && flag[2])
            ans = max(ans, dp[i][0]);
    }
    cout << ans << "\n";
}