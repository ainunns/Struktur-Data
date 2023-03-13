#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int q;
    cin >> q;
    priority_queue<pair<int, int>> pq;
    string patient[q + 1];
    for (int i = 0; i < q; i++)
    {
        string cmd;
        cin >> cmd;
        if (cmd[0] == 'M')
        {
            int urg;
            cin >> patient[i] >> urg;
            pq.push({urg, -i});
        }
        else
        {
            if (!pq.empty())
            {
                cout << patient[-pq.top().second] << "\n";
                pq.pop();
            }
            else
            {
                cout << "HORE\n";
            }
        }
    }
    return 0;
}