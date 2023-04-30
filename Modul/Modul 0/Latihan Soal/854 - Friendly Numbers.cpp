#include <iostream>
using namespace std;
typedef long long ll;
const ll MX = 1e6 + 1;
ll sumDiv[MX];
int main()
{
    for (ll i = 1; i < MX; ++i)
    {
        for (ll j = i; j < MX; j += i)
            sumDiv[j] += i;
    }
    ll m, n;
    cin >> m >> n;
    bool ada = false;
    for (ll i = m; i <= n; i++)
    {
        ll x = sumDiv[i] - i;
        if (x > n || x < m)
            continue;
        ll y = sumDiv[x] - x;
        if (y == i && i < x)
        {
            ada = true;
            cout << i << " " << x << endl;
        }
    }
    if (!ada)
        cout << "Absent\n";
    return 0;
}