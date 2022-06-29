// Data Converter v1
// By Kunal M.A.

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

// Store Binary, Octal and Hexa in array
// to avoid formatting issues while calculating
// So, will have to recode the functions to
// process data accordingly.


int bin(int cal);
int dec(int cal,int check);
int oct(int cal);
char hex(char hexa[50])

int main() 
{
    int sel,bi,de,oc;

    printf("Select the type of input :\n");
    printf("\n1 - Binary");
    printf("\n2 - Decimal");
    printf("\n3 - Octal");
    printf("\n\nSelection : ");
    scanf("%d",&sel);

    if (sel==1)
    {d
        printf("Input : ");
        scanf("%d",&bi);

        de = bin(bi);
        oc = dec(de,2);

        printf("\nBinary   : %d",bi);
        printf("\nDecimal  : %d",de);
        printf("\nOctal    : %d\n",oc);
    }
    else if (sel==2)
    {
        printf("\nInput : ");
        scanf("%d",&de);

        bi = dec(de,1);
        oc = dec(de,2);

        printf("\nBinary   : %d",bi);
        printf("\nDecimal  : %d",de);
        printf("\nOctal    : %d\n",oc);
    }
    else if (sel==3)
    {
        printf("\nInput : ");
        scanf("%d",&oc);

        de = oct(oc);
        bi = dec(de,1);

        printf("\nBinary   : %d",bi);
        printf("\nDecimal  : %d",de);
        printf("\nOctal    : %d\n",oc);
    }
    else
    {
        printf("\nError !\n");
    }
}

int dec(int cal,int check) // Decimal -> Bin, Oct
{
    if (check==1) // Binary
    {
        int sol,fac=1,out=0;
        while (cal!=0) 
        {
            sol = cal % 2;
            cal = cal / 2;
            out = out + (sol * fac);
            fac = fac * 10;
        }
        return out;
    }
    else if (check==2) // Octal
    {
        int fac=1,out=0;
        while (cal!=0)
        {
            out = out + (cal % 8) * fac;
            cal = cal / 8;
            fac = fac * 10;
        }
        return out;
    }
    else
    {
        printf("\nError !\n");
    }
}

int bin(int cal) // Binary -> Dec
{
    int sol,fac=0,out=0;
    while (cal!=0) 
    {
        sol = cal % 10;
        cal = cal / 10;
        out = out + (sol * pow(2,fac));
        fac = fac + 1;
    }
    return out;
}

int oct(int cal) // Octal -> Dec
{
    int fac=0,out=0;
    while(cal != 0)
    {
        out = out + (cal%10) * pow(8,fac);
        fac = fac + 1;
        cal = cal / 10;
    }
    return out;
}
char hex(char hexa[50])
{
    char bit[200]="";
    int i=0;
    while(hexa[i])
    {
        switch(hex[i])
        {
            case '0':
                strcat(bit,"0000");
                break;
            case '1':
                strcat(bit,"0001");
                break;
            case '2':
                strcat(bit,"0010");
                break;
            case '3':
                strcat(bit,"0011");
                break;
            case '4':
                strcat(bit,"0100");
                break;
            case '5':
                strcat(bit,"0101");
                break;
            case '6':
                strcat(bit,"0110");
                break;
            case '7':
                strcat(bit,"0111");
                break;
            case '8':
                strcat(bit,"1000");
                break;
            case '9':
                strcat(bit,"1001");
                break;
            case 'A':
            case 'a':
                strcat(bit,"1010");
                break;
            case 'B':
            case 'b':
                strcat(bit,"1011");
                break;
            case 'C':
            case 'c':
                strcat(bit,"1100");
                break;
            case 'D':
            case 'd':
                strcat(bit,"1101");
                break;
            case 'E':
            case 'e':
                strcat(bit,"1110");
                break;
            case 'F':
            case 'f':
                strcat(bit,"1111");
                break;
            default:
                printf("Error !");
                break;
        }
        i++;
    }
    return bit;
}