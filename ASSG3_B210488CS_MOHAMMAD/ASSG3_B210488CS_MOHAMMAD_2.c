#include <stdio.h>
int main()
{
    int x, y;
    scanf("%d %d\n", &x, &y);

    int input1[x+1];
    int input2[y+1];
    for (int t = 0; t < x; t++)
    {
        scanf("%d", &input1[t]);
    }
    input1[x]=999999;
    for (int m = 0; m < y; m++)
    {
        scanf("%d", &input2[m]);
    }
    input2[y]=999999;

    int q;
    scanf("\n%d",&q);


    int output[x + y];
    int k;
    int i = 0;
    int j = 0;

    for (k = 0; k < (x+y); k++)
    {
        if (input1[i] < input2[j])
        {
            output[k] = input1[i];
            i++;
        }
        else
        {
            output[k] = input2[j];
            j++;
        }
    }

for (int  d = 0; d < x+y; d++)
{
    if(q==output[d]){
        printf("%d\n",d);
        return 0;
    }


}
printf("-1\n");
return 0;

}
