#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a,b,sum ;
    int *pa,*pb,*psum;
    pa = &a;
    pb = &b;
    psum = &sum;
    printf("Enter the first integer : ");
    scanf("%d",pa);
    printf("Enter the second integer : ");
    scanf("%d",pb);
    
    *psum = *pa + *pb ;
    printf("Sum of %d and %d equals to %d .\n",a,b,sum);
    return 0;
}