#include <stdio.h>
void read_and_store(int a[],int n);
void print(int b[],int n);
int digit_sum(int x[],int n);
void digit_sort(int b[],int n);


int main()
{
    int k = 0;
    int n;
    char a;
    int arr[1000];
    int index;
    while (k >= 0)
    {
       
        scanf("%c", &a);
       
        switch (a)
        {
        case 'r':
        {
            scanf("%d", &n);
            arr[n]='\0';
            read_and_store(arr,n);
            break;
        }

       
        case 'p':
            {
                print(arr,n);
                printf("\n");
                break;
            }
           
        case 'd':
            {
                scanf("%d",&index);
                int z=digit_sum(arr,index);
                printf("%d\n",z);
                break;
            }
           
        case 's':
            {
                digit_sort(arr, n);
                break;
            }
           
        case 't':
            printf("-1");
            printf("\n");
            k = -1;
            break;
        }
    }
}

void read_and_store(int a[],int n){
int i;
for ( i = 0; i < n; i++)
{
   scanf("%d",&a[i]);
}

}




void print(int l[],int n){
    int m;
    for ( m = 0; m< n; m++)
    {
        printf("%d ",l[m]);
    }

}

int digit_sum(int x[],int n){
    int temp,b;
    temp=x[n];
    int sum=0;

    while(temp!=0){
        b=temp%10;
        sum=sum+b;
        temp=temp/10;
    }

    return sum;
}

void digit_sort(int b[],int n){
int i,j;
int beta;
int alpha;

for ( i = 1; i < n; i++)
{

   alpha=b[i];
   beta=digit_sum(b,i);
   j=i-1;

   while(j>=0 && digit_sum(b,j)>beta){
    b[j+1]=b[j];
    j=j-1;
   }
   b[j+1]=alpha;

}

}
