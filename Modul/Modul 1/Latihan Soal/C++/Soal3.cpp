#include <iostream>
#include <queue>
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
    queue<string> q;
    q.push("10");
    q.push("4");
    q.push("3");
    q.push("2");
    q.push("9");
    q.push("1");
    q.push("8");
    q.push("7");
    cout << "Queue: \n";
    while (!q.empty())
    {
        cout << q.front() << "\n";
        q.pop();
    }
    cout << "\n";
    deque<string> dq;
    dq.push_front("10");
    dq.push_front("4");
    dq.push_front("3");
    dq.push_front("2");
    dq.push_front("9");
    dq.push_front("1");
    dq.push_front("8");
    dq.push_front("7");
    cout << "Deque: \n";
    while (!dq.empty())
    {
        cout << dq.back() << "\n";
        dq.pop_back();
    }
    cout << "\n";
    priority_queue<string> pq;
    pq.push("10");
    pq.push("4");
    pq.push("3");
    pq.push("2");
    pq.push("9");
    pq.push("1");
    pq.push("8");
    pq.push("7");
    cout << "Priority Queue: \n";
    while (!pq.empty())
    {
        cout << pq.top() << "\n";
        pq.pop();
    }
    cout << "\n";
    return 0;
}