#include <stdio.h>
#include <stdlib.h>

int mystrlen(char e[])
{
    int len = 0;
    for (int i = 0; e[i] != '\0'; i++)
    {
        len++;
    }
    return len;
}

struct node
{
    char op;
    struct node *left;
    struct node *right;
};

struct node *stack[100];

struct node *create_node(char c)
{
    struct node *x;
    // printf("%c",c);
    x = (struct node *)malloc(sizeof(struct node));
    x->op = c;
    x->left = NULL;
    x->right = NULL;
    return x;
}
void push(struct node *x, int *top)
{
    stack[++(*top)] = x;
}
struct node *pop(int *top)
{
    struct node *p;
    p = stack[(*top)--];
    return p;
}
void inorder(struct node *t)
{
    if (t != NULL)
    {
        inorder(t->left);
        // printf("hey");
        printf("%c", t->op);
        inorder(t->right);
    }
}
void preorder(struct node *t)
{
    if (t != NULL)
    {
        printf("%c", t->op);
        preorder(t->left);
        preorder(t->right);
    }
}
void postorder(struct node *t)
{
    if (t != NULL)
    {
        postorder(t->left);
        postorder(t->right);
        printf("%c", t->op);
    }
}
struct node *create_tree(char e[])
{
    int i;
    struct node *x;
    int top = -1;
    for (i = 0; i < mystrlen(e); i++)
    {
        if (e[i] == '*' || e[i] == '-' || e[i] == '/' || e[i] == '+')
        {
            x = create_node(e[i]);
            x->right = pop(&top);
            x->left = pop(&top);
            push(x, &top);
        }
        else
        {
            x = create_node(e[i]);
            push(x, &top);
        }
    }
    return x;
}
int main()
{
    char e[100];
    char op;
    struct node *new, t;
    int j, i;

    scanf("%c", &op);

    while (op != 't')
    {
        switch (op)
        {
        case 'e':
            scanf("%s", e);
            new = create_tree(e);
            break;
        case 'i':
            inorder(new);
            printf("\n");
            break;
        case 'p':
            preorder(new);
            printf("\n");
            break;
        case 's':
            postorder(new);
            printf("\n");
            break;
        }
        scanf("%c", &op);
    }
}
