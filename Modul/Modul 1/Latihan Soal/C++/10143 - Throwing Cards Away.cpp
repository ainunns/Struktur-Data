#include <stdio.h>
#include <queue>
using namespace std;
int main()
{
    int n;
    while (scanf("%d", &n) == 1)
    {
        if (n == 0)
            break;
        queue<int> q;
        for (int i = 1; i <= n; i++)
            q.push(i);
        printf("Discarded cards:");
        while (q.size() > 1)
        {
            printf(" %d", q.front());
            q.pop();
            q.push(q.front());
            q.pop();
            if (q.size() > 1)
                printf(",");
        }
        printf("\nRemaining card: %d\n", q.front());
    }
    return 0;
}