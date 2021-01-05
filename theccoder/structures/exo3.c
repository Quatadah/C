#include <stdio.h>
#include <stdlib.h>
#define MAX_STR 30

typedef struct Student{
    char fullName[MAX_STR];
    double score;
}Student;

void updateScore(Student class[],int len)
{
    for(int i = 0; i<len;i++)
    {
        if(class[i].score<10)
            class[i].score++;
        else if (class[i].score >= 10 && class[i].score <= 15)
            class[i].score += 0.5;
    }
}

void scanClass(Student class[], int len)
{
    for(int i = 0;i <len ;i++)
    {
        getchar();
        printf("Enter fullName of the student number %d : ",i);
        fgets(class[i].fullName,30,stdin);
        printf("His/her score : ");
        scanf("%d",&class[i].score);
    }
}


int main(int argc, char *argv[])
{
    int len;
    printf("Enter number of students : ");
    scanf("%d",&len);

    Student class[len];
    scanClass(class,len);

}