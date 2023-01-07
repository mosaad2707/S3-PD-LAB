#include <stdio.h>
int mystrlen(char arr[])
{
    int count = 0;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}
int CompareTwoStrings(char *StringOne, char *StringTwo)
{
    int c;
    if (mystrlen(StringOne) > mystrlen(StringTwo))
    {
        c = mystrlen(StringOne);
    }
    else
    {
        c = mystrlen(StringTwo);
    }

    int i;
    for (i = 0; i < c; i++)
    {
        if (StringOne[i] != StringTwo[i])
        {
            if (StringOne[i] < StringTwo[i])
            {
                return (-1);
            }
            if (StringOne[i] > StringTwo[i])
            {
                return (+1);
            }
        }
    }
    return (0);
}

int main(void) {
    int t;
    scanf("%d",&t);
    struct student {
        char name[30];
        int marks;
        
    }list[t],temp;
    for(int j=0;j<t;j++){
        scanf("%s %d",&list[j].name,&list[j].marks);
        
    }
    char s[30];
    int key=0;
    scanf("%s",s);
    for(int k=0;k<t;k++){
        if(CompareTwoStrings(list[k].name,s)==0){
            key=k;
            break;
        }
        
    }
    
    int max=0,min=0;
    for(int y=0;y<t;y++){
    if(list[y].marks>max){
    max=list[y].marks;
    }
    if(list[y].marks<min){
    min=list[y].marks;
    }
    }
    
    if(list[0].marks==max)
    {
    for(int i=1;i<t;i++){
    printf("%s ",list[i].name);
    }
    
    printf("%s \n",list[0].name);
    return 0;
    
    }

    
    int pivot=list[key].marks;
    int i,l;
    
    for(i=-1,l=0;l<t;l++){
        if(list[l].marks<pivot){
            i++;
            temp=list[i];
            list[i]=list[l];
            list[l]=temp;
        }
    }
    // swap(list.name[i+1],list.name[key]);
    if(pivot==max){
     for(int j=0;j<t;j++){
        printf("%s ",list[j].name);
        
    }
    printf("\n");
    return 0;
    }
    
    temp=list[i+1];
            list[i+1]=list[key];
            list[key]=temp;
            
    
     for(int j=0;j<t;j++){
        printf("%s ",list[j].name);
        
    }
    printf("\n");

	return 0;
}

