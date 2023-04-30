#include <stdio.h>
#include <queue>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        q.push(x);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        while (!q.empty())
        {
            int fr = q.front();
            q.pop();
            ans++;
            if (fr != x)
                q.push(fr);
            else
                break;
        }
    }
    printf("%d\n", ans);
    return 0;
}