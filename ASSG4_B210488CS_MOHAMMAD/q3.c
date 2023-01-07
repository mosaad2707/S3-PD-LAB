#include<stdio.h>
#include<stdlib.h>
struct QUEUE
{
long int A[10000];
int size;
int head;
int tail;
};

int QUEUE_EMPTY(struct QUEUE *Q)
{
if(Q->head==-1)
return -1;
else
return 1;
}
int QUEUE_FULL(struct QUEUE *Q)
{
if((Q->tail==Q->size-1 && Q->head==0) || Q->tail==Q->head-1 || Q->size==0)
return -1;
else
return 1;
}
void ENQUEUE(struct QUEUE *Q,long int k)
{
  if(QUEUE_FULL(Q)==-1)
  printf("-1\n");
  else if(Q->head==-1)
  {
  Q->head=Q->tail=0;
  Q->A[Q->tail]=k;
  }
  else if(Q->tail==Q->size-1 && Q->head!=0)
  {
  Q->tail=0;
  Q->A[Q->tail]=k;
  }
  else
  {
  Q->tail++;
  Q->A[Q->tail]=k;
  }
}
void DEQUEUE(struct QUEUE *Q)
{
  if(QUEUE_EMPTY(Q)==-1)
  printf("-1\n");
  else
  {
  printf("%ld\n",Q->A[Q->head]);
  if(Q->head==Q->tail)
  Q->head=Q->tail=-1;
  else if(Q->head==Q->size-1)
  Q->head=0;
  else
  Q->head++;
  }
}

int main()
{
char op;
struct QUEUE *Q;


Q=(struct QUEUE*)malloc(sizeof(struct QUEUE));
scanf("%d",&(Q->size));
long int k;
scanf("%c",&op);
Q->head=-1;
Q->tail=-1;
while(op!='t')
{ switch(op)
{
case 'i': scanf("%ld",&k);
  ENQUEUE(Q,k);
  break;
case 'd': DEQUEUE(Q);
  break;
case 'e': QUEUE_EMPTY(Q));
  break;
case 'f': QUEUE_FULL(Q));
  break;    
}
scanf("%c",&op);
}
  return 0;  

}