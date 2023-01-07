#include <stdio.h>

int BinarySearch(int A[], int m, int n, int k)
{
    int mid;
    mid =(m + n) / 2;
    if(m>n){
        return -1;

    }
    
    else if (A[mid] == k)
    {

        return mid;
    }
    else if (m > n)
    {
        return -1;
    }
    else if (k < A[mid])
    {

       return BinarySearch(A, m, mid - 1, k);
    }
    else if (k > A[mid])
    {
       return BinarySearch(A, mid + 1, n, k);
    }
}

int main()
{
    int a, b, c;
    scanf("%d %d", &a, &b);

    int arr[a];
    for (int i = 0; i < a; i++)
    {
        scanf("%d", &arr[i]);
    }
    int l;
    l = BinarySearch(arr, 0, a-1, b);

     
printf("%d\n", l );
    if (l==a-1)
        {
           printf("-1");
           return 0;

        }
    if(l==-1){
        printf("-1");
        return 0;
    }    
    for (int j = l; j < a; j++)
    {
        
        
        if (arr[j] == b)
        {
            continue;
        }

        printf("%d ", j);
    }
    printf("\b");

    return 0;
}
