#include <stdio.h>
#include <stdlib.h>
#define MAX_STR 30
#define MAX_PEOPLE 40


typedef struct Person{
    char firstName[MAX_STR];
    char lastName[MAX_STR];
    int age;
}Person;

void addPerson(Person People[],Person p,int position,int len)
{
    for(int i = len  ; i>=position+1; i--)
    {
        People[i]=People[i-1];
    }
    People[position] = p;
    
}

int main()
{
    int len;
    Person People[MAX_PEOPLE];
    printf("Enter number of people : ");
    scanf("%d",&len);
    for(int i = 0; i<len;i++)
    {
        printf("Enter firstName, lastName of person %d : ",i);
        scanf("%s%s",People[i].firstName,People[i].lastName);
        printf("his/her age : ");
        scanf("%d",&People[i].age);
    }

    Person p={"Quatadah","Nasdami",20};
    int position = len/2;
    addPerson(People,p,position,len);
    len++;
    for(int i =0; i<len ; i++)
    {
        printf("%s %s \n",People[i].firstName,People[i].lastName);
    }

    return 0;
}