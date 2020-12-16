#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//Exercice 1

int length(char str[])
{
    int i=0;
    while(str[i] != 0)
    {
        i++;
    }
    return i;
}

int lengthcompare(char s1[],char s2[])
{
    if (length(s1)>length(s2))
        return 1;
    else if (length(s1)<length(s2))
        return -1;
    else
        return 0;
}

char vowels[7]={'a','e','y','u','i','o','\0'};

int count_vowels(char str[])
{
    int i = 0;
    int counter = 0;
    while(str[i] != '\0')
    {
        for (int j=0;j<7;j++)
        {
            if (vowels[j]==str[i])
            {
                counter ++;
                break;
            }
        }
        i++;
    }
    return counter;
}


//Exercice 2

int is_palindrome(char str[])
{
    int len = length(str);
    int mid = len/2;
    for (int i =0 ; i< mid ;i++)
    {
        if (str[len-1-i] != str[i])
            return 0;
    }
    return 1;
}

int is_in_alphabet(char c)
{
    return ((c >= 65 && c<= 90) || (c >= 97 && c<=122 )); 
}

char lower(char c)
{
    if (c>=65 && c<=90)
        return c + 32;
    else if (c >= 97 && c<= 122)
        return c;
    else 
        return 0;
}

char* mirror(char s[])
{
    int len = strlen(s);
    int mid = len/2;
    for(int i =0;i<mid ; i++)
    {
        char tmp = s[i];
        s[i] = s[len-i-1];
        s[len-i-1] = tmp;
    }
    return s;
}

int count_int(int n)
{
    int sum = 0;
    while (n>1)
    {
        n /= 10;
        sum++;
    }
    return sum;
}

void itoa(int n, char *str)
{
    int bool = n<0;
    if (bool)
        n = -n;
    
    int i = 0;
    do{
        str[i] = (n%10) + '0';
        n /= 10;
        i++;
    }while(n);

    str[i] = 0;
    mirror(str);
}


int main(int argc, char *argv[])
{
    //printf("length of %s is %d\n",argv[1],length(argv[1]));
    //printf("length of %s is %ld\n",argv[1],strlen(argv[1]));

    //printf("number of vowels in %s is %d \n ", argv[1],count_vowels(argv[1]));

    //printf("This word is a palindrome ? %s -> %d.\n",argv[1],is_palindrome(argv[1]));

    //printf("This character is an alphabet ? %c -> %d\n",argv[1][0],is_in_alphabet(argv[1][0]));
    //printf("This character is an alphabet ? %c -> %d\n",argv[1][0],isalpha(argv[1][0]));

    // printf("%c miniscule -> %c \n",'A',lower('A'));
    // printf("%c miniscule -> %c \n",'Z',tolower('Z'));

    //    printf("%s becomes %s\n",argv[1],mirror(argv[1]));
    //printf("%d\n",atoi("19209"));
    char str[6];
    itoa(11021,str);
    printf("%d becomes %s \n",10021,str);
    return 0;
}