#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
    char string[10];
    char c;
    printf("Enter a string : ");
    fgets(string,10,stdin);
    printf("Enter a character : ");
    scanf("%c",&c);

    char *ret;
    ret = strchr(string,c);

    if (ret==NULL) printf("This character doesn't exist in the string entered.\n");
    else
    {
        printf("the string that comes after '%c' is :  ");
        for(ret;ret< string + strlen(string);ret++)
            printf("%c",*ret);
        printf("\n");
    }
    

    return 0;
}