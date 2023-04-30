#include <iostream>
#include <deque>
#include <map>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    map<int, int> teammate;
    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;
        for (int j = 1; j <= n; j++)
        {
            int id;
            cin >> id;
            teammate[id] = i;
        }
    }
    deque<pair<int, int>> dq;
    string command;
    while (cin >> command)
    {
        if (command == "ENQUEUE")
        {
            int id;
            cin >> id;
            deque<pair<int, int>>::iterator it = dq.begin();
            while (it != dq.end() && teammate[it->first] != teammate[id])
                it++;
            if (it == dq.end())
                dq.push_back({id, teammate[id]});
            else
            {
                while (it != dq.end() && teammate[it->first] == teammate[id])
                    it++;
                dq.insert(it, {id, teammate[id]});
            }
        }
        else if (command == "DEQUEUE")
        {
            cout << dq.front().first << '\n';
            dq.pop_front();
        }
    }
    return 0;
}