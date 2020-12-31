#include <stdio.h>
#include <stdlib.h>

void swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}


int main()
{
    char a = 'a';
    char b = 'b';

    //before swap
    printf("%c then %c.\n",a,b);
    
    swap(&a,&b);
    //after swap
    printf("%c then %c.\n",a,b);

    return 0;

}
