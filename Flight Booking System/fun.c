#include "header.h"


void CreateStack(Stack *ps)
{
    ps->top = NULL;
    ps->size=0;
}

void Push(Client e,Stack *ps)                                       //Add Nodes to List
{
    StackNode *pn =(StackNode *)malloc(sizeof(StackNode));
    pn->entry = e;
    pn->next = ps->top;
    pn->prev = NULL;

    if (ps->top)
        pn->next->prev = pn;
    ps->top = pn;
    ps->size++;

}

void CreatClasses (Classes *Cl)
{
    int i;
    strcpy(Cl->Class_BUS.Name_bus,"Business Class");
    strcpy(Cl->Class_ECO.Name_eco,"Economy Class");
    strcpy(Cl->Class_SMO.Name_smo,"Smoking Class");

    char arr_B[Class_bus_Size][4]=Class_bus_seats;
    char arr_E[Class_eco_Size][4]=Class_eco_seats;
    char arr_S[Class_smo_Size][4]=Class_smo_seats;
    for (i=0;i<Class_bus_Size;i++)
    {
        strcpy(Cl->Class_BUS.Seats_bus[i],arr_B[i]);
        Cl->Class_BUS.Indication_bus[i]=0;
    }
    for (i=0;i<Class_eco_Size;i++)
    {
        strcpy(Cl->Class_ECO.Seats_eco[i],arr_E[i]);
        Cl->Class_ECO.Indication_eco[i]=0;
    }
    for (i=0;i<Class_smo_Size;i++)
    {
        strcpy(Cl->Class_SMO.Seats_smo[i],arr_S[i]);
        Cl->Class_SMO.Indication_smo[i]=0;

    }
}

void Book_Seat(Client C,Classes *Cl)                                //Book Seat or Free Seat for Clients. It change the Indication
{
    int i;
    if(C.Class==1)         //Business Class
    {
        for (i=0;i<Class_bus_Size;i++)
        {
            if(strcmp(C.SN,Cl->Class_BUS.Seats_bus[i])==0)
                Cl->Class_BUS.Indication_bus[i]^=1<<1;
        }
    }
    else if(C.Class==2)
    {
        for (i=0;i<Class_eco_Size;i++)
        {
            if(strcmp(C.SN,Cl->Class_ECO.Seats_eco[i])==0)
                Cl->Class_ECO.Indication_eco[i] ^=1<<1;
        }

    }
    else if(C.Class==3)
    {
        for (i=0;i<Class_smo_Size;i++)
        {
            if(strcmp(C.SN,Cl->Class_SMO.Seats_smo[i])==0)
                Cl->Class_SMO.Indication_smo[i]^=1<<1;
        }

    }
}

                    //****************************Validation Functions Prototyping****************************//

char Name_Validation(char *name,Stack *ps)                          //To Check the Name is only string and not repeated
{
    char ind=0;
    unsigned char i;
    StackNode *pn = ps->top;
    for(i=0;name[i];i++)
    {
        if(isdigit(name[i])||(name[i])=='!'||(name[i])=='@'||(name[i])=='#'||(name[i])=='$'||(name[i])=='%'||(name[i])=='^'||(name[i])=='&'||(name[i])=='*'||(name[i])=='-'||(name[i])=='/'||(name[i])=='+')
        {
            printf("\nName Format is Wrong\n");
            ind = 1;
        }
    }
    for(i=0;i<(ps->size);i++)
    {
        if(!(strcmp(pn->entry.Name,name)))
        {
            printf("\nThe Name is Repeated\n");
            ind = 1;
        }
        pn=pn->next;
    }
    return ind;
}

char ID_Validation(char *s,int *ID,Stack *ps)               //To Check the ID is only Int and not repeated
{
    int i=0;
    int ind=0;
    StackNode *pn = ps->top;

    while(isspace(s[i])) i++;
    int length = strlen(s);
    if (i == length) {ind=1;printf("The ID data is empty");return ind;}

    char integer_buffer[50];
    int integrs_chars=0;

    while(i<length && (!isspace(s[i])))
    {
        if (!isdigit(s[i])) {ind=1;printf("The ID Format is Wrong");return ind;}
        integer_buffer[integrs_chars]=s[i];
        integrs_chars++;
        i++;
    }
    integer_buffer[integrs_chars]='\0';
    while (isspace(s[i])) i++;
    if (s[i] != '\0') {ind=1;return ind;}
    *ID = atoi(integer_buffer);

    for(i=0;i<(ps->size);i++)
    {
        if(pn->entry.ID==(*ID))
        {
            printf("\nThe ID is Repeated\n");
            ind = 1;
        }
        pn=pn->next;
    }

    return ind;
}


char PN_Validation(char *s)
{
    char ind=0;
    while (*s) {
        if (isdigit(*s++) == 0)
        {
            ind=1;
        }
    }
    if(ind==1) printf("\nPhone Number Format is wrong\t");

    return ind;
}

char BD_Validation (int day,int month,int year)
{
    char ind=0;

    if (day<1 || day >32)
    {
        printf("\nDay Format is wrong\t");
        ind =1;
    }
    if (month<1 || month>12)
    {
        printf("Month Format is wrong\t");
        ind =1;
    }
    if (year<1930 || year>2022)
    {
        printf("Year Format is wrong");
        ind =1;
    }
        return ind;
}


char Seat_Validation(char *s,int cl_check,Classes *Cl)
{
    int i;
    char ind=2;

    if (cl_check==1)
    {
        for (i=0;i<Class_bus_Size;i++)
        {
            if(!strcmp(Cl->Class_BUS.Seats_bus[i],s))
            {
                ind=0;
                if(Cl->Class_BUS.Indication_bus[i])
                {
                    printf("\nThe seat is not free\n");
                    ind =1;
                }
            }
        }
    }
    else if (cl_check==2)
    {
        for (i=0;i<Class_eco_Size;i++)
        {
            if(!strcmp(Cl->Class_ECO.Seats_eco[i],s))
            {
                ind=0;
                if(Cl->Class_ECO.Indication_eco[i])
                {
                    printf("\nThe seat is not free\n");
                    ind =1;
                }
            }
        }
    }

    else if (cl_check==3)
    {
        for (i=0;i<Class_smo_Size;i++)
        {
            if(!strcmp(Cl->Class_SMO.Seats_smo[i],s))
            {
                ind=0;
                if(Cl->Class_SMO.Indication_smo[i])
                {
                    printf("\nThe seat is not free\n");
                    ind =1;
                }
            }
        }
    }

    if(ind == 2) printf("\nInvalid Class Seat\n");

    return ind;
}



                    //****************************Print Functions Prototyping****************************//

void Print_Data(StackNode *pn,Classes *Cl)
{
    printf("Name: %s\n",pn->entry.Name);
    printf("ID: %d\n",pn->entry.ID);
    printf("Birthday: %d/%d/%d\n",pn->entry.Birthday.Day,pn->entry.Birthday.Month,pn->entry.Birthday.Year);
    printf("Address: %s\n",pn->entry.Address);
    printf("Phone Number: %s\n",pn->entry.PN);
    if (pn->entry.Class==1) printf("Class: %s\n",Cl->Class_BUS.Name_bus);
    if (pn->entry.Class==2) printf("Class: %s\n",Cl->Class_ECO.Name_eco);
    if (pn->entry.Class==3) printf("Class: %s\n",Cl->Class_SMO.Name_smo);
    printf("Seat Number: %s\n",pn->entry.SN);
    printf("**************************\n");
}
