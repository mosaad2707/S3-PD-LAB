#include <stdio.h>
#include <stdlib.h>
struct node
{
    long int key;
    struct node *next;
};
struct QUEUE
{
    struct node *head;
    struct node *tail;
};
int QUEUE_EMPTY(struct QUEUE *Q)
{
    if (Q->head == NULL)
        return -1;
    else
        return 1;
}
struct node *create_node(long int k)
{
    struct node *x;
    x = (struct node *)malloc(sizeof(struct node));
    x->next = NULL;
    x->key = k;
    return x;
}

void ENQUEUE(struct QUEUE *Q, struct node *x)
{
    long int k;
    scanf("%ld", &k);
    x = create_node(k);
    if (Q->head == NULL)
        Q->head = x;
    else
        Q->tail->next = x;
    Q->tail = x;
    
}
void DEQUEUE(struct QUEUE *Q)
{
    if (QUEUE_EMPTY(Q) == -1)
        printf("Empty ");
    else
    {
        printf("%ld ", Q->head->key);
        Q->head = Q->head->next;
    }
}

int main()
{
    char op;
    struct QUEUE *Q;
    struct node *x;
    long int l;

    Q = (struct QUEUE *)malloc(sizeof(struct QUEUE));

    scanf("%c", &op);
    Q->head = NULL;
    Q->tail = NULL;
    while (op != 't')
    {
        switch (op)
        {
        case 'i':
            ENQUEUE(Q, x);
            break;
        case 'd':
        {
            scanf("%ld", &l);
            while (l-- > 0)
            {
                DEQUEUE(Q);
            }
            printf("\n");
            break;
        }

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
        }
        scanf("%c", &op);
    }
    return 0;
}
