#include <iostream>
#include <queue>
#define ll long long
using namespace std;
int main()
{
    int n;
    cin >> n;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        pq.push(x);
    }
    ll ans = 0;
    while (pq.size() > 1)
    {
        ll a = pq.top();
        pq.pop();
        ll b = pq.top();
        pq.pop();
        ans += a + b;
        pq.push(a + b);
    }
    cout << ans << "\n";
    return 0;
}