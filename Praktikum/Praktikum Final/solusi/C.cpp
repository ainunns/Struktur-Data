/*
    Praktikum Final Struktur Data
    Author: Ainun Nadhifah Syamsiyah
    Problem: C - Made In Haven
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            mp[x]++;
        }
        ll sum = 0;
        vector<ll> v;
        for (auto i : mp)
        {
            sum += i.second;
            v.push_back(i.second);
        }
        sort(v.begin(), v.end());
        if (sum < 2 * v[v.size() - 1])
            cout << abs(sum - 2 * v.back()) << "\n";
        else
            cout << sum % 2 << "\n";
    }

    return 0;
}