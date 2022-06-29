#include<stdio.h>
#include<stdlib.h>

struct employee
{
    int account;
    char fname[20];
    char lname[20];
    char email[30];
    char phone[10];
    int money;
};

struct employee user[100];

int main()
{
    int n, i, chars,entry=1;
    FILE *fp;

    fp = fopen("data.txt", "w");

    if(fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    printf("Enter the number of records you want to enter: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nEnter details of employee %d \n",entry);

        user[entry].account = 21900 + entry;
        printf("Account No. : %d\n",user[entry].account);

        printf("First Name: ");
        scanf("%s",user[entry].fname);

        printf("Last Name: ");
        scanf("%s",user[entry].lname);

        printf("Email: ");
        scanf("%s",user[entry].email);

        printf("Phone: ");
        scanf("%s",user[entry].phone);

        printf("Money: ");
        scanf("%d", &user[entry].money);

        chars = fwrite(&user, sizeof(user), 1, fp);
        printf("Number of items written to the file: %d\n", chars);
        entry++;
    }

    fclose(fp);
    return 0;
}
