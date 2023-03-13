#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int n;
    stack<pair<int, int>> st;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, mi;
        cin >> a;
        mi = a;
        if (!st.empty())
            mi = min(st.top().second, mi);
        st.push({a, mi});
    }
    while (!st.empty())
    {
        pair<int, int> tp = st.top();
        cout << tp.first << " " << tp.second << "\n";
        st.pop();
    }
    return 0;
}