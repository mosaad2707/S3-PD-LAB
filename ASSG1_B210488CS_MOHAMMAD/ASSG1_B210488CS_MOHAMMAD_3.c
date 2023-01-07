#include<stdio.h>

int strln(char a[]){

    int i;
    int count=0;

    for(i=0;a[i]!='\0';i++)
    {
      count++;
    }

return count;


}
int main(){
    char s[100];
    scanf("%s",s);
    int l;
    l=strln(s);

    for(int j=0;j<l;j++){
        if((s[j]>=97)&&(s[j]<=122))
        {
            s[j]=s[j]-32;
        }

    }
int q,r;
for(q=0,r=l-1;q<(l/2);q=q+1,r=r-1)
{
    if(s[q]!=s[r])
    {
        printf("NO");
        return 0;
    }
}
printf("YES");

}