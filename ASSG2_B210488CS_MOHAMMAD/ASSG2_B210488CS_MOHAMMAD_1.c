#include <stdio.h>

int check(char c, int x, int y[], char p[])
{
    int i;
    for (i = 0; i <= x; i++)
    {
        if (p[i] == c)
        {
            y[i]++;
            return 0;
        }
    }
    if (i > x)
        return 1;
    return 0;
}
int strln(char a[1000])
{
    int count = 0;
    for (int i = 0; a[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

int main()
{
    char input[1000];
    char store[1000];
    int count[1000];
    scanf("%s", input);
    int l;
    l = strln(input);
    int a, b;
    b = 0;
    store[0] = input[0];
    count[0] = 1;

    for (int j = 1; j < l; j++)
    {
        if (check(input[j], b, count, store))
        {
            b++;
            store[b] = input[j];
            count[b] = 1;
        }
    }
    int multiply = 1;
    for (int y = 0; y <= b; y++)
    {
        multiply = multiply * count[y];
    }
    printf("%d", multiply);
}
