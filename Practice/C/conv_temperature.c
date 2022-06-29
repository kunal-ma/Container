#include <stdio.h>
int main() 
{
    int sel;
    float fah,cel;

    printf("Please select your preferred unit : \n\n");
    printf("1 - Fahrenheit\n");
    printf("2 - Celsius\n\n");
    printf("Selection : ");
    scanf("%d",&sel);

    if(sel==1) 
    {
        printf("\nEnter the temperature : ");
        scanf("%f",&fah);
        cel = (5.0/9.0)*(fah-32.0);
        printf("Temperature in Celsius : %0.2f\n",cel);
    }
    else if(sel==2) 
    {
        printf("\nEnter the temperature : ");
        scanf("%f",&cel);
        fah = (9.0/5.0)*(cel+32.0);
        printf("Temperature in Fahrenheit : %0.2f\n",fah);
    }
    else
    {
        printf("\nError !!\n");
    }
}
