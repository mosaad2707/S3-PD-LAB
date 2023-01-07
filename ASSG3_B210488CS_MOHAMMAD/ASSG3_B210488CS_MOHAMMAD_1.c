#include<stdio.h>

void insort(float x[],int n){
int i,j;
float alpha;

for(i=1;i<n;i++){
    alpha=x[i];
    j=i-1;
    while (j>=0 && x[j]>alpha)

    {
       x[j+1]=x[j];
       j=j-1;
    }
    x[j+1]=alpha;
    
}
}

int main(){
    int i,n;
    scanf("%d",&n);
    float input[n];
    float store[n];

    for(int f=0;f<n;f++){
        store[f]='\0';
    }



    for ( i = 0; i < n; i++)
    {
        scanf("%f",&input[i]);
    }
    
    for (int h = 0;h < n; h++)
    {
       store[h]=input[h];
    }
    
    

    insort(input,n); 
    for ( int j= 0;j< n; j++)
    {
        for(int k=0;k<n;k++){
        if((float)store[j]==(float)input[k]){
        printf("%d ",k);
        }
        
        }
    }
    printf("\n");
    return 0;
    
   

}
