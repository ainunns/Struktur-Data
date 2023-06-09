/*
    Praktikum 1 Struktur Data
    Author: Ainun Nadhifah Syamsiyah
    Problem: LT - Langkah Terjauh
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        string s;
        cin >> s;
        int len = s.length(), cur = 0, ans = 0;
        stack<int> st;
        st.push(-1);
        for (int i = 0; i < len; i++)
        {
            if (s[i] == 'F')
            {
                st.push(i);
            }
            else if (s[i] == 'B')
            {
                if (!st.empty())
                    st.pop();
                if (!st.empty())
                    ans = max(ans, i - st.top());
                else
                    st.push(i);
            }
        }
        cout << ans << "\n";
    }
}

/*
14
BBFFFBFFBFBB
FFBFBFF
BFBFFBBBB
FFBFBFBFBFBFBFFBBB
BFBF
FBBF
FBFB
FFFBBB
BB
BF
FFBFBFBB
FBFBBBFBFBFB
FB
FFFFFBBFFBBBFFB
*/