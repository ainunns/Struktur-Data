#include <iostream>
#include <queue>
using namespace std;
int main()
{
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