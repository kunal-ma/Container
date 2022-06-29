#include <stdio.h>
int main() 
{
    int mon,year,check;
    
    printf("Assume the order of month as a\n");
    printf("number, like 1 is January.\n\n");
    printf("Enter the year  : ");
    scanf("%d",&year);
    printf("Enter the month : ");
    scanf("%d",&mon);
    
    if (0<mon<=12)
    {
        if (mon==2)
        {
            check = year % 4;
            if (check==0)
            {
                printf("\nNo. of days : 29\n");
            }
            else if (check!=0)
            {
                printf("\nNo. of days : 28\n");
            }
            else
            {
                printf("\nError !\n");
            }
        }
        else if (mon==1 || mon==3 || mon==5 || mon==7 || mon==8 || mon==10 || mon==12)
        {
            printf("\nNo. of days : 31\n");
        }
        else if (mon==4 || mon==6 || mon==9 || mon==11)
        {
            printf("\nNo. of days : 30\n");
        }
        else
        {
            printf("\nError !");
        }
    }
    else
    {
        printf("\nInput Error !\n");
    }
}
