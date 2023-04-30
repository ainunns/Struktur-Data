#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> AVL;

int main()
{
    AVL bst;
    int q;
    cin >> q;
    while (q--)
    {
        long long x, k;
        cin >> x >> k;
        if (x == 1)
        {
            bst.insert(-k);
        }
        else
        {
            if (*bst.find_by_order(bst.order_of_key(-k)) == -k)
                cout << bst.order_of_key(-k) + 1 << endl;
            else
                cout << "Data tidak ada\n";
        }
    }
    return 0;
}
