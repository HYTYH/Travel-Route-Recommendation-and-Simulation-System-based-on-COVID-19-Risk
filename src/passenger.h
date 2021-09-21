#ifndef PASSENGER_H
#define PASSENGER_H
#include <QString>
struct Passenger {
    int Seq;
    int Time_Req;
    float Risk_Req;
    int Price_Req;
    QString Depart_Place;
    QString Dest_Place;
    struct Trav_Plan {
        QString Plan_City[20];
        int Plan_Vehicle[20];
        int Plan_Time[20];
        float Plan_risk;
        int Plan_Price;
    }Plan;
    struct Passenger* next;
    struct Passenger* prev;
};
typedef struct Passenger Pas_List;
//链表

int Num_Pas = -1;
int Timer_Time = 0;
Pas_List* Pas_ptr = NULL, * Current_ptr = NULL, * Last_ptr = NULL;



#endif // PASSENGER_H

