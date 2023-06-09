/*
    Praktikum Final Struktur Data
    Author: Ainun Nadhifah Syamsiyah
    Problem: M - Liburan Ersya
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<char> st;
    string s;
    cin >> s;
    for (auto c : s)
    {
        if (c == '(' || c == '{' || c == '[')
            st.push(c);
        else
        {
            if (st.empty())
            {
                cout << "unvaldi\n";
                return 0;
            }
            if (c == ')' && st.top() != '(')
            {
                cout << "unvaldi\n";
                return 0;
            }
            if (c == '}' && st.top() != '{')
            {
                cout << "unvaldi\n";
                return 0;
            }
            if (c == ']' && st.top() != '[')
            {
                cout << "unvaldi\n";
                return 0;
            }
            st.pop();
        }
    }
    if (st.empty())
        cout << "valdi\n";
    else
        cout << "unvaldi\n";
    return 0;
}