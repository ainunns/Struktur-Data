#include <iostream>
#include <queue>
using namespace std;
int main()
{
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
    return 0;
}