#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> AVL;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int c, k;
        cin >> c >> k;
        AVL bbst;
        while (c--)
        {
            int x;
            cin >> x;
            if (x == 0)
            {
                if (bbst.size() < k)
                {
                    cout << "-1\n";
                }
                else
                {
                    cout << *bbst.find_by_order(k - 1) << "\n";
                }
            }
            else
            {
                bbst.insert(x);
            }
        }
    }
    return 0;
}
