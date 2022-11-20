#include "header.h"
int main()
{
    int Choice,F;
    Stack s;
    CreateStack(&s);
    Classes Cl;
    CreatClasses(&Cl);
    Client c;

    while(Choice != 7)
    {
        system("cls");
        Choice = MAIN_MENU();
        if(Choice == 1)
        {
            system("cls");
            NEW_CLIENT (c,&s,&Cl);
        }
        else if(Choice == 2)
        {
            system("cls");

            do
            {
                printf("Your Choice is: Delete Client\n");
                DELETE_CLIENT (&s,&Cl);
                printf("\nReturn to Main menu press: 0\n");
                scanf("%d",&F);
            }while(F);
        }

        else if(Choice == 3)
        {
            system("cls");
            do
            {
                printf("Your Choice is: Client List\n");
                CLIENT_LIST(&s,&Cl);
                printf("\nReturn to Main menu press: 0\n");
                scanf("%d",&F);
            }while(F);
        }

        else if(Choice == 4)
        {
            system("cls");
            do
            {
                printf("Your Choice is: Client Edit\n");
                CLIENT_EDIT(&s,&Cl);
                printf("\nReturn to Main menu press: 0\n");
                scanf("%d",&F);
            }while(F);
        }

        else if(Choice == 5)
        {
            system("cls");
            printf("Your Choice is: Free Seats\n");
            FREE_SEATS(&Cl);
        }

        else if(Choice == 6)
        {
            system("cls");
            printf("Your Choice is: Class List\n");
            CLASS_LIST(&s,&Cl);

        }

        else if(Choice == 7)
            printf("Your Choice is: Exit\n");
        else
            printf("Your choice is wrong please select again\n");

    }

    return 0;

}
