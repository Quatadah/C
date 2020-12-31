#include<stdio.h>
#include<stdlib.h>


int main()
{
    int len;
    int *ptr;
    int sum = 0;
    printf("Enter the length of the table : ");
    scanf("%d",&len);

    int tab[len];

    for( ptr=tab ; ptr<tab+len ; ptr++)
    {
        printf("Enter value : ");
        scanf("%d",ptr);  
        sum += *ptr;
    }

    printf("the sum is %d.\n",sum);

    return 0;
}