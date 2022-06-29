#include <stdio.h>
int main() 
{
    int mon,year,sum=0,check,i;

    printf("Assume the order of month as a\n");
    printf("number, like 1 is January.\n\n");
    printf("Enter the year  : ");
    scanf("%d",&year);
    printf("Enter the month : ");
    scanf("%d",&mon);
    
    for (i=1;i<=mon; ++i)
    {
        if (i==2)
        {
            check = year % 4;
            if (check==0)
            {
                sum=sum+29;
            }
            else if (check!=0)
            {
                sum=sum+28;
            }
            else
            {
                printf("\nError !\n");
            }
        }
        else if (i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12)
        {
            sum=sum+31;
        }
        else if (i==4 || i==6 || i==9 || i==11)
        {
            sum=sum+30;
        }
        else
        {
            printf("\nError !");
        }
    }
    
    printf("Total no. of days : %d\n",sum);
}
