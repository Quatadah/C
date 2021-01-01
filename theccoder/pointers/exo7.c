#include <stdio.h>
#include <stdlib.h>


int main(int argc, char * argv[])
{
    int *table;
    int len;
    printf("Enter the length of the table : ");
    scanf("%d",&len);

    table  = malloc(sizeof(int)*len);

    for (int i = 0; i<len ;i++)
    {
        printf("Enter value of table[%d] : ",i);
        scanf("%d",table+i);
    }

    for (int i =0; i<len ; i++)
    {
        printf("table[%d] = %d\n",i,table[i]);
    }



    free(table);
    
    return 0;
}