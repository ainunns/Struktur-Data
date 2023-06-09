/*
    Praktikum Final Struktur Data
    Author: Ainun Nadhifah Syamsiyah
    Problem: R - Player Muak Linked List
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    cin >> a >> b;
    int c[1005], d[1005];
    memset(c, 0, sizeof(c));
    memset(d, 0, sizeof(d));
    for (int i = a - 1; i >= 0; i--)
        cin >> c[i];
    for (int i = b - 1; i >= 0; i--)
        cin >> d[i];
    int dum = 0;
    for (int i = 0; i < 1003; i++)
    {
        int temp = c[i] + d[i] + dum;
        dum = temp / 10;
        c[i] = temp % 10;
    }
    int i = 1003;
    while (c[i] == 0)
        i--;
    while (i >= 0)
    {
        cout << c[i--];
    }
    cout << "\n";
    return 0;
}