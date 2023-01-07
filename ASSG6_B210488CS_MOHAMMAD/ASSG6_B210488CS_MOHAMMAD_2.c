#include <stdio.h>
#include <stdlib.h>
struct node
{
    long int data;
    struct node *next;
    struct node *top;
};

int STACK_EMPTY(struct node *s)
{
    if (s->top == NULL)
        return -1;
    else
        return 1;
}
struct node *CREATE_NODE(long int k)
{
    struct node *x;
    // printf("check1");
    x = (struct node *)malloc(sizeof(struct node));
    x->next = NULL;
    x->data = k;
    return x;
}
void PUSH(struct node *s, struct node *x)
{
    long int k;
    scanf("%ld", &k);
    // printf("check2");
    x = CREATE_NODE(k);
    x->next = s->top;
    s->top = x;
}
void POP(struct node *s, long int k)
{
    while (k-- > 0)
    {
        if (STACK_EMPTY(s) == -1)
            printf("Empty ");
        else
        {

            printf("%ld ", s->top->data);
            s->top = s->top->next;
        }
    }
    printf("\n");
}

int main()
{
    char op;
    struct node *x;
    struct node *s;
    long int l;
    // printf("check");
    s = (struct node *)malloc(sizeof(struct node));
    long int k;
    scanf("%c", &op);
    s->top = NULL;
    while (op != 't')
    {
        switch (op)
        {
        case 'i':
        {
            PUSH(s, x);
            break;
        }
        case 'd':
        {
            scanf("%ld", &l);
            POP(s, l);
        }
        break;
        case 'e':
        {
            if (STACK_EMPTY(s) == -1)
            {
                printf("YES\n");
                break;
            }
            else if (STACK_EMPTY(s) == 1)
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

