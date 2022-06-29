#include <stdio.h>
int main() 
{
    int a=10,b=20,c;

    printf("Value of a is %d\n",a);
    printf("Value of b is %d\n",b);

    c=b;
    b=a;
    a=c;

    printf("\nValue of a is %d",a);
    printf("\nValue of b is %d\n",b);
}
