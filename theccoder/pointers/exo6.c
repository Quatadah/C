#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_palindrome(char *str)
{
    int bool = 1;
    char *start = str;
    char *end = str + strlen(str) - 1 ;

    while (start != end)
    {
        if (*start != *end)
        {
            bool = 0;
            break;
        }
        start++;
        end--;
    }

    return bool;
}

int main()
{
    char *string = "maanenaam";
    int bool = is_palindrome(string);

    printf("the answer is %d.\n",bool);

    return 0;
}