#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while (cin >> n)
    {
        if (n == 0)
            return 0;
        if (n < 0)
        {
            cout << "Mana ada kartu minus!\n";
            continue;
        }
        deque<int> dq;
        for (int i = 1; i <= n; i++)
        {
            dq.push_back(i);
        }
        vector<int> dc;
        while ((int)dq.size() > 1)
        {
            dc.push_back(dq.front());
            dq.pop_front();
            dq.push_back(dq.front());
            dq.pop_front();
        }
        cout << "Discarded cards:";
        for (int i = 0; i < n - 2; i++)
        {
            cout << " " << dc[i] << ",";
        }
        cout << " " << dc[n - 2] << "\n";
        cout << "Remaining card: " << dq.front() << "\n";
    }
}