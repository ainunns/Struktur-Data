#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    srand(time(NULL));
    ll timeout = rand() % 10 + 1;
    cout << timeout << "\n";

    ll n=rand()%5+1,t,lp,b,lb;
    for (int i = 1; i <= n; i++)
    {
        t = rand() % 20 + 1;
        lp = rand() % 20 + 1;
        b = rand() % lp + 1;
        lb = rand() % 20 + 1;
        cout << t << " " << lp << " " << b << " " << lb << "\n";
    }
    cout << "-1\n";
    return 0;
}