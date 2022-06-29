#include <stdio.h>
#include <math.h>
int main() 
{
    float x,y,dist;

    printf("Enter the X coordinate of Point : ");
    scanf("%f",&x);
    printf("Enter the Y coordinate of Point : ");
    scanf("%f",&y);

    if (x==0 && y==0)
    {
        printf("\nThe Point (%0.1f,%0.1f) lies on the origin\n",x,y);
    }
    else if(x>=0 && y>=0)
    {
        printf("\nThe Point (%0.1f,%0.1f) lies in the 1st Quadrant\n",x,y);
    }
    else if (x<=0 && y>=0)
    {
        printf("\nThe Point (%0.1f,%0.1f) lies in the 2nd Quadrant\n",x,y);
    }
    else if (x<=0 && y<=0)
    {
        printf("\nThe Point (%0.1f,%0.1f) lies in the 3rd Quadrant\n",x,y);
    }
    else if (x>=0 && y<=0)
    {
        printf("\nThe Point (%0.1f,%0.1f) lies in the 4th Quadrant\n",x,y);
    }
    else
    {
        printf("\nInvalid Point !\n");
    }
}
