#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_palindrome(char str[])
{
    int len = strlen(str);
    int mid = len/2;
    int i = 0;
    while(i<mid)
    {
        if (str[i]!=str[len-1-i])
            return 0;
        i++;
    }


    return 1;

}


int main(int argc, char *argv[])
{
    int bool;
    char str[20];
    printf("Enter a string : ");
    scanf("%s",str);
    bool = is_palindrome(str);

    printf("The value of is_palindrome of %s is %d.\n",str,bool);
    return 0;
}