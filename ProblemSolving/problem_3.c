#include<stdio.h>
int main()
{
    int i, count = 0;
    for(i=1000; i>=1; i--){
        printf("%d\t", i);
        count = count + 1;
        if(count % 5 == 0) printf("\n");
    }
}
