#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char **triangle;
    int p;
    printf("Enter the number of lines : ");
    scanf("%d",&p);
    triangle = (char **)malloc(sizeof(char *)*p);

    for(int i = 0;i<p;i++)
    {
        triangle[i] = (char*) malloc(sizeof(char)*(i+1));
        for(int j = 0 ; j < i + 1;j++)
            triangle[i][j] = '*';
    }

    for (int i = 0;i < p ; i++)
    {
        for (int j = 0;j < i+1; j++)
        {
            printf("%c",triangle[i][j]);
        }
        printf("\n");
    }

    free(triangle);

    return 0;
}