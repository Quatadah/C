#include <stdio.h>
#include <stdlib.h>
#define MAX_STR 30

typedef struct City{
    char name[MAX_STR];
    int population;
}City;

void sort(City cities[] ,int len)
{
    for(int i = 0;i<len;i++)
    {
        for(int j = i +1; j<len ;j++)
        {
            if(cities[i].population > cities[j].population)
            {
                City tmp = cities[i];
                cities[i] = cities[j];
                cities[j] = tmp;
            }
        }
    }
}

int main()
{
    printf("Enter number of cities : ");
    int len;
    scanf("%d",&len);
    City cities[len];

    for(int i=0;i<len;i++)
    {
        getchar();
        printf("Enter the name of the city number %d : ",i);
        fgets(cities[i].name,30,stdin);
        printf("Enter its population : ");
        scanf("%d",&cities[i].population);
    }

    sort(cities,len);

    printf("*****Cities*****\n");
    for(int i = 0; i <len ; i++)
    {
        printf("%s : %d \n",cities[i].name,cities[i].population);
    }

}