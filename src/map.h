#ifndef MAP_H
#define MAP_H
#include <QString>
#include <stdlib.h>
typedef struct City C;
typedef struct Map M;

//Storage structure
struct City {
    QString City_Name;
    float City_Risk;
    int City_State;
    int Count_Adj_City;
    struct Record {
        QString Adj_Name;
        int Seq_Name;
        int Mark_Air;
        int Mark_Train;
        int Mark_BUS;
        int Air_Time;
        int Train_Time;
        int Bus_Time;
    }Record_Adj_City[12];
    C* Adj_City[12];
    C* next;
};

struct Map {
    C* Map_City[12];
};

#endif // MAP_H
