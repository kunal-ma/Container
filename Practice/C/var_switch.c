#include <stdio.h>
int main() 
{
    int a=10,b=20;

    printf("Value of a is %d\n",a);
    printf("Value of b is %d\n",b);
    
    a=a+b;
    b=a-b;
    a=a-b;

    printf("\nValue of a is %d",a);
    printf("\nValue of b is %d\n",b);
}
