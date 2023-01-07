#include<stdio.h>
#include<stdlib.h>

struct node {
    long int key;
struct node *right;
struct node *left;
struct node *p;
};

struct tree{
    struct node *root;
};

struct node *create_node(long int k){
    struct node *x;
    x=(struct node*)malloc(sizeof(struct node));
    x->left=NULL;
    x->right=NULL;
    x->p=NULL;
    x->key=k;
    return x;
}

void INSERT(struct tree *t,struct node *n){
    long int k;
    scanf("%ld",&k);
    n=create_node(k);
    struct node *x=t->root;
    struct node *y=NULL;//both x and y are pointers (imp)
    while(x!=NULL){
        y=x;
        if(n->key<=x->key){
            x=x->left;
        }
        else
            x=x->right;
    }
n->p=y;
if(y==NULL)
    t->root=n;
else if(n->key<y->key)
        y->left=n;
else
        y->right=n;       

}

struct node *SEARCH(struct node *x,int k){
    if(x==NULL || x->key==k)
        return x;
    if(x->key<k)
        return SEARCH(x->right,k);
    else
        return SEARCH(x->left,k);      
}

struct node *FIND_MIN(struct node *x){
    while(x->left!=NULL){
        x=x->left;
    }
    return x;
}

struct node *FIND_MAX(struct node *y){
    while(y->right!=NULL){
        y=y->right;
    }
    return y;
}

void PREORDER(struct node *t){
     printf("( ");
    if(t!=NULL){
       
        printf("%ld ",t->key);
        PREORDER(t->left);
        PREORDER(t->right);
    }
    printf(") ");
}

void POST(struct node *t){
    if(t!=NULL){
        
        POST(t->left);
        POST(t->right);
        printf("%ld ",t->key);
    }
}


void INORDER(struct node *t){
    if(t!=NULL){
        
        INORDER(t->left);
        printf("%ld ",t->key);
        INORDER(t->right);
    }
}

int main(){
    struct tree *t;
    struct node *x;
    struct node *y;
    t=(struct tree*)malloc(sizeof(struct tree));
    t->root=NULL;
    char op;
    scanf("%c",&op);
    long int k;
    while(op!='e'){
        switch (op)
        {
        case 'i': INSERT(t,x);
		 	   break;
       
		 case 'p':   if(t->root==NULL){
            printf("( )\n");
            break;
         }
         else{
                PREORDER(t->root);
		 	   printf("\n");
         }
         break;
	
    }
    scanf("%c",&op);
}
}


