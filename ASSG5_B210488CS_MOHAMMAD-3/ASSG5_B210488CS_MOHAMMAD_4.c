#include<stdio.h>
#include<stdlib.h>
struct node
{
	long int key;
	struct node *next;
	struct node *prev;
};
struct sll
{
	struct node *head;
};

struct node *create_node(long int k)
{	
	struct node *x;
	x=(struct node*)malloc(sizeof(struct node));
	x->next=NULL;
	x->prev=NULL;
	x->key=k;
	return x;
}

struct node *list_search(struct sll *L,long int k)
{	
	int c=0;
	struct node *temp;
	temp=L->head;
	while(temp!=NULL)
		if(temp->key==k)
		{	c++;
			return temp;
		}
		else
			temp=temp->next;
	if(c==0)
		return NULL;
		
}
void LIST_INSERT_FRONT(struct sll *L,struct node *x)
{	
	long int k;
	scanf("%ld",&k);
	x=create_node(k);

	x->next=L->head;
	x->prev=NULL;
	if(L->head!=NULL)
		(L->head)->prev=x;
	L->head=x;
}

void LIST_INSERT_TAIL(struct sll *L,struct node *x)
{	
	long int k;
	struct node *temp;
	scanf("%ld",&k);
	x=create_node(k);
	if(L->head==NULL)
		L->head=x;
	else
		{
		 temp=L->head;
		 while(temp->next!=NULL)
		 	temp=temp->next;
		 temp->next=x;
		 x->prev=temp;
		 x->next=NULL;
		 
		 }
	
}

void LIST_INSERT_AFTER(struct sll *L,struct node *x, struct node *y)
{	
	long int key,key_search;
	scanf("%ld",&key);
	scanf("%ld",&key_search);
	y=list_search(L,key_search);
	if(L->head==NULL){
	printf("NULL\n");
	return;
	
	}
	if(y==NULL){
		printf("ABSENT\n");
		
		}
	else
		{
		x=create_node(key);
		
		x->next=y->next;
		if(y->next!=NULL)
			(y->next)->prev=x;
		x->prev=y;
		y->next=x;
	
		}
		return;
	
}

void LIST_INSERT_BEFORE(struct sll *L,struct node *x, struct node *y)
{	
	long int k,key_search;
	int c=0;
	scanf("%ld",&k);
	scanf("%ld",&key_search);
	struct node *temp;
	struct node *before;
	
	temp=L->head;
	
	if(temp==NULL){
	printf("NULL\n");
	return;
	}
	
	before=NULL;
	while(temp!=NULL)
		if(temp->key==key_search)
		{	c++;
			y=temp;
			break;
		}
		else
			{
			before=temp;
			temp=temp->next;
			}
	if(c==0)
		y=NULL;
	

	if(y==NULL){
		printf("ABSENT\n");
		return;
		}
	else if(y==L->head)
		{
		x=create_node(k);
		x->next=y;
		x->prev=NULL;
		y->prev=x;
		L->head=x;
		
		}
	else
		{
		x=create_node(k);
		x->next=y;
		y->prev=x;
		x->prev=before;
		before->next=x;
		}
		return;
	
}


void LIST_DELETE(struct sll *L,struct node *x){
    long int k;
    scanf("%ld",&k);
    struct node *temp;
    temp=L->head;
    x=list_search(L,k);
    if(temp==NULL){
    printf("NULL\n");
    return;
    }
    if(x==NULL){
        printf("ABSENT\n");
        return;
    }
    if(x==temp){
        L->head=temp->next;
        temp->prev=NULL;
        printf("FIRST\n");
		free(temp);
		return;

    }
    while(temp!=NULL){
        if(temp->next==x){
        	printf("%ld\n",temp->key);
        	if(x->next!=NULL){
            x->next->prev=temp;
            temp->next=x->next;
            break;
            }
            else{
            temp->next=NULL;
            break;
            
            }
        }
        else{
            temp=temp->next;
        }
    }
   return;
}

void LIST_DELETE_FIRST(struct sll *L)
{	
	struct node *temp;
	temp=L->head;
	if(temp!=NULL)
		{
		
		printf("%ld\n",temp->key);
		if(temp->next!=NULL)
			L->head=temp->next;
		else
			L->head=NULL;
		
		}
	else if(temp==NULL)
		printf("NULL\n");
	free(temp);	
}

void LIST_DELETE_LAST(struct sll *L)
{	
	struct node *temp;
	
	temp=L->head;
	
	if(temp==NULL)
		printf("NULL\n");
	else
	{
	while(temp!=NULL)
		       {
			if(temp->next==NULL)
				{
				printf("%ld\n",temp->key);
				if(temp->prev!=NULL)
				 	{
				 	(temp->prev)->next=NULL;
				 	break;
				 	}
				else
					{
					L->head=NULL;
					break;
					}
				
				}
			else
				temp=temp->next;
			}
	
	
	}
	free(temp);	
}


void PRINT(struct sll *L)
{
	struct node *temp;
	temp=L->head;
	if(temp==NULL){
	printf("NULL\n");
	return;
	}
	
	else{
	while(temp->next!=NULL){
	temp=temp->next;
	}
	
	while(temp!=NULL){
	printf("%ld ",temp->key);
	temp=temp->prev;
	}
	
	printf("\n");
	}
	return;
	
}
void SWAP(struct sll *L,long int x,long int y){
	struct node *temp;
	temp=L->head;
	if(temp==NULL){
	printf("NULL\n");
	return;
	}
	struct node *temp2;
	struct node *counter;
	counter=L->head;
	int cnt=1;
	while(counter->next!=NULL){
	cnt++;
	counter=counter->next;
	}
	long int h;
	temp2=L->head;
	int count=1;
	
	
	
	
	
	
	
	if(x<=cnt && y<=cnt){
	while(temp->next!=NULL){
	temp=temp->next;
	}
	while(y>1){
	temp=temp->prev;
	y--;
	}
	while(x>1){
	temp2=temp2->next;
	x--;
	}
	
	h=temp2->key;
	temp2->key=temp->key;
	temp->key=h;
	PRINT(L);
	}
	else {
	
	printf("NULL\n");
	}
	return;

}


int main()
{	
	struct sll *L;
	struct node *x;
	struct node *y;
	struct node *alpha;
	struct node *temp;
	alpha=L->head;
	long int count,count2,count3;
	count=0;
	
	L=(struct sll*)malloc(sizeof(struct sll));
	char op;
	long int k;
	scanf("%c",&op);
	while(op!='e')
	{ 	switch(op)
		{
		 case 'f': LIST_INSERT_FRONT(L,x);
		 	   break;
		 case 'p':{
		 		long int k;
		 		long int l;
		 		scanf(" %ld",&k);
		 		scanf(" %ld",&l);
		 		
		 		/*temp=L->head;
		 		count++;
		 		while(temp->next!=NULL){
		 		count++;
		 		temp=temp->next;
		 		}
		 		count++;
		 		if(k<=count && l<=count){
		 		while(k>0){
		 		
		 		alpha=alpha->next;
		 		k--;
		 		}
		 		while(l>0){
		 		
		 		temp=temp->prev;
		 		l--;
		 		}
		 		
		 		long int beta;
		 		beta=alpha->key;
		 		alpha->key=temp->key;
		 		temp->key=beta;*/
		 		SWAP(L,k,l);
		 		{
		 		break;
		 		
		 		}
		 		}
		 		 
		 	   break;
		 	   
		 case 't': LIST_INSERT_TAIL(L,x);
		 	   break;		 	   
		}
		scanf("%c",&op);
	}
 	return 0;	 	  		 
}
