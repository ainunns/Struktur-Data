#include <stdio.h>
#include <set>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    set<int> s;
    while (n--)
    {
        int m;
        scanf("%d", &m);
        if (s.find(m) == s.end())
        {
            printf("No ");
            s.insert(m);
        }
        else
            printf("Yes ");
        printf("%d\n", (int)s.size());
    }
    return 0;
}