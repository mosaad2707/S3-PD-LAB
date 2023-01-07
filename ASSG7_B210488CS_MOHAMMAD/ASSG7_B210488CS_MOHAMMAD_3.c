#include <stdio.h>
#include <stdlib.h>


char isadigit( unsigned char c) 
{
  if ( c >= '0' && c <= '9' )   
      return 1;

 return 0;
}

// defining stringlentgh
int mystrlen(char e[])
{
    int len = 0;
    for (int i = 0; e[i] != '\0'; i++)
    {
        len++;
    }
    return len;
}

// defining power function
long long power(int x, int n)
{
    long long p = 1;
    for (int i = 0; i < n; i++)
    {
        p = p * x;
    }

    return p;
}
struct node
{
    int op;
    struct node *link;
    struct node *top;
};

int STACK_EMPTY(struct node *s)
{
    if (s->top == NULL)
        return -1;
    else
        return 1;
}
struct node *create_node(int n)
{
    struct node *x;
    x = (struct node *)malloc(sizeof(struct node));
    x->link = NULL;
    x->op = n;
    return x;
}
void PUSH(struct node *s, int n)
{
    long int k;
    struct node *x;
    x = create_node(n);
    x->link = s->top;
    s->top = x;
}
int POP(struct node *s)
{
    if (STACK_EMPTY(s) == -1)
        ;
    else
    {
        int n = s->top->op;
        s->top = s->top->link;
        return n;
    }
}
void EvaluatePostfix(char e[])
{
	int i;
	char c;
	struct node* S;
	S=(struct node*)malloc(sizeof(struct node));
	S->top=NULL;
	for(i=0;i<mystrlen(e);i++)
		{
		//printf("check e[i]%c i%d ",e[i],i);
		if((e[i]==' '|| i==mystrlen(e)) && isadigit(e[i-1]))
		{
			int j=i-1;
			int num=0;
			int p=0;
			while(j>=0 && e[j]!=' ')
			{
				num+=(e[j]-48)*power(10,p);
				p++;
				j--;
			}
			PUSH(S,num);
		}			 
	
		
		else if(e[i]=='+' || e[i]=='-' || e[i]=='*' || e[i]=='/')
		{
			
			
			
			int num1=POP(S);
			int num2=POP(S);
			
			switch(e[i])
			{
			case '+':PUSH(S,num2+num1);
				 break;
			case '-':PUSH(S,num2-num1);
				 break;
			case '*':PUSH(S,num2*num1);
				 break;
			case '/':PUSH(S,num2/num1);
				 break;
			}
				
		}
		
		}
	printf("%d\n",POP(S));
	
		
}

int main()
{
    int t;
    char e[100];
    //scanf("%d", &t);
    scanf("%d\n", &t);
    while (t-- > 0)
    {
        fgets(e, 100, stdin);//other input tyoe may cause error with spaces
        EvaluatePostfix(e);
    }
    return 0;
}
