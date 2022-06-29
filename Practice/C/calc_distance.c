#include <stdio.h>
#include <math.h>
int main() 
{
    float x1,y1,x2,y2,dist;

    printf("Enter the X coordinate of Point A : ");
    scanf("%f",&x1);
    printf("Enter the Y coordinate of Point A : ");
    scanf("%f",&y1);
    printf("Enter the X coordinate of Point B : ");
    scanf("%f",&x2);
    printf("Enter the Y coordinate of Point B : ");
    scanf("%f",&y2);

    dist = sqrt((pow(x1-x2,2)+pow(y1-y2,2)));

    printf("\nDistance between A & B : %.2f \n",dist);
}
