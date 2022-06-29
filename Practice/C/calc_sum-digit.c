#include <stdio.h>
int main() 
{
    int num,tem,sum=0;

    printf("Enter a 4 digit number : ");
    scanf("%d",&num);

    tem = num%10;
    num = num/10;
    sum = sum+tem;

    tem = num%10;
    num = num/10;
    sum = sum+tem;
    
    tem = num%10;
    num = num/10;
    sum = sum+tem;

    tem = num%10;
    sum = sum+tem;

    printf("The Sum of the digits is : %d\n",sum);
}
