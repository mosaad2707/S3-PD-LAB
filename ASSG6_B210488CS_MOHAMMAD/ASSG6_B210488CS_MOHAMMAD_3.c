#include <stdio.h>
#include <stdlib.h>
struct QUEUE
{
    long int arr[10000];
    int size;
    int head;
    int tail;
};

int QUEUE_EMPTY(struct QUEUE *Q)
{
    if (Q->head == -1)
        return -1;
    else
        return 1;
}
int QUEUE_FULL(struct QUEUE *Q)
{
    if ((Q->tail == Q->size - 1 && Q->head == 0) || Q->tail == Q->head - 1 || Q->size == 0)
        return -1;
    else
        return 1;
}
void ENQUEUE(struct QUEUE *Q, long int k)
{
    if (QUEUE_FULL(Q) == -1)
        printf("Full\n");
    else if (Q->head == -1)
    {
        Q->head = Q->tail = 0;
        Q->arr[Q->tail] = k;
    }
    else if (Q->tail == Q->size - 1 && Q->head != 0)
    {
        Q->tail = 0;
        Q->arr[Q->tail] = k;
    }
    else
    {
        Q->tail++;
        Q->arr[Q->tail] = k;
    }
}
void DEQUEUE(struct QUEUE *Q)
{

    {
        if (QUEUE_EMPTY(Q) == -1)
            printf("Empty ");
        else
        {
            printf("%ld ", Q->arr[Q->head]);
            if (Q->head == Q->tail)
                Q->head = Q->tail = -1;
            else if (Q->head == Q->size - 1)
                Q->head = 0;
            else
                Q->head++;
        }
    }
}

int main()
{
    char op;
    struct QUEUE *Q;
    int n;
    long int l;

    Q = (struct QUEUE *)malloc(sizeof(struct QUEUE));
    scanf("%d", &(n));
    Q->size=n-1;
    long int k;
    scanf("%c", &op);
    Q->head = -1;
    Q->tail = -1;
    while (op != 't')
    {
        switch (op)
        {
        case 'i':
            scanf("%ld", &k);
            ENQUEUE(Q, k);
            break;
        case 'd':
          scanf("%ld", &l);
            while (l-- > 0)
            {
                DEQUEUE(Q);
            }
            printf("\n");
            break;
        case 'e':
        {
            if (QUEUE_EMPTY(Q) == -1)
            {
                printf("YES\n");
                break;
            }
            else if (QUEUE_EMPTY(Q) == 1)
            {
                printf("NO\n");
                break;
            }
        }
        case 'f':
        {
            if (QUEUE_FULL(Q) == -1)
            {
                printf("YES\n");
                break;
            }
            else if (QUEUE_FULL(Q) == 1)
            {
                printf("NO\n");
                break;
            }
        }
        }
        scanf("%c", &op);
    }
    return 0;
}
