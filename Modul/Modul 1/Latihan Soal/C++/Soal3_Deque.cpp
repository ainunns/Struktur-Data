#include <iostream>
#include <queue>
using namespace std;
int main()
{
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
    return 0;
}