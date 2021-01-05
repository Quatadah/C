#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void toUpper(char *str)
{
    while (*str != '0')
    {
        if (*str > 'a' && *str < 'z')
            *str = *str -'a'+ 'A';
        str ++;
    }
}

int main(int argc, char *argv[])
{
    char a[] = "hellopeople";
    toUpper(a);

    printf("%s\n",a);
    return 0;
}

