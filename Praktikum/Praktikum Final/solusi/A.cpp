/*
    Praktikum Final Struktur Data
    Author: Ainun Nadhifah Syamsiyah
    Problem: A - Aceng Pamit Gan
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

map<string, map<string, vector<string>>> mp;
map<string, string> mp2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    while (n--)
    {
        string ip, s;
        cin >> ip >> s;
        mp2[ip] = s;
    }
    while (q--)
    {
        string ip1, ip2, message;
        cin >> ip1 >> ip2;
        getline(cin, message);
        if (mp2[ip1] == "" || mp2[ip2] == "")
            continue;
        mp[ip2][ip1].push_back(message);
    }
    for (auto i : mp)
    {
        cout << "===========\n";
        cout << "Mail: " << mp2[i.first] << "\n";
        for (auto j : i.second)
        {
            cout << "From: " << mp2[j.first] << "\n";
            for (auto k : j.second)
            {
                cout << ">>" << k << "\n";
            }
        }
    }
    return 0;
}