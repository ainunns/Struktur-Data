#include <bits/stdc++.h>
#define piis pair<pair<int, int>, string>
using namespace std;
int main()
{
    priority_queue<piis, vector<piis>, greater<piis>> pq;
    int n, m;
    cin >> n >> m;
    while (n--)
    {
        string name;
        int d, mn;
        cin >> name >> d >> mn;
        pq.push({{mn, d}, name});
    }
    while (m--)
        pq.pop();
    if (pq.empty())
    {
        cout << "Miko TOP G\n";
        return 0;
    }
    cout << "Waifu selanjutnya adalah " << pq.top().second << " chan\n";
    return 0;
}