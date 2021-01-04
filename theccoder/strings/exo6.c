#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int charInString(char c, char *str)
{
    while(*str != '0')
    {
        if (*str==c)
            return 1;
        str ++;
    }
    return 0;
}

int main(int argc, char *argv[])
{

    char string[100];
    printf("Enter a phrase : ");
    fgets(string,100,stdin);

    printf("There are the letters that does not appear in the sentence.\n");
    for (char c = 'a' ; c < 'z' ; c++)
    {
        if (!charInString(c,string))
            printf("%c ",c);
    }
    printf("\n");

}