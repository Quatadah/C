#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void deleteOccurences(char *str, char c)
{
    while(*str != 0)
    {
        if (*str==c)
        {
            char *p = str;
            while(*(p)!=0)
            {
                *p = *(p+1);
                p++;
            }
        }
        str ++;
    }
}

int main(int argc, char *argv[])
{
    printf("Enter a string : ");
    char string[1000];
    char c;
    fgets(string,1000,stdin);
    printf("character to delete : ");
    scanf("%c",&c);
    deleteOccurences(string,c);
    printf("the string become : \n %s \n",string);

    return 0;
}