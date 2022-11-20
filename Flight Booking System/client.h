#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

#include "header.h"

#define Class_bus_seats {"A1","C1","D1","G1","H1","K1","A2","C2","D2","G2","H2","K2","A3","C3","D3","G3","H3","K3","A4","C4","D4","G4","H4","K4","A5","C5","D5","G5","H5","K5","A6","C6","D6","G6","H6","K6","A7","C7","D7","G7","H7","K7","A8","C8","D8","G8","H8","K8","A9","C9","D9","G9","H9","K9","A10","C10","D10","G10","H10","K10"}
#define Class_eco_seats {"A22","C22","H22","K22","A23","C23","D23","E23","F23","G23","H23","K23","A24","C24","D24","E24","F24","G24","H24","K24","A25","C25","D25","E25","F25","G25","H25","K25","A26","C26","D26","E26","F26","G26","H26","K26","A27","C27","D27","E27","F27","G27","H27","K27","A28","C28","D28","E28","F28","G28","H28","K28","A29","C29","D29","E29","F29","G29","H29","K29"}
#define Class_smo_seats {"A45","C45","H45","K45","A46","C46","D46","E46","F46","G46","H46","K46","A47","C47","D47","E47","F47","G47","H47","K47","A48","C48","D48","E48","F48","G48","H48","K48","A49","C49","D49","E49","F49","G49","H49","K49","A50","C50","D50","E50","F50","G50","H50","K50"}
#define Class_bus_Size 60
#define Class_eco_Size 60
#define Class_smo_Size 44

typedef struct bd{
    int Day;
    int Month;
    int Year;

}Birthday;

typedef struct client{
    char Name[50];
    Birthday Birthday;
    int ID;
    char Address[50];
    char PN[15];                   //Phone Number
    int Class;                     // 1--> Business Class **** 2-->Economy Class **** 3-->Smoking Class
    char SN[4];                        //Seat Number
}Client;
typedef struct class_bus{
    char Seats_bus[Class_bus_Size][4];
    int Indication_bus[Class_bus_Size];
    char Name_bus[30];
}Class_BUS;
typedef struct class_eco{
    char Seats_eco[Class_eco_Size][4];
    int Indication_eco[Class_eco_Size];
    char Name_eco[30];
}Class_ECO;
typedef struct class_smo{
    char Seats_smo[Class_smo_Size][4];
    int Indication_smo[Class_smo_Size];
    char Name_smo[30];
}Class_SMO;

typedef struct classes{
    Class_BUS Class_BUS;
    Class_ECO Class_ECO;
    Class_SMO Class_SMO;
}Classes;


#endif // CLIENT_H_INCLUDED
