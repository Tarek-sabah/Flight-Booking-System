#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "client.h"
#include "doubly.h"


                    //****************************Client Functions Prototyping****************************//

int MAIN_MENU (void);                               //this function displays the welcome screen and targeted activates.

void NEW_CLIENT (Client ,Stack *,Classes *);        /*this function creates a new client account.
                                                    It asks about details of the client such as
                                                    name, date of birth, ID, address and phone number, preferred class and seat number.*/

void DELETE_CLIENT (Stack *ps,Classes *);           //this function is for deleting a customer account.


void CLIENT_LIST (Stack *ps,Classes *Cl);                         /*this function, you can view the clients information such as
                                                    name, date of birth, ID, address and phone number in table form
                                                    (alphabetically ascending).*/

void CLIENT_EDIT (Stack *,Classes *);               //this function has been used for updating a particular Client account.

void FREE_SEATS (Classes *);                        //this function has been used for displaying the free seats in every class.

void CLASS_LIST ();                                 //this function can sort all Clients according to their seats in selected class.



                    //****************************Other Functions Prototyping****************************//

void	CreateStack (Stack *);              //Create Stack
void Push(Client e,Stack *ps);              //Make a New node and add it to the Stack
void CreatClasses (Classes *);              //Create Business Class, Economy Class and Smoking Class
void Book_Seat(Client C,Classes *Cl);       //Toggle the Seat indicator that indicate if the seat is booked or not


                    //****************************Validation Functions Prototyping****************************//

char Name_Validation(char *name,Stack *ps);                     //To Check the Name is only string and not repeated
char ID_Validation(char *s,int *ID,Stack *ps);                  //To Check the ID is only Int and not repeated
char PN_Validation(char *s);                                    //To Check the Phone Number is valid
char BD_Validation (int day,int month,int year);                //To Check the Birthday format is valid
char Seat_Validation(char *s,int cl_check,Classes *Cl);         //To Check the Seats are in specified Classes and free to Book

void Print_Data(StackNode *pn,Classes *Cl);                     //Print Client Data





#endif // HEADER_H_INCLUDED
