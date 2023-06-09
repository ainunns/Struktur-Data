/*
    Praktikum Final Struktur Data
    Author: Ainun Nadhifah Syamsiyah
    Problem: D - Due sang Teknisi
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int timeout;
    cin >> timeout;

    vector<tuple<int, int, int, int, int>> v;
    tuple<int, int, int, int, int, int, int> kosong = {-1, -1, -1, -1, -1, -1, -1}, prod = kosong;
    priority_queue<tuple<int, int, int, int, int, int>, vector<tuple<int, int, int, int, int, int>>, greater<tuple<int, int, int, int, int, int>>> pq;
    int ti, no = 1, lp, b, lb, time, status;
    while (cin >> ti)
    {
        if (ti == -1)
            break;
        cin >> lp >> b >> lb;
        pq.push({ti, no++, lp, b, lb, 0});
    }

    int idx = 0, t = get<0>(pq.top());
    while (true)
    {
        if (pq.empty() && prod == kosong)
            break;
        if (prod == kosong)
        {
            tie(ti, no, lp, b, lb, status) = pq.top();
            prod = {ti, no, lp, b, lb, timeout, status};
            cout << max(ti, t) << ": Mesin mengerjakan produk " << get<1>(prod) << "\n";
            pq.pop();
        }
        // cout << ti << " " << t << "\n";
        tie(ti, no, lp, b, lb, time, status) = prod;
        if (lp == 0)
        {
            cout << max(ti, t) << ": Mesin menyelesaikan produk " << get<1>(prod) << "\n";
            prod = kosong;
            continue;
        }
        if (b == 0 && status == 0)
        {
            cout << max(ti, t) << ": Mesin memblokir produk " << get<1>(prod) << "\n";
            prod = kosong;
            pq.push({t + lb, no, lp, 0, 0, 1});
            continue;
        }
        if (time == 0)
        {
            cout << max(ti, t) << ": Mesin mengembalikan produk " << get<1>(prod) << "\n";
            prod = kosong;
            pq.push({max(ti, t), no, lp, b, lb, status});
            continue;
        }
        prod = {max(ti, t) + 1, no, lp - 1, max(b - 1, 0), lb, time - 1, status};
        t = max(ti, t) + 1;
    }
    return 0;
}