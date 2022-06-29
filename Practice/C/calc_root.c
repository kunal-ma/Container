#include <stdio.h>
#include <math.h>
int main() 
{
    int a,b,c,check;
    float r1,r2;
    
    printf("For the quadratic equation :\n");
    printf("y = a(x^2) + b(x) + c\n\n");
    printf("Enter the value of a : ");
    scanf("%d",&a);
    printf("Enter the value of b : ");
    scanf("%d",&b);
    printf("Enter the value of c : ");
    scanf("%d",&c);
    
    check = (b*b)-(4*a*c);
    
    if (check>0)
    {
        r1 = ((b*(-1)) + (sqrt(check)))/(2*a);
        r2 = ((b*(-1)) - (sqrt(check)))/(2*a);
        
        printf("\nRoot 1 : %.2f",r1);
        printf("\nRoot 2 : %.2f\n",r2);
    }
    else if (check==0)
    {
        r1 = ((b*(-1)) + (sqrt(check)))/(2*a);
        printf("\nRoot : %.2f\n",r1);
    }
    else if (check<0)
    {
        printf("\nRoots are imaginary\n");
    }
    else
    {
        printf("\nError !\n");
    }
}
