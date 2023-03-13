#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        string s;
        cin >> n >> s;
        stack<char> st;
        for (int i = 0; i < n; i++)
        {
            if (!st.empty() && st.top() == '(' && s[i] == ')')
                st.pop();
            else
                st.push(s[i]);
        }
        cout << (int)st.size() / 2 << "\n";
    }
}