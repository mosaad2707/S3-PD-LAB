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
    if(t!=NULL){
        printf("%ld ",t->key);
        PREORDER(t->left);
        PREORDER(t->right);
    }
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
        case 'a': INSERT(t,x);
		 	   break;
        case 's': scanf("%ld",&k);
		 	   if(SEARCH(t->root,k)!=NULL)
		 	   	printf("Found\n");
		 	   else
		 	   	printf("NotFound\n");
		 	   break;		
        case 'x':{
            if(t->root!=NULL){
                y=(FIND_MAX(t->root));
            printf("%ld\n",y->key);
            }
            else 
            printf("NIL\n");
        }   
        break;

          case 'n':{
            if(t->root!=NULL){
                y=(FIND_MIN(t->root));
            printf("%ld\n",y->key);
            }
            else 
            printf("NIL\n");
        }     
        break;

		 case 'i': 
         if(t->root==NULL){
            printf("NIL\n");
            break;
         }
         else{
                INORDER(t->root);
		 	   printf("\n");
         }
		 	   break;
		 case 'p':   if(t->root==NULL){
            printf("NIL\n");
            break;
         }
         else{
                PREORDER(t->root);
		 	   printf("\n");
         }
         break;
		 case 't':   if(t->root==NULL){
            printf("NIL\n");
            break;
         }
         else{
                POST(t->root);
		 	   printf("\n");
         }
    }
    scanf("%c",&op);
}
}


