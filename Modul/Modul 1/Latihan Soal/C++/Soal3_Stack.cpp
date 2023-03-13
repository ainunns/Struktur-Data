#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<string> st;
    st.push("10");
    st.push("4");
    st.push("3");
    st.push("2");
    st.push("9");
    st.push("1");
    st.push("8");
    st.push("7");
    cout << "Stack: \n";
    while (!st.empty())
    {
        cout << st.top() << "\n";
        st.pop();
    }
    cout << "\n";
    return 0;
}