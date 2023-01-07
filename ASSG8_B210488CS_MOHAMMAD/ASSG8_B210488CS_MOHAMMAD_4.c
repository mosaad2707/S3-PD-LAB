#include <stdio.h>
#include <stdlib.h>

int mystrlen(char e[])
{
    int len = 0;
    for (int i = 0; e[i] != '\0'; i++)
    {
        len++;
    }
    return len - 1;
}

struct node
{
    long int key;
    struct node *right;
    struct node *left;
};

struct tree
{
    struct node *root;
};

struct node *create_node(long int k)
{
    struct node *x;
    x = (struct node *)malloc(sizeof(struct node));
    x->left = NULL;
    x->right = NULL;
    x->key = k;
    return x;
}
char * clearspace(char *string)
{
    
    int alpha = 0;
 
   
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] != ' ')
        {
            string[alpha] = string[i];
            alpha++;
        }    
    }
    
  
    string[alpha] = '\0';
    return string;
}


struct node *BUILD_TREE(char e[], int *s)
{
    if (mystrlen(e) == 0 || mystrlen(e) == 4 || *s >= mystrlen(e))
        return NULL;

    long int n = 0;
    int sign;
    if(e[*s]=='-'){
        sign=-1;
        *s=*s+1;
    }
    else{
        sign=1;
    }
    while (*s < mystrlen(e) && e[*s] != '(' && e[*s] != ')')
    {
        long int num = (int)(e[*s] - 48);
        n = n * 10 + num;
        *s = *s + 1;
    }
    n=n*sign;
    struct node *root = NULL;
    if(n!=0){
    root = create_node(n);
    }

    if(e[*s-1]=='0'){
        int j=0;
        root=create_node(j);
    }
    char c = e[*s];
    if (*s < mystrlen(e) && c == '(')
    {
        *s = *s + 1;
        root->left = BUILD_TREE(e, s);
    }
    if (*s < mystrlen(e) && e[*s] == ')')
    {
        *s = *s + 1;
        return root;
    }
    if (*s < mystrlen(e) && e[*s] == '(')
    {
        *s = *s + 1;
        root->right = BUILD_TREE(e, s);
    }
    if (*s < mystrlen(e) && e[*s] == ')')
        *s = *s + 1;
    return root;
}

void POST(struct node *t)
{
    if (t != NULL)
    {

        POST(t->left);
        POST(t->right);
        printf("%ld ", t->key);
    }
}

int main()
{
    struct node *tree;
    int begin = 1;
    char e[1000];
    
    fgets(e, 1000, stdin);
    if(mystrlen(e)==3){
    printf("NIL\n");
    return 0;
    
    }
    clearspace(e);
    tree = BUILD_TREE(e, &begin);
    POST(tree);
    printf("\n");
    return 0;
}
