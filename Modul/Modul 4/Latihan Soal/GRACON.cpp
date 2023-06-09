#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> v[n + 1];
        vector<bool> vis(n + 1, false);
        while (m--)
        {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        int cc = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                cc++;
                stack<int> st;
                st.push(i);
                vis[i] = true;
                while (!st.empty())
                {
                    int cur = st.top();
                    st.pop();
                    for (auto x : v[cur])
                    {
                        if (!vis[x])
                        {
                            vis[x] = true;
                            st.push(x);
                        }
                    }
                }
            }
        }
        if (cc == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}