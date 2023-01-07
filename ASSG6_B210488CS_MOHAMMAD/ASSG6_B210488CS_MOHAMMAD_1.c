#include<stdio.h>
#include<stdlib.h>
struct stack{
long int A[100000];
int head;
int size;
};

int STACK_EMPTY(struct stack *s){
    if(s->head==-1){
        return -1;
    }
    else {
        return 0;
    }
}

int STACK_FULL(struct stack *s){
    if(s->head==s->size-1){
        return 1;
    }
    else 
        return 0;
}

void PUSH(struct stack *s,long int k)
{
  if(STACK_FULL(s)==1){
  printf("Full\n");
  }
  else
  {
  s->head=s->head+1;
  //printf("hey");
  s->A[s->head]=k;
  }
}

void POP(struct stack *s,long int l)
{
    while(l-->0){
  if(STACK_EMPTY(s)==-1)
  printf("Empty ");
  else
  {

  printf("%ld ",s->A[s->head]);
  s->head=s->head-1;
 
  }
     }
    printf("\n"); 
}

int main()
{
char op;
struct stack *s;
s=(struct stack*)malloc(sizeof(struct stack));
//printf("check mem alloc");
scanf("%d",&(s->size));
long int k;
long int l;
scanf("%c",&op);
s->head=-1;
while(op!='t')
{ switch(op)
{
case 'i': scanf("%ld",&k);
  PUSH(s,k);
  break;
case 'd':{
    scanf("%ld",&l);
    POP(s,l);
   
}
  break;
case 'e':{
        if(STACK_EMPTY(s)==-1){
            printf("YES\n");
            break;
        }
        else if(STACK_EMPTY(s)==1){
              printf("NO\n");
                break;
        }
     
    }
    case 'f':{
        if(STACK_FULL(s)==1){
            printf("YES\n");
            break;
        }
        else if(STACK_FULL(s)==0){
              printf("NO\n");
                break;
        }
     
    }
}
scanf("%c",&op);
}
  return 0;  

}


