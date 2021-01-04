#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * stringCopy(char *dest, char *src)
{
    while (*src != 0)
    {
        *dest = *src;
        dest++;                  // *dest++=*src++
        src++; 
    }

    return dest;
}

int main(int argc, char *argv[])
{
    char dest[20];
    char src[20];
    printf("Enter a string : ");
    fgets(src,17,stdin);

    stringCopy(dest,src);

    printf("%s , %s \n",src,dest);


    return 0;
}