#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void swap(int *a,int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void order(int *a,int *b)
{
    if (*a>*b)
        swap(a,b);
}

void min_max(int l,int t[], int *min, int *max)
{
    *max = t[0];
    *min = t[0];
    for (int i =0; i < l; i++)
    {
        if (t[i]>=*max)
            *max = t[i];
        if (t[i]<=*min)
            *min = t[i];
    }
}

char *stpcpy2(char *dst, const char *src)
{
    while(*src)
    {
        *dst = *src;
        dst++;
        src++;
    }
    return dst;
}


size_t strlength(const char *s)
{
    int i = 0;
    while(*s)
    {
        s++;
        i++;
    }
    return i;
}

int strcmp2(const char *s1,const char *s2)
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
    return !(s1==s2);
}


void array_zero( char *str, size_t len)
{
    while(len--)  // replaces (len --;) later on on the loop
    {
        *str++ = 0; // replaces :  { *str = 0
                    //                str ++  }
    }
}


int main(int argc, char *argv[])
{
    int a = 12;
    int b = 24;
    //printf("%d,%d\n",a,b);
    //swap(&a,&b);
    //printf("%d,%d\n",a,b);
    
    int tab[6]={1,32,239,3,6,15};
    int min;
    int max;
    min_max(6,tab,&min,&max);
    printf("min of tab is : %d \nmax of tab is : %d\n",min,max);

    char src[40];
    char dst[40];
    strcpy(src,"Hey boys wassup");
    strcpy(dst,"yo girls wassup");
    //printf("%ld\n",strlength(src));
    printf("%s\n",strcat(dst,src));
    return 0;
}