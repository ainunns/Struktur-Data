/*
    Praktikum Final Struktur Data
    Author: Ainun Nadhifah Syamsiyah
    Problem: B - Z
*/

#include <bits/stdc++.h>
#define ll long long
#define PI acos(-1)
using namespace std;

int tc, n;
double dist[3001];
bool vis[3001];
tuple<double, double, double> roda[3001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (cin >> tc)
    {
        if (tc == -1)
            break;
        for (int i = 1; i <= tc; i++)
        {
            double x, y, r;
            cin >> x >> y >> r;
            roda[i] = {r, x, y};
            vis[i] = false;
            dist[i] = DBL_MAX;
        }
        dist[1] = 0.0;
        while (true)
        {
            int u = -1;
            double mi = DBL_MAX;
            for (int i = 1; i <= tc; i++)
            {
                if (!vis[i] && dist[i] < mi)
                {
                    mi = dist[i];
                    u = i;
                }
            }
            if (u == -1)
                break;
            vis[u] = true;
            for (int i = 1; i <= tc; i++)
            {
                if (u == i || vis[i])
                    continue;
                double x_1, y_1, r_1, x_2, y_2, r_2;
                tie(r_1, x_1, y_1) = roda[u];
                tie(r_2, x_2, y_2) = roda[i];
                double distance = sqrt((x_2 - x_1) * (x_2 - x_1) + (y_2 - y_1) * (y_2 - y_1));
                double hypo = sqrt(distance * distance - (r_2 - r_1) * (r_2 - r_1));
                double alpha = asin(abs(r_2 - r_1) / distance);
                double weight = PI * (r_1 + r_2) + 2 * hypo + 2 * alpha * abs(r_2 - r_1);
                dist[i] = min(dist[i], weight);
            }
        }
        double ans = 0.0;
        for (int i = 1; i <= tc; i++)
        {
            ans += dist[i];
        }
        cout << fixed << setprecision(3) << ans << "\n";
    }

    return 0;
}