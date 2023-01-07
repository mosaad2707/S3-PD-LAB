

#include <stdio.h>
void swap(float* a, float* b)
{

	float temp = *a;

	*a = *b;

	*b = temp;
}


void heapify(float arr[], int N, int i)
{
	
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < N && arr[left] > arr[largest])

		largest = left;
	if (right < N && arr[right] > arr[largest])

		largest = right;
	if (largest != i) {

		swap(&arr[i], &arr[largest]);

		heapify(arr, N, largest);
	}
}i

void heapSort(float arr[], int N)
{

	for (int i = N / 2 - 1; i >= 0; i--)

		heapify(arr, N, i);
	for (int i = N - 1; i >= 0; i--) {

		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}
int main()
{
    int N, Y;
    scanf("%d %d", &N, &Y);
    float arr[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%f", &arr[i]);
    }
    int i, j, k, l;
    l = 0;
    float array[Y];
    for (i = 0; i < (N / Y); i++)
    {
        k = 0;
        for (j = l; k < Y; j++)
        {
            array[k] = arr[j];
            k++;
        }

        l = l + Y;
        heapSort(array, k);
        printf("%0.2f ", array[k - 1]);
    }
    printf("\n");
}
