#include<stdio.h>

int main()
{
    int n,t,i;
    scanf("%d%d",&n,&t);
    if(t==10)
    {
        if(n==1)printf("-1");
        else
        {
            printf("1");
            for(i=1;i<n;i++)
                printf("0");
        }
    }
    else
    {
        for(i=0;i<n;i++) printf("%d",t);
    }
    return 0;
}
