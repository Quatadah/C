#include <stdio.h>
#include <stdlib.h>


// Exercice 1

int pgcd(int a,int b)
{
    if (!b)
        return a;
    else
        return pgcd(b, a % b);
}

int pgcd_iter(int a,int b)
{
    if (!b)
        return a;
    while(b)
    {
        int r = a;
        a = b;
        b = r % a;
    }
    return a;
    
}

// Exercice 2

void show_table(int len, int tab[])
{
    for (int i =0; i<len; i++)
    {
        printf("tab[%d] = %d\n",i,tab[i]);
    }
}

void fill_pair(int tab[],int len)
{
    for(int i = 1; i <= len ;i ++)
    {
        tab[i]= 2*i;
    }
}

// Exercice 3

int sum(int len, int tab[])
{
    int s = 0;
    for(int i=0;i<len;i++)
    {
        s += tab[i];
    }
    return s;
}

int scalar_product(int t1[],int t2[], int len)
{
    int s = 0;
    for(int i =0 ;i<len;i++)
    {
        s += t1[i] * t2[i];
    }
    return s;
}

void sum_tables(int t1[],int t2[], int t3[],int len)
{
    for (int i=0;i<len ;i++)
    {
        t3[i] = t1[i] + t2[i];
    }
}

//Exercice 4

int is_sorted(int tab[],int len)
{
    int i =0;
    while(i<len-1)
    {
        if (tab[i]<tab[i+1])
            return 0;
        i++;
    }
    return 1;
}

int is_in(int len, int tab[],int x)
{
    int i =0;
    while(i<len)
    {
        if (tab[i] == x)
            return 1;
        i++;
    }
    return 0;
}

int is_in_but_sorted(int len, int tab[],int x)
{
    int begin = 0;
    int end = len - 1 ;
    while(begin<end)
    {
        int mid = (begin+end)/2;
        if (x == tab[mid])
            return 1;
        else if(x< tab[mid])
            end = mid - 1;
        else
            begin = mid + 1;
    }
    return (tab[begin]==x);
}

void pascal_nline(int Cn[],int n )
    {
        int i = n-1;
        Cn[i] = 1;
        while(i > 1)
        {
            i--;
            Cn[i] = Cn[i-1] + Cn[i];
        }
    }



void show(int len,int tab[])
{
    for (int i = 0;i<len;i++)
    {
        printf("%d ",tab[i]);
    }
    printf("\n");
}



void show_pascal(int n)
{
    int i =1;
    int tab[n];
    while (i<n+1)
    {
        pascal_nline(tab,i);
        show(i,tab);
        i++;
    }
}

//Exercice 6

int fibo_rec(int x)
{
    if (x<=1)
        return x;
    return fibo_rec(x-1) + fibo_rec(x-2);
}

int fibo_iter(int x)
{
    if (x<=1)
        return x;
    int s = 0;
    int a = 1;
    int b = 0;
    while(x>1)
    {   
        a = a + b;
        b = a - b;
        x--;
    }
    return a;

}


int main(int argc, char *argv[])
{
    int a = 3;
    int b = 14;
    int tab[4]={1,2,3,4};
    int tab2[5];
    printf("pgcd(%d,%d) = %d\n",a,b,pgcd(a,b));
    printf("pgcd(%d,%d) = %d\n",a,b,pgcd_iter(a,b));
    show_table(4,tab);
    fill_pair(tab2,5);
    show_table(5,tab2);
    printf("\n\n\n");
    show_pascal(4);
    printf("true -> %d, is true ? -> %d \n",fibo_rec(11),fibo_iter(11));

    return 0;
}