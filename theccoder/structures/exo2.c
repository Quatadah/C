#include <stdio.h>
#include <stdlib.h>
#define MAX_STR 30


typedef struct Etudiant {
    char lastName[MAX_STR];
    char firstName[MAX_STR];
    int score;
}Etudiant;

int main(int argc,char *argv[])
{
    int len;
    printf("How many students are there ? ");
    scanf("%d",&len);

    Etudiant class[len];
    for(int i =0; i<len ; i++)
    {
        printf("Enter the firstName, lastName and age of the %d(st,th,rd) student :",i);
        scanf("%s %s %d",class[i].firstName,class[i].lastName,&class[i].score);
    }

    printf("Here is the list of students that have passed the exam : \n");
    for (int i =0;i<len ;i++)
    {
        if (class[i].score>=10)
            printf("%s %s\n",class[i].firstName,class[i].lastName);
    }

    return 0;
}