// Altis Banking Systems
// By Kunal M.A.

// ----------------------------------

// Features & Ideas :

// Search for user data based on
// Account No. in Existing Accounts

// Proper changelogs based on token
// data for future reference, can be
// in an external file for better
// memory management.

// ----------------------------------

// Major Bugs :

// getchar() not working when
// implemented in Existing
// Accounts for pausing until
// user presses a key.

// ----------------------------------

// Libraries

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ----------------------------------

// Global variables

int entry=1;        // Entry counter
int token=52301;    // Token ID
FILE *dat;          // FILE link

// ----------------------------------

// User data storage

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

// ----------------------------------

// Functions : User Interface

int menu();     // Main menu
int auth();     // Login page

// Functions : Modules

int account();  // Account Manager
int payment();  // Transactions
int surplus();  // Loans & FDs
int trading();  // Stock Market

// Functions : Services

int load();     // Load from file
int verify();   // Account Verification

// Functions : Subroutines

int cash();     // Deposit & Withdrawal
int income();   // Tax Calculator

// Functions : Errors

int invalid();  // Invalid Input

// ----------------------------------

// Prime Loop

int main()
{
    int sel;

    int locker=1;
    int looper=1;

		/*
    while (locker!=0)			// Currently disabled
        locker=auth();
		*/

    load();

    while (looper!=0)
    {
        sel = menu();

        if(sel==1)
            account();
        if(sel==2)
            payment();
        if(sel==3)
            surplus();
        if(sel==4)
            trading();
        if(sel==0)
            looper--;
        //system("clear");
    }
}

// ----------------------------------

// Main Menu GUI

int menu()
{
    //system("clear");

    int var,test;
    printf("||----------------------------------||\n");
    printf("||       Altis Banking Systems      ||\n");
    printf("||----------------------------------||\n");
    printf("\n  1  -  Accounts");
    printf("\n  2  -  Transactions");
    printf("\n  3  -  Loans & FDs");
    printf("\n  4  -  Stock Market\n");
    printf("\n  0  -  Exit\n");
    printf("\n  Selection : ");
    test=scanf("%d",&var);

    printf("\n");

    if(test==0)
        invalid();
    else
        return var;
}

// ----------------------------------

// Accounts Menu GUI

int account()
{
    //system("clear");

    int var,test,check;
    printf("||----------------------------------||\n");
    printf("||             Accounts             ||\n");
    printf("||----------------------------------||\n");
    printf("\n  1  -  New account");
    printf("\n  2  -  Existing accounts");
    printf("\n  3  -  Modify user data");
    printf("\n  4  -  Close an account\n");
    printf("\n  0  -  Exit\n");
    printf("\n  Selection : ");

    test=scanf("%d",&var);
    printf("\n");

    if(test==0)
        invalid();
    else
    {
        if(var==1)  // New Account GUI
        {
            //system("clear");

            user[entry].account = 21900 + entry;

            printf("||----------------------------------||\n");
            printf("||            New Account           ||\n");
            printf("||----------------------------------||\n\n");

            printf("  Account No. : %d\n",user[entry].account);
            printf("  First Name  : ");
            scanf("%s",user[entry].fname);
            printf("  Last Name   : ");
            scanf("%s",user[entry].lname);
            printf("  Email       : ");
            scanf("%s",user[entry].email);
            printf("  Phone       : +91-");
            scanf("%s",user[entry].phone);
            printf("  Balance     : $");
            scanf("%d",&user[entry].money);

            dat = fopen("users.dat", "a");
            test = fwrite(&user, sizeof(user), 1, dat);

            if(dat != NULL && test==1)
            {
                printf("\n||----------------------------------||");
                printf("\n||            Successful !          ||");
                printf("\n||----------------------------------||\n");
            }
            else
            {
                printf("\n||----------------------------------||");
                printf("\n||          Write Failure !         ||");
                printf("\n||----------------------------------||\n");
                exit(1);
            }

			fclose(dat);
            //getchar();
            entry++;
            return 1;
        }

        else if(var==2)
        {
            //system("clear");

            int n=1;

            printf("||----------------------------------||\n");
            printf("||         Existing Accounts        ||\n");
            printf("||----------------------------------||\n");

            while(n<entry)
            {
                printf("\n||----------------------------------||\n");
                printf("\n  Account No. : %d",user[n].account);
                printf("\n  First Name  : %s",user[n].fname);
                printf("\n  Last Name   : %s",user[n].lname);
                printf("\n  Email       : %s",user[n].email);
                printf("\n  Phone       : +91-%s",user[n].phone);
                printf("\n  Balance     : $%d\n",user[n].money);
                n++;
            }
            printf("\n||----------------------------------||\n\n");
            //getchar();
        }

        else if(var==3)
        {
            //system("clear");

            int check,search,query;

            printf("||----------------------------------||\n");
            printf("||         Modify user data         ||\n");
            printf("||----------------------------------||\n\n");

            printf("  Account No. : ");
            check=scanf("%d",&search);

            query=verify(search);

            if(check==0)
                invalid();
            else if(query==0)
                return 1;
            else
            {
                    printf("  First Name  : ");
                    scanf("%s",user[query].fname);
                    printf("  Last Name   : ");
                    scanf("%s",user[query].lname);
                    printf("  Email       : ");
                    scanf("%s",user[query].email);
                    printf("  Phone       : +91-");
                    scanf("%s",user[query].phone);
                    printf("\n||----------------------------------||\n\n");
                    //getchar();
            }
        }

        else if(var==4)
        {
            //system("clear");

            int check,search,query;

            printf("||----------------------------------||\n");
            printf("||         Close an account         ||\n");
            printf("||----------------------------------||\n\n");

            printf("  Account No. : ");
            check=scanf("%d",&search);

            query = verify(search);

            if(check==0)
                invalid();
            else if(query==0)
                return 1;
            else
            {
                user[query].account = 0;
                strcpy(user[query].fname,"Invalid");
                strcpy(user[query].lname,"Invalid");
                strcpy(user[query].email,"Invalid");
                strcpy(user[query].phone,"0000000000");
                user[query].money = 0;

                printf("\n||----------------------------------||");
                printf("\n||       Account Data deleted !     ||");
                printf("\n||----------------------------------||\n\n");
                //getchar();
                return 1;
            }
        }
        else if(var==0)
        {
            return 0;
        }
    }
}

int payment()
{
    //system("clear");

    int var,test;
    printf("||----------------------------------||\n");
    printf("||           Transactions           ||\n");
    printf("||----------------------------------||\n");
    printf("\n  1  -  Deposit");
    printf("\n  2  -  Withdrawal");
    printf("\n  3  -  Money Transfer\n");
    printf("\n  0  -  Exit\n");
    printf("\n  Selection : ");

    test=scanf("%d",&var);
    printf("\n");

    if(test==0)
        return 0;
    else
    {
        if(var==1 || var==2)
            cash(var);

        else if(var==3)
        {
            //system("clear");

            int check,payer,payee,send,sink,amount,calc;

            printf("||----------------------------------||\n");
            printf("||           Money Transfer         ||\n");
            printf("||----------------------------------||\n\n");

            printf("  Payer Acc. No. : ");
            check = scanf("%d",&send);
            payer = verify(send);

            if(payer==0)
                return 0;

            printf("  Payee Acc. No. : ");
            check = scanf("%d",&sink);
            payee = verify(sink);

            if(payee==0)
                return 0;

            printf("  Amount         : $");
            check=scanf("%d",&amount);

            if(check==0)
                invalid();
            else
            {
                calc = user[payer].money - amount;

                if(calc>=0)
                {
                    user[payer].money -= amount;
                    user[payee].money += amount;
                    printf("\n||----------------------------------||");
                    printf("\n||            Successful !          ||");
                    printf("\n||----------------------------------||\n");
                    //getchar();
                }
                else
                {
                    printf("\n||----------------------------------||");
                    printf("\n||        Insufficient Funds !      ||");
                    printf("\n||----------------------------------||\n\n");
                    //getchar();
                    return 1;
                }
            }

            printf("\n||----------------------------------||\n\n");
            //getchar();
            return 1;
        }
    }
}

int surplus()
{
    //system("clear");

    int var,test;
    printf("||----------------------------------||\n");
    printf("||            Loans & FDs           ||\n");
    printf("||----------------------------------||\n");
    printf("\n  1  -  Loans");
    printf("\n  2  -  Fixed Deposit");
    printf("\n  3  -  ???\n");
    printf("\n  0  -  Exit\n");
    printf("\n  Selection : ");

    test=scanf("%d",&var);
    printf("\n");

    if(test==0)
        return 0;
    else
    {
        if(var==1)
        {
            //system("clear");

            int search,check,query;
            int sal,tax,net,loan;

            printf("||----------------------------------||\n");
            printf("||               Loans              ||\n");
            printf("||----------------------------------||\n\n");

            printf("  Token ID    : %d\n",token);
            printf("  Account No. : ");

            check = scanf("%d",&search);
            query = verify(search);

            if(check==0)
                invalid();
            if(query==0)
                return 1;
            else
                printf("  Name\t      : %s %s\n",user[query].fname,user[query].lname);

            printf("\n  Gross Salary    : $");
            check=scanf("%d",&sal);

            if(check==0)
                invalid();
            else
            {
                tax = income(sal);
                net = sal- tax;
                printf("  Net Salary      : $%d\n",net);
            }

            printf("\n  Loan Amount     : $");
            check=scanf("%d",&loan);
        }
    }
}

int trading()
{

}

int auth()
{
    //system("clear");

    int n=1;
    int login,test;

    int code = 9587;

    printf("||----------------------------------||\n");
    printf("||            Verification          ||\n");
    printf("||----------------------------------||\n\n");

    printf("  Passcode   : ");
    test=scanf("%d",&login);

    if(test==0)
    {
        //system("clear");
        exit(1);
    }
    else
    {
        if(login==code)
            return 0;
        else
            return 1;
    }
}

int cash(int var)
{
    //system("clear");

    int search,calc,check,query;

    printf("||----------------------------------||\n");

    if(var==1)
        printf("||             Deposits             ||\n");
    else if(var==2)
        printf("||            Withdrawal            ||\n");
    else
        invalid();

    printf("||----------------------------------||\n\n");

    printf("  Token ID    : %d\n",token);
    printf("  Account No. : ");

    check = scanf("%d",&search);
    query = verify(search);

    if(check==0)
        invalid();
    if(query==0)
        return 1;
    else
        printf("  Name        : %s %s\n",user[query].fname,user[query].lname);

    printf("  Amount      : $");
    check=scanf("%d",&calc);

    if(check==0)
        invalid();
    else
    {
        if(0<calc && calc<=50000)
        {
            if(var==1)
                user[query].money += calc;
            else if(var==2)
                user[query].money -= calc;
            else
                invalid();

            printf("\n||----------------------------------||");
            printf("\n||            Successful !          ||");
            printf("\n||----------------------------------||\n");
            //getchar();
        }
        else
        {
            printf("\n||----------------------------------||");
            printf("\n||       Amount over the limit !    ||");
            printf("\n||----------------------------------||\n\n");
            //getchar();
            return 1;
        }
    }

    token++;
    return 1;
}

int verify(int query)
{
    int calc,look;

    if(query==0)
        invalid();

    else
    {
        calc=query-21900;

        if(0<calc && calc<=100)
        {
            look = user[calc].account;

            if(look==0)
            {
                printf("\n||----------------------------------||");
                printf("\n||      Account is unavailable !    ||");
                printf("\n||----------------------------------||\n\n");
                //getchar();
                return 0;
            }

            else
                return calc;
        }
        else
        {
            printf("\n||----------------------------------||");
            printf("\n||       Invalid Account No. !      ||");
            printf("\n||----------------------------------||\n\n");
            //getchar();
            return 0;
        }
    }
}

int invalid()
{
    printf("\n||----------------------------------||");
    printf("\n||           Invalid Input !        ||");
    printf("\n||----------------------------------||\n\n");
    //getchar();
    //system("clear");
    exit(1);
}

int income(int var)
{

}

int load()
{
    //system("clear");
    dat = fopen("users.dat", "r");

    if(dat == NULL)
    {
        printf("\n||----------------------------------||");
        printf("\n||          Entry Failure !         ||");
        printf("\n||----------------------------------||\n\n");
        exit(1);
    }

    while( fread(&user, sizeof(user), 1, dat) == 1 )
    {
        printf("\n  Account No. : %d",user[entry].account);
        printf("\n  First Name  : %s",user[entry].fname);
        printf("\n  Last Name   : %s",user[entry].lname);
        printf("\n  Email       : %s",user[entry].email);
        printf("\n  Phone       : +91-%s",user[entry].phone);
        printf("\n  Balance     : $%d\n",user[entry].money);
        entry++;
    }

    fclose(dat);
    //system("clear");
}
