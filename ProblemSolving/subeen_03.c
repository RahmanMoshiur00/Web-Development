#include<stdio.h>

int main()
{
    int i, count=0;
    for(i=1000; i>=1; i--){
        printf("%d", i);
        count++;
        if(count==5){
            printf("\n");
            count=0;
        }
        else printf("\t");
    }
    return 0;
}
