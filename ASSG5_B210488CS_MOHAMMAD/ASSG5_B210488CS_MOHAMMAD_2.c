#include<stdio.h>
#include<stdlib.h>

struct node
{

  char key;
  struct node *next;
};

typedef struct node *node;
struct LL
{

struct node *head;

};
typedef struct LL *LL;


node CREATE_NODE(char* k){

  node x;
  x=(struct node*)malloc(sizeof(struct node));
  if(x == NULL)
exit(0);
x->key = k[0];
x->next = NULL; 
return x;
}

node LIST_SEARCH(LL L,char* k)
{
  int s=0;
  node temp;
  temp=L->head;
  	while(temp!=NULL)
		if(temp->key==k[0])
		{	s++;
			return temp;
		}
		else
			temp=temp->next;
	if(s==0)
		return NULL;

return NULL;    
}

void LIST_INSERT_FRONT(LL L,node x){
  char k[1];
  scanf("%s",k);
  x=CREATE_NODE(k);
  x->next=L->head;
  L->head=x;
}

void LIST_INSERT_TAIL(LL L,node x)
{	
	char k[1];
  node temp;
	scanf("%s",k);
	x=CREATE_NODE(k);
	if(L->head==NULL)
		L->head=x;
	else
		{
		 temp=L->head;
		 while(temp->next!=NULL)
		 	temp=temp->next;
		 temp->next=x;
		 }
	
}

void LIST_INSERT_AFTER(LL L,node x,node y)
{	
	char key[1],key_search[1];
	scanf("%s",key);
	scanf("%s",key_search);
	y=LIST_SEARCH(L,key_search);
	node temp;
	 temp=L->head;
  	if(temp==NULL){
  	printf("NULL\n");
  	}
	
	else if(y==NULL){
		printf("ABSENT\n");
		}
	else
		{
		x=CREATE_NODE(key);
		x->next=y->next;
		y->next=x;
		}
	
}

void LIST_INSERT_BEFORE(LL L, node x,node y){
  char k[1],key_search;
  int c=0;
  scanf(" %s",k);
  scanf(" %c",&key_search);
  node temp;
  node prev;
  temp=L->head;
  prev=NULL;
  
  if(temp==NULL){
  	printf("NULL\n");
  	goto label;
  	}
  
  
  	
  while(temp!=NULL){
    if(temp->key==key_search)
    {
      c++;
      y=temp;
      break;
    }
    else{
      prev=temp;
      temp=temp->next;
    }
    }

  	if(c==0)
		y=NULL;
		
		
	
if(y!=NULL){
	
	 if(y==L->head)
		{
		x=CREATE_NODE(k);
		x->next=y;
		L->head=x;
		
		}
	else
		{
		x=CREATE_NODE(k);
		x->next=y;
		prev->next=x;
		}
		}
else{
printf("ABSENT\n");
}
label:
		
}

void LIST_DELETE(LL L,node x)
{	
	char k[1];
	scanf("%s",k);
	x=LIST_SEARCH(L,k);
	node temp;
	temp=L->head;
  	if(temp==NULL){
  	printf("NULL\n");
  	exit(0);
  	}
	if(x==NULL)
		printf("ABSENT\n");
	else if(x==temp)
		{
		L->head=temp->next;
		if(temp->next!=NULL){
		printf("%c\n",temp->next->key);
		}
		else{
		printf("LAST\n");
		}
		free(temp);
		}
	else
	{	
		
		while(temp!=NULL)
			if(temp->next==x)
				temp->next=x->next;
			else 
				temp=temp->next;
		if(temp==NULL){
		printf("LAST\n");
		}
		else {
		printf("%c\n",temp->next->key);
		}
		free(x);
	}	
	
}

void LIST_DELETE_FIRST(LL L)
{	
	node temp;
	temp=L->head;
	if(temp!=NULL)
		{
		
		printf("%c \n",temp->key);
		if(temp->next!=NULL)
			L->head=temp->next;
		else
			L->head=NULL;
		
		}
	else if(temp==NULL)
		printf("NULL\n");
	free(temp);
		
}

void LIST_DELETE_LAST(LL L)
{	
	node temp;
	node prev;
	temp=L->head;
	prev=NULL;
	if(temp==NULL)
		printf("NULL\n");
	else
		{
		while(temp->next!=NULL)
		       {
			prev=temp;
			temp=temp->next;
			}
		if(prev!=NULL)
			prev->next=NULL;
		
		if(temp==L->head)
			L->head=NULL;
		printf("%c \n",temp->key);
		}
	free(temp);	
}

void PRINT(LL L)
{
	node temp;
	temp=L->head;
	if(temp==NULL){
	    printf("NULL");
	}
	while(temp!=NULL)
	{
		printf("%c ",temp->key);
		temp=temp->next;
	}
	printf("\n");
}



int main()
{	
	LL L;
  node x;
  node y;
  node h1;
  h1=NULL;
  
	L=(LL)malloc(sizeof(LL));
	L->head=h1;
	
	char op[1];
	char k[1];
	scanf("%s",op);
	while(op[0]!='e')
	{ 	switch(op[0])
		{
		 case 'f': LIST_INSERT_FRONT(L,x);
		 	   break;
		 case 't': LIST_INSERT_TAIL(L,x);
		 	   break;
		 case 'a': LIST_INSERT_AFTER(L,x,y);
		 	   break;
		 case 'b': LIST_INSERT_BEFORE(L,x,y);
		 	   break;
		 case 'd': LIST_DELETE(L,x);
		 	   break;
		 case 'i': LIST_DELETE_FIRST(L);
		 	   break;	
		 case 'l': LIST_DELETE_LAST(L);
		 	   break;
		 case 'p': PRINT(L);
		 	   break;  
		}
		scanf("%s",op);
	}
 	return 0;	 	  		 
}
