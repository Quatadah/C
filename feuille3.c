#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Exercice 1

int is_bissextile(int year)
{
    return ( (!(year % 4) && (year % 10)) || !(year % 400));
}

int month_duration(int year,int month)
{
    switch(month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 2:
            return is_bissextile(year) ? 29 :28;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return EXIT_FAILURE;
    }
}
/* 
    this function returns: 
    0 -> Sunday
    1 -> Monday
    2 -> Tuesday
    3 -> Wednesday
    4 -> Thursday
    5 -> Friday
    6 -> Saturday
*/
int which_day(int d,int m, int y)
{
    int z;
    if (m >= 3)
    {
        z = y;
        return (((23*m) / 9 ) + d + 4 + y + (z/4) -(z/100) + (z/400) - 2 ) % 7;
        
    }
    z = y - 1;
    return (((23*m) / 9 ) + d + 4 + y + (z/4) -(z/100) + (z/400)) % 7;
}

void print_day(int d,int m,int y)
{
    int day = which_day(d,m,y);
    switch(day)
    {
        case 0:
            printf("Sunday, ");
            break;
        case 1:
            printf("Monday, ");
            break;
        case 2:
            printf("Tuesday, ");
            break;
        case 3:
            printf("Wednesday, ");
            break;
        case 4:
            printf("Thursday, ");
            break;
        case 5:
            printf("Friday, ");
            break;
        default:
            printf("Saturday, ");
            break;
    }
}

void show_date(int d,int m,int y)
{
    printf("Date : ");
    print_day(d,m,y);
    switch(m)
    {
        case 1:
            printf("January ");
            break;
        case 2:
            printf("February ");
            break;
        case 3 :
            printf("March ");
            break;
        case 4:
            printf("April ");
            break;
        case 5:
            printf("May ");
            break;
        case 6:
            printf("June ");
            break;
        case 7:
            printf("July ");
            break;
        case 8:
            printf("August ");
            break;
        case 9:
            printf("September");
            break;
        case 10:
            printf("October ");
            break;
        case 11:
            printf("November ");
            break;
        default :
            printf("December");
            break;
    }
    printf(" %d %d\n", d,y);
}



//Show Ascii table

void show_ascii()
{
    printf("Car.    dec.    hexa.   octal.   \n\n");
    for (int i = 65; i < 98; i ++)
    {
        printf("%c       %d      %x      %o     \n",i,i,i,i);
    }
}

void show_ascii2()
{
    printf("Car.    dec.    hexa.   octal.   \n\n");
    for (int i = 33; i < 128; i ++)
    {
        printf("%c       %d      %x      %o     \n",i,i,i,i);
    }
}

// /!\ sizeof(type) : returns number of bytes composing that type of integers 
// sizeof(char) = 1 --> 1byte = 8bits
// sizeof(int) = 4 --> 4bytes = 32 bits 
// ...

// function that returns the occurence of 1 in binary compisition of a number
// size_t type read with %ld

size_t occurence1(int n)
{
    int counter = 0;
    for (int i =0 ;i< sizeof(n);i++)
    {
        if ( n & (1<<i))
            counter++;
    }
    return counter;
}


size_t occurence2(int n)
{
    int s = 0;
    while (n)
    {
        if (n%2)
            s++;
        n = n >> 1;
    }
    return s;
}

// 6 -> 00000110
// 7 -> 00000111 => 7 >> 1 -> 00000011 = 3


enum color{
    Noir,
    Marron,
    Rouge,
    Orange,
    Jaune,
    Vert,
    Bleu,
    Violet,
    Gris,
    Blanc
};

int times_pow10(int n,int p)
{
    int fac = 10;
    for (int i =1 ;i < p ;i ++)
        fac *= 10;
    return n*fac;
}

int resistance(enum color c1, enum color c2, enum color c3)
{
    return times_pow10((c1 *10 + c2),c3);
}

int index_of(char *str[],char *s)
{
    int i = 0;
    while(*str != 0)
    {
        if (*str[i]==*s) return i;
        i ++;
    }
}


int main(int argc, char *argv[])
{

    //printf(" 2000 -> %d\n",is_bissextile(2000));
    //printf(" 2008 -> %d\n",is_bissextile(2008));
    //printf(" 2009 -> %d\n",is_bissextile(2009));
    //printf("%d\n",month_duration(2007,2));
    //show_date(16,12,2020);
    //printf("%s\n",__DATE__);


    //printf("\n\n\n");
    //show_ascii2();

    //printf("\n\n");
    //printf("%ld\n",sizeof(int));
    //printf("%ld\n",occurence2(723868769));
    //printf("%d\n",1%2);

    char *str[3]={"heyman","wassup","lol"};
    char *s;
    s = "wassup";
    printf("%d\n",index_of(str,s));



    return 0;
}