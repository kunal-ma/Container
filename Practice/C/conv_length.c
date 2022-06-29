#include <stdio.h>
int main() 
{
    float len,in,cm,ft;

    printf("Enter the length in mm : ");
    scanf("%f",&len);

    cm = len/10.0;
    in = cm/2.5;
    ft = in/12.0;

    printf("\nDistance in cm      : %0.2f",cm);
    printf("\nDistance in inches  : %0.2f",in);
    printf("\nDistance in feet    : %0.2f\n",ft);
}
