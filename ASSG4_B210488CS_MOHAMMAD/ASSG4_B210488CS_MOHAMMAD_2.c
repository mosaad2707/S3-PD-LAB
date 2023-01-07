 #include <stdio.h>
  static int count=0;
  void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  
  void heapify(int arr[], int n, int i) {
    int max = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
  
    if(l<n){
        count++;
    }
    if (l < n && arr[l] > arr[max])
      max = l;
    if(r<n){
        count++;
    }
    if (r < n && arr[r] > arr[max])
      max = r;
  
    if (max != i) {
      swap(&arr[i], &arr[max]);
      heapify(arr, n, max);
    }
  }
  void buildmax(int arr[],int N){
    for(int i=N/2-1;i>=0;i--){
        heapify(arr,N,i);
    }
}
  

  void heapSort(int arr[], int n) {

   buildmax(arr,n);
  
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);

      heapify(arr, i, 0);
    }
  }
  
  void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
      printf("%d ", arr[i]);
    printf("\n");
  }
  
  int main() {
   int N;
    scanf("%d ",&N);
    int arr[N];
    
    for(int i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    heapSort(arr, N);
   
    printArray(arr, N);
     printf("%d\n",count);
  }
  
