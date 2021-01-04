#include <stdio.h> 
#include <stdlib.h>

int countChar(char *str,char c)
{
    int counter = 0;
    while(*str != 0)
    {
        if (*str == c)
            counter ++;
        str ++;
    }
    return counter;
}

int main(int argc, char * argv[])
{   
    char string[100];
    printf("Enter a sentence : ");
    fgets(string,100,stdin);
    char chars[10];
    printf("Enter the characters you want their occurence in the sentence : ");
    fgets(chars,100,stdin);

    int i = 0;
    while(chars[i] != 0)
    {
        printf("the character %c appears %d time(s).\n",chars[i],countChar(string,chars[i]));
        i++;
    }


    return 0;
}