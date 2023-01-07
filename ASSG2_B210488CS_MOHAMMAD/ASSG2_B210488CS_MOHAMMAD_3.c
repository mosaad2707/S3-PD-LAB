#include <stdio.h>

int main()
{ 
    int N;
    scanf("%d\n",&N);
    int a[N];
   int z;
   for (int i = 0; i <N; i++)
   {
    scanf("%d", &a[i]);

   }

   int max=a[0];
   int temp=a[0];

   for (int i =0; i < N; ++i)
   { 
    if (a[i]>max)
    {
        temp=max;
        max=a[i];
    }
    else if(a[i]>temp &&a[i]!=max){
        temp=a[i];
    }
   }
   if(temp==max){
    for (int i = 0; i < N; i++)
   { 
    
        printf("%d ",a[i]);
    }

   }
   for (int i = 0; i < N; i++)
   { 
    if(a[i]!=temp){
        printf("%d ",a[i]);
    
    }
   }
   printf("\b");


    return 0;

}


