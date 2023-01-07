#include <stdio.h>
int main()
{
    int k, m, n;
    scanf("%d %d", &n, &k);
    m = n / k;

    int a[n];
    int j;
    for (j = 0; j < n; j++)
    {
        scanf("%d", &a[j]);
    }

    int x;
    scanf("%d",&x);

    int f;
    int i;
    int count = 0;

    for (f = 1; f <= m; f++)
    {

        for (i = (f - 1) * n / m; i < f * n / m; i++)
        {
            if (a[i] == x)
            {
                count++;
                break;
            }
        }
    }
    printf("%d",count);
}
