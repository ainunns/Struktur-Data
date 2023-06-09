/*
    Praktikum Final Struktur Data
    Author: Ainun Nadhifah Syamsiyah
    Problem: N - Kabel Milik Adit
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    stack<int> st;

    while (n--)
    {
        int x;
        cin >> x;
        if (st.empty())
        {
            if (x == 1)
                st.push(1);
            st.push(0);
        }
        else if (st.size() == 1)
        {
            if (st.top() == 0)
            {
                if (x == 0)
                    st.pop();
            }
            else
            {
                if (x == 1)
                    st.pop();
                else
                    st.push(0);
            }
        }
        else if (st.top() == 0)
        {
            st.pop();
            if (x == 1)
            {
                st.push(1);
                st.push(0);
                st.push(1);
                st.push(0);
            }
        }
        else
        {
            if (x == 0)
                st.push(0);
            else
                st.pop();
        }
    }
    cout << (int)st.size() << endl;
    return 0;
}