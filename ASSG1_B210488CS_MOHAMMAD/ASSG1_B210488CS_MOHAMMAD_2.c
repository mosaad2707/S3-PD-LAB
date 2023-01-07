#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int array[n];
    
    for(int i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    int r;
    scanf("%d",&r);
    while(r>0){

        int h;
        int temp;
        temp=array[0];
        // printf("%d test 0",temp);
        for(int k=0;k<n-1;k++){
            // printf("%d test1\n",array[k]);
            array[k]=array[k+1];
            // printf("%d test2\n",array[k]);
        }
        array[n-1]=temp;
        // printf("%d test3",array[n-1]);




        r--;

    }
    for(int u=0;u<n;u++){
        printf("%d ",array[u]);
    }   
return 0;
}