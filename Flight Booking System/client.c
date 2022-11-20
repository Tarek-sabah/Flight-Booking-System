#include "header.h"


int MAIN_MENU (void)
{
    int Choice;
    printf("\n\n");
    printf("\t\t\t\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t\t\t\t\tHELLO TO TAREK FLIGHT BOOKING SYSTEM\n");
    printf("\t\t\t\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");

    printf("\n\nPlease enter your choice from below (1-7)\n\n");
    printf("1) New Client\n\n"
           "2) Delete Client\n\n"
           "3) Client List\n\n"
           "4) Client Edit\n\n"
           "5) Free Seats\n\n"
           "6) Class List\n\n"
           "7) Exit\n\n");


    scanf("%d",&Choice);
    return Choice;

}

void NEW_CLIENT (Client C,Stack *ps,Classes *Cl)
{
    char name[50];
    int ID=0;
    char ID_s[50];
    char PN[15];
    int day,month,year;
    int cl_check=0;
    char SN[4];

    printf("Making New Client ");
    //  Name
    do
    {
        printf("\nName: ");
        fflush(stdin);
        gets(name);
        strupr(name);
    }while(Name_Validation(name,ps));
    strcpy(C.Name,name);

    // ID
    do
    {
        printf("\nID: ");
        fflush(stdin);
        gets(ID_s);
    }while(ID_Validation(ID_s,&ID,ps));
    C.ID=ID;

    // Birthday
    do
    {
        printf("\nBirthday: ");
        printf("\nDay: ");
        fflush(stdin);
        scanf("%d",&day);
        printf("\nMonth: ");
        fflush(stdin);
        scanf("%d",&month);
        printf("\nYear: ");
        fflush(stdin);
        scanf("%d",&year);
    }while(BD_Validation(day,month,year));

    //gets((C.BD));
    C.Birthday.Day=day;
    C.Birthday.Month=month;
    C.Birthday.Year=year;

    //Phone Number
    do
    {
        printf("\nPhone Number: ");
        fflush(stdin);
        gets(PN);
    }while(PN_Validation(PN));
    strcpy(C.PN,PN);


    //Address
    printf("\nAddress: ");
    fflush(stdin);
    gets((C.Address));

    FREE_SEATS(Cl);
    do
    {
        printf("\nChoose Class:\n"
        "\t\t1) Business Class\n"
        "\t\t2) Economy Class\n"
        "\t\t3) Smoking Class\n");
        scanf("%d",&cl_check);
        if(cl_check!=1 && cl_check!=2 && cl_check!=3) printf("Invalid Choice");
    }while((cl_check!=1) && (cl_check!=2) && (cl_check!=3));
    C.Class=cl_check;

    do
    {
        printf("\nSeat Number: ");
        fflush(stdin);
        gets(SN);
    }while(Seat_Validation(SN,cl_check,Cl));
    strcpy(C.SN,SN);

    Book_Seat(C,Cl);

    Push(C,ps);
}

void DELETE_CLIENT (Stack *ps,Classes *Cl)
{
    StackNode *pn = ps->top;
    int id,i,f=0,flag=0;

    if(!(ps->size))
        printf("There is no Clients");
    else
    {
        do
        {
            printf("Enter ID you want to delete: ");
            fflush(stdin);
            scanf("%d",&id);
        }while(!id);

        for(i=0;i<(ps->size);i++)
        {
            if((pn->entry.ID) == id)
            {
                Print_Data(pn,Cl);


                if ((pn->prev==NULL)&& (pn->next==NULL))
                {
                    free(ps->top);
                    ps->size=0;
                    flag=0;
                }
                else if (pn == ps->top)
                {
                    ps->top = pn->next;
                    free(pn);
                    ps->size--;
                    flag=0;
                }
                else if((pn->prev)&&(!(pn->next)))
                {
                    pn->prev->next=NULL;
                    free(pn);
                    ps->size--;
                    flag=0;
                }
                else if((pn->prev)&&(pn->next))
                {
                    pn->next->prev=pn->prev;
                    pn=pn->next;
                    free(pn->prev->next);
                    pn->prev->next=pn;
                    ps->size--;
                    flag=1;
                }
                f=1;
            }

            if(!flag)
            {
                pn = pn->next;
            }

        }

        if(!f)
            printf("The ID is incorrect");
    }

}


void CLIENT_LIST (Stack *ps,Classes *Cl)
{

    StackNode *pn =ps->top;
    int i,j,flag=0;

    printf("\nList Size: %d\n",ps->size);

    if(!(ps->size))
        printf("There is no Clients");

    else if (ps->size > 0)
    {
        StackNode *pnn = pn->next;

        if (ps->size==1)
        {
            Print_Data(pn,Cl);
        }
        else if(ps->size==2)
        {
         if(strcmp(pn->entry.Name,pnn->entry.Name)>0)
            {
                pnn->prev=pn->prev;
                pn->next=pnn->next;
                pn->prev=pnn;
                pnn->next=pn;
                ps->top=pnn;
                pn=ps->top;
            }
        }
        else if(ps->size > 2)
        {
            for (i = 0;i<(ps->size)-1;i++)
            {

                for(j=0;j<(ps->size)-i-1;j++)
                {

                    if(strcmp(pn->entry.Name,pnn->entry.Name)>0)
                    {
                        if(!(pn->prev))         //The node that will swap is the head
                        {
                            pnn->prev=pn->prev;
                            pn->next=pnn->next;
                            pnn->next->prev=pn;
                            pnn->next=pn;
                            pn->prev=pnn;
                            ps->top=pnn;
                            pnn=pn->next;
                            flag=1;
                        }
                        else if ((pn->prev) && (pn->next)&&(pnn->prev)&&(pnn->next))
                        {
                            pn->next=pnn->next;
                            pnn->prev=pn->prev;
                            pn->prev=pnn;
                            pnn->next=pn;
                            pnn->prev->next=pnn;
                            pn->next->prev=pn;
                            pnn=pn->next;
                            flag=1;
                        }
                        else if (!(pnn->next)&&(pnn->prev))
                        {
                            pn->next=NULL;
                            pnn->next=pn;
                            pnn->prev=pn->prev;
                            pn->prev->next=pnn;
                            pn->prev=pnn;
                        }
                    }

                    if (!flag)                                                  //If there is no change in any condition enter to the next element
                    {
                        pn=pnn;
                        pnn = pn->next;
                        flag=0;
                    }
                }
                pn=ps->top;
                pnn=pn->next;
            }
        }

        for (i= 0;(ps->size > 1)&&(i<(ps->size));i++)
        {
            Print_Data(pn,Cl);
            pn = pn->next;
        }
    }
}


void CLIENT_EDIT (Stack *ps,Classes *Cl)
{
    StackNode *pn =ps->top;
    char name[50];
    int id,i,select=0;
    int day,month,year;
    int ID=0;
    char ID_s[50];
    char PN[15];
    int cl_check=0;
    char SN[4];
    char f=0;


    if(!(ps->size))
        printf("There is no Clients");
    else
    {

        printf("Enter ID you want to Edit: ");
        scanf("%d",&id);
        for (i=0;i<(ps->size);i++)
        {
            if(pn->entry.ID == id && (select !=8))
            {
                Print_Data(pn,Cl);


                printf("What do you want to edit\n"
                   "1) Name\n"
                   "2) ID\n"
                   "3) Birthday\n"
                   "4) Address\n"
                   "5) Phone Number\n"
                   "6) Class\n"
                   "7) Seat Number\n"
                   "8) Exit\n");
                scanf("%d",&select);

                if (select == 1)
                {
                    strcpy(pn->entry.Name,"\0");
                    do
                    {
                        printf("\nName: ");
                        fflush(stdin);
                        gets(name);
                    }while(Name_Validation(name,ps));
                    strcpy(pn->entry.Name,name);
                }
                else if (select == 2)
                {
                    pn->entry.ID=0;
                    do
                    {
                        printf("\nID: ");
                        fflush(stdin);
                        gets(ID_s);
                    }while(ID_Validation(ID_s,&ID,ps));
                    pn->entry.ID=ID;
                }
                else if (select == 3)
                {
                    do
                    {
                        printf("\nBirthday: ");
                        printf("\nDay: ");
                        scanf("%d",&day);
                        printf("\nMonth: ");
                        scanf("%d",&month);
                        printf("\nYear: ");
                        scanf("%d",&year);
                    }while(BD_Validation(day,month,year));
                    pn->entry.Birthday.Day=day;
                    pn->entry.Birthday.Month=month;
                    pn->entry.Birthday.Year=year;
                }
                else if (select == 4)
                {
                    printf("Address: ");
                    fflush(stdin);
                    gets(pn->entry.Address);
                }
                else if (select == 5)
                {
                    do
                    {
                        printf("\nPhone Number: ");
                        fflush(stdin);
                        gets(PN);
                    }while(PN_Validation(PN));
                    strcpy(pn->entry.PN,PN);
                }
                else if (select == 6)
                {
                    FREE_SEATS(Cl);
                    do
                    {
                        printf("\nChoose Class:\n"
                                "\t\t1) Business Class\n"
                                "\t\t2) Economy Class\n"
                                "\t\t3) Smoking Class\n");
                        scanf("%d",&cl_check);
                        if(cl_check!=1 && cl_check!=2 && cl_check!=3) printf("Invalid Choice");
                    }while((cl_check!=1) && (cl_check!=2) && (cl_check!=3));
                    pn->entry.Class=cl_check;
                    Book_Seat(pn->entry,Cl);
                    do
                    {
                        printf("You have to change Seat Number: ");
                        fflush(stdin);
                        gets(SN);
                    }while(Seat_Validation(SN,cl_check,Cl));
                    strcpy(pn->entry.SN,SN);
                    Book_Seat(pn->entry,Cl);
                }
                else if (select == 7)
                {
                    Book_Seat(pn->entry,Cl);
                    do
                    {
                        printf("Seat Number: ");
                        fflush(stdin);
                        gets(SN);
                    }while(Seat_Validation(SN,cl_check,Cl));
                    strcpy(pn->entry.SN,SN);
                    Book_Seat(pn->entry,Cl);
                }
                else if (select == 8);
                else
                    printf("\nWrong selection\n");
                f=1;
            }
            pn = pn->next;
        }
        if(!f) printf("The ID you entered is wrong");
    }
}




void FREE_SEATS(Classes *Cl)
{
    int sel=5,i;
    while(sel)
    {
        do
        {
            printf("\n\nFree Seats for: \n"
           "\t\t1) Business Class\n"
           "\t\t2) Economy Class\n"
           "\t\t3) Smoking Class\n"
           "\t\t4) All Classes\n"
           "\t\t0) Book Your Seat\n"
           "Select: ");
           fflush(stdin);
            scanf("%d",&sel);
        }while((sel!=1)&&(sel!=2)&&(sel!=3)&&(sel!=4)&&(sel!=0));


        if((sel==1)||(sel==4))
        {
            printf("\n______Business Class______\n");
            for (i=0;i<Class_bus_Size;i++)
            {
                if(!(Cl->Class_BUS.Indication_bus[i]))
                    printf("%s\t",Cl->Class_BUS.Seats_bus[i]);
                if((i==(5))||(i==(11))||(i==(17))||(i==(23))||(i==(29))||(i==(35))||(i==(41))||(i==(47))||(i==(53)))
                    printf("\n");
            }
        }
        if((sel==2)||(sel==4))
        {
            printf("\n______Economy Class______\n");
            for (i=0;i<Class_eco_Size;i++)
            {
                if(!(Cl->Class_ECO.Indication_eco[i]))
                    printf("%s\t",Cl->Class_ECO.Seats_eco[i]);

                if((i==(3))||(i==(11))||(i==(19))||(i==(27))||(i==(35))||(i==(43))||(i==(51)))
                    printf("\n");
            }
        }
        if((sel==3)||(sel==4))
        {
            printf("\n______Smoking Class______\n");
            for (i=0;i<Class_smo_Size;i++)
            {
                if(!(Cl->Class_SMO.Indication_smo[i]))
                    printf("%s\t",Cl->Class_SMO.Seats_smo[i]);

                if((i==(3))||(i==(11))||(i==(19))||(i==(27))||(i==(35)))
                    printf("\n");
            }
        }
    }
}


void CLASS_LIST(Stack *ps,Classes *Cl)
{
    StackNode *pn =ps->top;
    int Select=1;
    int i,j;
    while (Select)
    {
        printf("\n\nClass List: \n"
        "\t\t1) Business Class\n"
        "\t\t2) Economy Class\n"
        "\t\t3) Smoking Class\n"
        "\t\t4) All Classes\n"
        "\t\t0) Exit\n"
        "Select: ");
        scanf("%d",&Select);

        if (Select == 1 || Select == 4)
        {
            printf("\n______Business Class______\n");
            for (i=0;i<Class_bus_Size;i++)
            {
                if((Cl->Class_BUS.Indication_bus[i]))
                {
                    printf("%s\t",Cl->Class_BUS.Seats_bus[i]);
                    for (j=0;j<(ps->size);j++)
                    {
                        if(strcmp(pn->entry.SN,Cl->Class_BUS.Seats_bus[i])==0)
                        {
                            Print_Data(pn,Cl);

                        }
                        pn = pn->next;
                    }
                    pn=ps->top;
                }
            }
        }
        if (Select == 2 || Select == 4)
        {
            printf("\n______Economy Class______\n");
            for (i=0;i<Class_eco_Size;i++)
            {
                if((Cl->Class_ECO.Indication_eco[i]))
                {
                    printf("%s\t",Cl->Class_ECO.Seats_eco[i]);
                    for (j=0;j<(ps->size);j++)
                    {
                        if(strcmp(pn->entry.SN,Cl->Class_ECO.Seats_eco[i])==0)
                        {
                            Print_Data(pn,Cl);
                        }
                        pn = pn->next;
                    }
                    pn=ps->top;
                }

            }
        }

        if (Select == 3 || Select == 4)
        {
            printf("\n______Smoking Class______\n");
            for (i=0;i<Class_smo_Size;i++)
            {
                if((Cl->Class_SMO.Indication_smo[i]))
                {
                    printf("%s\t",Cl->Class_SMO.Seats_smo[i]);
                    for (j=0;j<(ps->size);j++)
                    {
                        if(strcmp(pn->entry.SN,Cl->Class_SMO.Seats_smo[i])==0)
                        {
                            Print_Data(pn,Cl);
                        }
                        pn = pn->next;
                    }
                    pn=ps->top;
                }
            }
        }
    }
}
