#include<stdio.h>
#include<stdlib.h>

struct data
{
    int account;
    char fname[20];
    char lname[20];
    char email[30];
    char phone[10];
    int money;
};

struct data user[100];

int main()
{
    FILE *fp;
    fp = fopen("data.txt", "rb");
    int n=1,io=1;

    if(fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    printf("Testing fread() function: \n\n");

    while( fread(&user, sizeof(user), 1, fp) == 1 )
    {
        printf("\n  Account No. : %d",user[n].account);
        printf("\n  First Name  : %s",user[n].fname);
        printf("\n  Last Name   : %s",user[n].lname);
        printf("\n  Email       : %s",user[n].email);
        printf("\n  Phone       : +91-%s",user[n].phone);
        printf("\n  Balance     : $%d\n",user[n].money);
        n++;
    }

    fclose(fp);

    while(io<n)
    {
        printf("\n----------------------------------------");
        printf("\n  Account No. : %d",user[io].account);
        printf("\n  First Name  : %s",user[io].fname);
        printf("\n  Last Name   : %s",user[io].lname);
        printf("\n  Email       : %s",user[io].email);
        printf("\n  Phone       : +91-%s",user[io].phone);
        printf("\n  Balance     : $%d",user[io].money);
        io++;
    }
}
