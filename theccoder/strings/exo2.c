#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(char *s1,char *s2)
{
    while (*s1 && *s2)
    {
        if (*s1<*s2)
            return -1;
        else if (*s1>*s2)
            return 1;
        s1++;
        s2++;
    }

    return 0;
}

int main(int argc, char *argv[])
{
    int bool;
    int bool2;
    bool = compare(argv[1],argv[2]);
    bool2 = strcmp(argv[1],argv[2]);

    if (bool==-1)
        printf("%s then %s\n",argv[1],argv[2]);
    else
        printf("%s then %s\n",argv[2],argv[1]);

    return 0;
}