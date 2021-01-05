#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point{
    int x;
    int y;
};

double distance(struct point p1,struct point p2)
{
    int distance;
    int x,y;
    x = p2.x - p1.x;
    y = p2.y - p1.y;
    distance = sqrt((x*x)+(y*y));
    return distance;
}


int main()
{
    struct point p1 = {1,3};
    struct point p2 = {0,4};
    double dis ;
    dis = distance(p1,p2);
    printf("distance between p1 and p2 is : %f\n",dis);

    return 0;
}