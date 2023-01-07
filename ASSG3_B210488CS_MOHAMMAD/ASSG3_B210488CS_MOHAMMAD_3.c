#include <stdio.h>

int mystrlen(char arr[])
{
    int count = 0;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

// void copy(char a[], char b[])
// {
//     while (*a++ = *b++)
//     ;
// }

char *copy(char *final, const char *initial)
{
    if (final == NULL)
    {
        return NULL;
    }
    char *ptr = final;
    while (*initial != '\0')
    {
        *final = *initial;
        final++;
        initial++;
    }
    *final = '\0';
    return ptr;
}
int compare(const char *p1, const char *p2)
{
  const unsigned char *s1 = (const unsigned char *) p1;
  const unsigned char *s2 = (const unsigned char *) p2;
  unsigned char c1, c2;
  do
    {
      c1 = (unsigned char) *s1++;
      c2 = (unsigned char) *s2++;
      if (c1 == '\0')
        return c1 - c2;
    }
  while (c1 == c2);
  return c1 - c2;
}
// int compare(char *s1, char *s2)
// {
//     int i;
//     for (i = 0; s1[i] && s2[i]; ++i)
//     {

//         if (s1[i] == s2[i] || (s1[i] ^ 32) == s2[i])
//             continue;
//         else
//             break;
//     }

//     if (s1[i] == s2[i])
//         return 0;

//     if ((s1[i] | 32) < (s2[i] | 32))
//         return -1;
//     return 1;
// }

void Merge(char arr[][100], int low, int mid, int high)
{
    int gamma = mid - low + 1;
    int delta = high - mid;

    char L[100][100];
    char R[100][100];
    int i;
    for (i = 0; i < gamma; i++)
    {
        copy(L[i], arr[low + i]);
    }
    for (i = 0; i < delta; i++)
    {
        copy(R[i], arr[mid + i + 1]);
    }
    int j = 0, k;
    i = 0;
    k = low;
    while (i < gamma && j < delta)
    {
        if (compare(L[i], R[j]) < 0)
        {
            copy(arr[k], L[i]);
            i++;
        }

        else
        {
            copy(arr[k], R[j]);
            j++;
        }
        k++;
    }
    while (i < gamma)
    {
        copy(arr[k], L[i]);
        i++;
        k++;
    }
    while (j < delta)
    {
        copy(arr[k], R[j]);
        k++;
        j++;
    }
}

void MergeSort(char arr[][100], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        Merge(arr, low, mid, high);
    }
}

int main()
{
    int n;
    scanf("%d\n", &n);

    char arr[n][100];
    int i;
    for (i = 0; i < n; i++)
    {
        fgets(arr[i], 100, stdin);
    }

    for(int u=0;u<n;u++){
        arr[u][mystrlen(arr[u])-1]='\0';
    }

    MergeSort(arr, 0, n - 1);


    for (i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    return 0;
}

