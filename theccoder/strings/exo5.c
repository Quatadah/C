#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int firstIndex(char *substr, char *str)
{
    int i = 0;
    while(*str != *substr)
    {
        str ++;
        i++;
    }
    return i;
}


int is_substr(char *substr, char *str)
{
    int index = firstIndex(substr,str);
    for (int j = 0; j<strlen(substr);j++)
    {
        if (str[index]!=substr[j])
            return 0;
        index++;
    }
    return 1;
}

int issub(char *substr, char *str)
{
    int len = strlen(str);
    int sublen = strlen(substr);
    int index = 0;
    int bool = 0;
    int j;

    for(int i = 0; i < len -sublen +1 ; i++ )
    {
        if (str[i] == substr[i])
        {
            int j;
            for (j=0 ; j < sublen ; j++)
            {
                if (substr[j] != str[i+j])
                    break;
            }
            if (j==sublen)
                bool = 1;
        }
        if (bool==1)
            break;
    }

    return bool;

}

int main(int argc, char *argv[])
{
    char chaine[]="paparresseux";
    char souschaine[]="parr";
    printf("%d\n",issub(souschaine,chaine));
    return 0;
}