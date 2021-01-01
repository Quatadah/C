#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   int **table;
   int i,j;
   printf("Enter number of lines : ");
   scanf("%d",&i);
   printf("number of lines chosen is %d \n",i);
   printf("Enter number of columns : ");
   scanf("%d",&j);
   printf("number of columns chosen is %d \n",j);

   table = malloc(sizeof(int *)*i);
   for (int k=0 ; k < i ; k++)
   {
      table[k] = malloc(sizeof(int)*j);
      //printf("hey");
   }

   for (int k = 0; k< i ; k++)
   {
      for (int l = 0; l < j ; l++)
      {
         printf("Enter value of table[%d][%d] : ",k,l);
         scanf("%d",&table[k][l]);
      }
   }

   for (int k = 0; k< i ; k++)
   {
      for (int l = 0; l < j ; l++)
      {
         printf("%d\t",table[k][l]);
      }
      printf("\n");
   }
   

   free(table);


   return 0;
}