#include<stdio.h>
#include<limits.h>
#define MAX 100
int idx = -1;
int pqVal[MAX];
int pqPriority[MAX];
int isEmpty(){
    return idx == -1;
}

int isFull(){
    return idx == MAX - 1;
}
void enqueue(int data, int priority)
{
    if(!isFull()){
        
        idx++;
        pqVal[idx] = data;
        pqPriority[idx] = priority;
    }
}
int peek()
{

    int maxPriority = INT_MIN;
    int indexPos = -1;
 

    for (int i = 0; i <= idx; i++) { 
      
         if (maxPriority < pqPriority[i]) {
            maxPriority = pqPriority[i];
            indexPos = i;
        }
    }
    
    return indexPos;
}

void dequeue()
{
    if(!isEmpty())
    {
        int indexPos = peek();
        printf("%d ",pqVal[indexPos]);

        for (int i = indexPos; i < idx; i++) {
            pqVal[i] = pqVal[i + 1];
            pqPriority[i] = pqPriority[i + 1];
        }
 
        idx--;
    }
}


int main()
{
  
    int a;
    scanf("%d",&a);
    int array[a],arr[a];
    for(int i=0;i<a;i++){
        scanf("%d",&array[i]);
        arr[i]=array[i];

    }
    int f;
    scanf("%d",&f);

    int i,j,k ,size;
    size=a;
    for ( i = 0; i < size; i ++)  
    {  
        for ( j = i + 1; j < size; j++)  
        {  
           
            if ( arr[i] == arr[j])  
            {  
               
                for ( k = j; k < size - 1; k++)  
                {  
                    arr[k] = arr [k + 1];  
                }  
               
                size--;  
                  
                j--;      
            }  
        }  
    }
    int freq[size];
    for(int u=0;u<size;u++){
        freq[u]=0;
        for(int t=0;t<a;t++){
            if(array[t]==arr[u]){
                freq[u]++;
            }
        }
    }  
    for(int l=0;l<size;l++){
        enqueue(arr[l],freq[l]);
    } 
 
   for(int y=0;y<f;y++){
    dequeue();
   }
   printf("\n");
    return 0;
}
