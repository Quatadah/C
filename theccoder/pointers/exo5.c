#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    struct person{
        char lastName[20];
        char firstName[20];
        int age;
    };

    struct person p1;
    struct person p2;

    printf("Enter the first person :\n");
    printf("Lastname : ");
    scanf("%s",p1.lastName);
    printf("firstName : ");
    scanf("%s",p1.firstName);
    printf("age : ");
    scanf("%d",&p1.age);

    
    printf("Enter the second person :\n");
    printf("Lastname : ");
    scanf("%s",p2.lastName);
    printf("firstName : ");
    scanf("%s",p2.firstName);
    printf("age : ");
    scanf("%d",&p2.age);

    printf("\n==================================\n");
    printf("Ladies and gentlemen, here is the younger person.\n\n");

    struct person *younger;

    if (p1.age < p2.age)
        younger = &p1;
    else
        younger = &p2;

    printf("Lastname : %s\nFirstname : %s \n",younger->lastName,younger->firstName);

    return 0;
}