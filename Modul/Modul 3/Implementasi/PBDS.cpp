#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> AVL;

int main()
{
    AVL X;
    for (int i = 1; i <= 10; i += 2)
        X.insert(i);

    cout << "elemen pada index ke 0 adalah : " << *X.find_by_order(0) << endl;
    cout << "elemen pada index ke 4 adalah : " << *X.find_by_order(4) << endl;

    cout << "jumlah elemen yang lebih kecil dari 6 sebanyak : " << X.order_of_key(6) << endl;
}