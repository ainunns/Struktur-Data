#include <iostream>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    long long ans = 0, sum = 0, a, mx = -1e9;
    bool ada = false;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a);
        ada |= (a >= 0);
        mx = max(mx, a);
        sum = max(0ll, sum + a);
        ans = max(ans, sum);
    }
    if (ans == 0 && !ada)
        ans = mx;
    printf("%lld\n", ans);
}