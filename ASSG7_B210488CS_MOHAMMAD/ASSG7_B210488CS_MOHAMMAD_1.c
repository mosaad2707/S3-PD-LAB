#include<stdio.h>
#include<stdlib.h>

struct node{
    char op;
    struct node *link;
    struct node *top;
};

int precedence(char c){
    switch(c){
        case '+':return 0;break;
        case '-':return 0;break;
        case '*':return 1;break;
        case '/':return 1;break;
        case '(':return -1;break;
    }
    return 0;
}

int STACK_EMPTY(struct node *s){
    if(s->top==NULL){
        return -1;
    }
    else
        return 1;

}

struct node * CREATE_NODE(char c){
    struct node *x;
    x=(struct node *)malloc(sizeof(struct node));
    x->link=NULL;
    x->op=c;
    return x;
}

void PUSH(struct node *s,char oper){
    long int k;
    struct node *x;
    x=CREATE_NODE(oper);
    x->link=s->top;
    s->top=x;
}

char POP(struct node *s){
    if(STACK_EMPTY(s)==-1){
        ;
    }
    else
        {
            char c=s->top->op;
            s->top=s->top->link;
            return c;

        }
}

void InfixToPostfix(char e[]){
    int i;
    char c;
    struct node *s;
    s=(struct node *)malloc(sizeof(struct node));
    s->top=NULL;
    int str=0;
    for(int j=0;e[j]!='\0';j++){
        str++;
    }
    for(i=0;i<str;i++){
       if((e[i]>='a' && e[i]<='z') || (e[i]>='A' && e[i]<='Z'))
		{	printf("%c",e[i]);
        }
       else if(e[i]=='('){
        PUSH(s,'(');
       } 
       else if(e[i]==')'){
        while(s->top->op!='(' && STACK_EMPTY(s)!=-1){
            printf("%c",POP(s));
        }
        POP(s);
       }
       else{
        if(STACK_EMPTY(s)!=-1){
            c=s->top->op;
        }
        while((STACK_EMPTY(s)!=-1)&& precedence(c)>=precedence(e[i])){
            printf("%c",POP(s));
            	if(STACK_EMPTY(s)!=-1)	
					c=s->top->op;


        }
        PUSH(s,e[i]);
       }
       

    }
    if(i==str){
        while(STACK_EMPTY(s)!=-1){
            printf("%c",POP(s));
        }
       }
}

int main(){
    int t;
    scanf("%d",&t);
    char e[100];
    while(t--){
        scanf("%s",e);
        InfixToPostfix(e);
        printf("\n");

    }
    return 0;
}
