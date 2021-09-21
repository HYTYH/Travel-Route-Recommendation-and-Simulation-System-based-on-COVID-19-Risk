#ifndef PATHSOLUTION_CPP
#define PATHSOLUTION_CPP

#include <QTextStream>
#include <QTextCodec>
#include <QLineEdit>
#include <QString>
#include <fstream>
#include "map.h"
#include "parameters.h"
#include "passenger.h"
#include "map.cpp"

using namespace std;
QString Satisfied = "";
QString record[20][12];

//init storage structure
void init_countrecordnum(void){
    int i = 0;
    for (i = 0; i<20; i++) {
        count_record_num[i] = 0;
    }
}

//init storage structure
void init_record(void){
    int i = 0, j = 0;
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 12; j++) {
            record[i][j] = "";
        }
    }
}

//init storage structure
void init_plantime(void){
    int i = 0, j = 0;
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 16; j++) {
            plantime[i][j] = 0;
        }
    }
}

//init storage structure
void init_planvehi(void){
    int i = 0, j = 0;
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 8; j++) {
            planvehi[i][j] = 0;
        }
    }
}

//init storage structure
void init_planprice(void){
    int i = 0;
    for (i = 0; i < 20; i++) {
        planprice[i] = 0;
    }
}

//init storage structure
void init_planrisk(void){
    int i = 0;
    for (i = 0; i < 20; i++) {
        planrisk[i] = 0;
    }
}

//Output record
void outrecord(void) {
    int i = 0, j = 0;
    for (i = 0; record[i][0] != ""; i++) {
        cout << count_record_num[i] << endl;
        for (j = 0; record[i][j] != ""; j++) {
            if (record[i][j + 1] == "")
                cout << record[i][j];
            else
                cout << record[i][j] << "-->";
        }
        cout << endl;
    }
}

//Output price
void outplanprice(void) {
    int i = 0;
    for (i = 0; planprice[i] != 0; i++) {
        cout << "planprice" << i << ": " << planprice[i] << endl;
    }
}

//Output risk
void outplanrisk(void) {
    int i = 0;
    for (i = 0; planrisk[i] != 0; i++) {
        cout << "planrisk" << i << ": " << planrisk[i] << endl;
    }
}

//Output time
void outplantime(void) {
    int i = 0, j = 0;
    for (i = 0; plantime[i][0] != 0; i++) {
        for (j = 1; plantime[i][j] != 0; j++) {
            if (plantime[i][j + 1] == 0)
                cout << plantime[i][j];
            else
                cout << plantime[i][j] << "-->>>";
        }
        cout << endl;
    }
}

//Output vehicle
void outplanvehi(void) {
    int i = 0, j = 0;
    for (i = 0; planvehi[i][0] != 0; i++) {
        for (j = 0; planvehi[i][j] != 0; j++) {
            if (planvehi[i][j + 1] == 0)
                cout << planvehi[i][j];
            else
                cout << planvehi[i][j] << "-->>>";
        }
        cout << endl;
    }
}

//Get relevant time index
int Get_time_index(int i) {
    int j = 0;
    for (j = 0; plantime[i][j] != 0; j++) {
        if (plantime[i][j + 1] == 0)
            return j;
    }
}

//Find the min-time plan and return the index
int Find_Plan_minTime(void) {
    int i = 0, j = 0;
    int mintime = 99999;
    int mintime_index = 0;
    for (i = 0; plantime[i][0] != 0; i++) {
        j = Get_time_index(i);
        if (plantime[i][j] < mintime) {
            mintime_index = i;
            mintime = plantime[i][j];
        }
    }
    return mintime_index;
}

//Find the min-risk plan and return the index
int Find_Plan_minRisk(void) {
    int i = 0;
    int minrisk = 99999;
    int minrisk_index = 0;
    for (i = 0; planrisk[i] != 0; i++) {
        if (planrisk[i] < minrisk) {
            minrisk_index = i;
            minrisk = planrisk[i];
        }
    }
    return minrisk_index;
}

//Find the min-price plan and return the index
int Find_Plan_minPrice(void) {
    int i = 0;
    int minprice = 99999;
    int minprice_index = 0;
    for (i = 0; planprice[i] != 0; i++) {

        if (planprice[i] < minprice) {
            minprice_index = i;
            minprice = planprice[i];
        }
    }
    return minprice_index;
}

//Display and output Pas's plan
int Out_Pas_Plan(int timereq, int riskreq, int pricereq, int plantype) {
    int i = 0, j = 0, k = 0;
    int marktime = 0, markrisk = 0, markprice = 0, markpath = 0, marksatis = 0;
    int index_mintime = 0, index_minrisk = 0, index_minprice = 0;
    int index_mintime_time = 0, index_mintime_risk = 0, index_mintime_price = 0;
    int minrisk_index = 0, minprice_index = 0, mintime_index = 0, minrisk = 9999, mintime = 9999, minprice = 99999;
    int result = 0;
    //cout << endl;

    if(timereq == 0 && riskreq == 0 && pricereq == 0){
        markprice = 1;
        marksatis = 1;
        for (i = 0; record[i][0] != ""; i++) {
            k = Get_time_index(i);
            if (plantime[i][k] <= timereq || timereq == 0) {
                marktime = 1;
                if (planrisk[i] <= riskreq || riskreq == 0) {
                    markrisk = 1;
                    if (planprice[i] <= pricereq || pricereq == 0) {
                        markprice = 1;
                        if(planrisk[i] < minrisk) {
                            minrisk_index = i;
                            minrisk = planrisk[i];
                        }
                        if(planprice[i] < minprice){
                            minprice_index = i;
                            minprice = planprice[i];
                        }
                        if(plantime[i][k] < mintime){
                            mintime_index = i;
                            mintime = plantime[i][k];
                        }
                    }
                }
            }
        }
    }
    else{
        for (i = 0; record[i][0] != ""; i++) {
            k = Get_time_index(i);
            if (plantime[i][k] <= timereq || timereq == 0) {
                marktime = 1;
                if (planrisk[i] <= riskreq || riskreq == 0) {
                    markrisk = 1;
                    if (planprice[i] <= pricereq || pricereq == 0) {
                        markprice = 1;
                        marksatis = 1;
                        if(planrisk[i] < minrisk) {
                            minrisk_index = i;
                            minrisk = planrisk[i];
                        }
                        if(planprice[i] < minprice){
                            minprice_index = i;
                            minprice = planprice[i];
                        }
                        if(plantime[i][k] < mintime){
                            mintime_index = i;
                            mintime = plantime[i][k];
                        }
                    }
                }
            }
        }
    }

    Satisfied = "yes";
    if(marksatis != 0){
        //k = Get_time_index(minrisk_index);
        //result = minrisk_index;

        if(plantype == 0)
            result = minrisk_index;
        else if(plantype == 1)
            result = mintime_index;
        else if(plantype == 2)
            result = minprice_index;

    }
    else{
        if(marksatis == 0){
            Satisfied = "no";
        }
        index_mintime = Find_Plan_minTime();
        index_minrisk = Find_Plan_minRisk();
        index_minprice = Find_Plan_minPrice();
        index_mintime_time = Get_time_index(index_mintime);
        index_mintime_risk = Get_time_index(index_minrisk);
        index_mintime_price = Get_time_index(index_minprice);

        if(plantype == 0)
            result = index_minrisk;
        else if(plantype == 1)
            result = index_mintime;
        else if(plantype == 2)
            result = index_minprice;
    }
    return result;
}

//Return the risk of relevant city
float Get_Risk(QString city) {
    M* map = new Map;
    Init_Map(map, 12);
    int i = 0, j = 0;
    for (i = 0; i < 12; i++) {
        if (map->Map_City[i]->City_Name == city)
            break;
    }
    float result = map->Map_City[i]->City_Risk;
    Free_Map(map);

    return result;
}

//Get vehicle type of 2 adjacent city
int Get_Vehi_Type(QString start, QString end) {
    M* map = new Map;
    Init_Map(map, 12);
    int i = 0, j = 0;
    for (i = 0; i < 12; i++) {
        if (map->Map_City[i]->City_Name == start)
            break;
    }

    for (j = 0; j < map->Map_City[i]->Count_Adj_City; j++) {
        if (end == map->Map_City[i]->Record_Adj_City[j].Adj_Name) {
            if (map->Map_City[i]->Record_Adj_City[j].Mark_Air == 1) {
                Free_Map(map);
                return 1;
            }
            else if (map->Map_City[i]->Record_Adj_City[j].Mark_BUS == 1 && map->Map_City[i]->Record_Adj_City[j].Mark_Train == 0) {
                Free_Map(map);
                return 2;
            }
            else if (map->Map_City[i]->Record_Adj_City[j].Mark_BUS == 0 && map->Map_City[i]->Record_Adj_City[j].Mark_Train == 1) {
                Free_Map(map);
                return 3;
            }
            else if (map->Map_City[i]->Record_Adj_City[j].Mark_BUS == 1 && map->Map_City[i]->Record_Adj_City[j].Mark_Train == 1) {
                Free_Map(map);
                return 4;
            }

        }
    }

    Free_Map(map);
    return 0;
}

//Get the transporting time of relevant type of vehicle between 2 adjacent city
int Get_Vehi_Time(QString start, QString end, int type) {
    M* map = new Map;
    Init_Map(map, 12);
    int i = 0, j = 0;
    int result = 0;
    for (i = 0; i < 12; i++) {
        if (map->Map_City[i]->City_Name == start)
            break;
    }
    for (j = 0; j < map->Map_City[i]->Count_Adj_City; j++) {
        if (end == map->Map_City[i]->Record_Adj_City[j].Adj_Name) {
            if (type == 1) {
                result = map->Map_City[i]->Record_Adj_City[j].Air_Time;
                Free_Map(map);
                return result;
            }
            else if (type == 2) {
                result = map->Map_City[i]->Record_Adj_City[j].Bus_Time;
                Free_Map(map);
                return result;
            }
            else if (type == 3) {
                result = map->Map_City[i]->Record_Adj_City[j].Train_Time;
                Free_Map(map);
                return result;
            }
        }
    }

    return 0;
}


float Get_City_Risk(QString city) {
    M* map = new Map;
    Init_Map(map, 12);
    int i = 0, j = 0;
    float result = 0;
    for (i = 0; i < 12; i++) {
        if (map->Map_City[i]->City_Name == city)
            break;
    }
    result = map->Map_City[i]->City_Risk;
    Free_Map(map);
    return result;
}

//This function act as TimeTable, storage relevant plan to Pas's infor
void Get_Pas_Plan(int init_time) {
    const int type_1 = 1;//air
    const int type_2 = 2;//bus
    const int type_3 = 3;//train
    const int type_4 = 4;//train+bus
    int type = 0;
    int vehi_time = 0;
    int mark_min = -1;
    int i = 0, j = 0, k = 0;
    int temp = 0;
    float cityrisk = 0;
    int tranrisk = 0;

    for (i = 0, k = 0; record[i][0] != ""; i++) {
        temp = init_time % 24;
        type = Get_Vehi_Type(record[i][0], record[i][1]);
        if (type == type_1) {
            if (temp <= 12) {
                plantime[i][k] = init_time + (12 - temp);
                k++;
            }
            else {
                plantime[i][k] = init_time + (24 - temp) + 12;
                k++;
            }
        }
        else if (type == type_2) {
            temp = init_time % 24;
            if (temp <= 8) {
                plantime[i][k] = init_time + 8 - temp; k++;
            }
            else if (temp > 8 && temp <= 12) {
                plantime[i][k] = init_time + 12 - temp; k++;
            }
            else if (temp > 12 && temp <= 16) {
                plantime[i][k] = init_time + 16 - temp; k++;
            }
            else if (temp > 16 && temp <= 20) {
                plantime[i][k] = init_time + 20 - temp; k++;
            }
            else {
                plantime[i][k] = init_time + 32 - temp; k++;
            }
        }
        else if (type == type_3) {
            temp = init_time % 24;
            if (temp <= 7) {
                plantime[i][k] = init_time + 7 - temp; k++;
            }
            else {
                plantime[i][k] = init_time + 31 - temp; k++;
            }
        }
        else if (type == type_4) {
            temp = init_time % 24;
            if (temp > 20) {
                plantime[i][k] = init_time + 31 - temp; k++;
            }
            else if (temp <= 7) {
                plantime[i][k] = init_time + 7 - temp; k++;
            }
            else if (temp == 8) {
                plantime[i][k] = init_time; k++;
            }
            else if (temp > 8 && temp <= 12) {
                plantime[i][k] = init_time + 12 - temp; k++;
            }
            else if (temp > 12 && temp <= 16) {
                plantime[i][k] = init_time + 16 - temp; k++;
            }
            else if (temp > 16 && temp <= 20) {
                plantime[i][k] = init_time + 20 - temp; k++;
            }
        }


        //由inittime和type求出初始时间。赋给plantime[k];k++;
        for (j = 0; record[i][j + 1] != ""; j++) {
            type = Get_Vehi_Type(record[i][j], record[i][j + 1]);
            cityrisk = Get_City_Risk(record[i][j]);

            if (type == type_1) {
                tranrisk = Air_Risk;
                vehi_time = Get_Vehi_Time(record[i][j], record[i][j + 1], type_1);

                planprice[i] += Airtime_Price * vehi_time;

                planvehi[i][j] = type_1;
                temp = plantime[i][k - 1] % 24;
                if (temp <= 12) {
                    plantime[i][k] = plantime[i][k - 1] + 12 - temp; k++;
                    planrisk[i] += cityrisk * (12 - temp);
                }
                else {
                    plantime[i][k] = plantime[i][k - 1] + 36 - temp; k++;
                    planrisk[i] += cityrisk * (36 - temp);
                }
                plantime[i][k] = plantime[i][k - 1] + vehi_time;
                k++;
                planrisk[i] += vehi_time * tranrisk;
            }
            else if (type == type_2) {
                vehi_time = Get_Vehi_Time(record[i][j], record[i][j + 1], type_2);
                planprice[i] += Bustime_Price * vehi_time;
                tranrisk = Bus_Risk;
                planvehi[i][j] = type_2;
                temp = plantime[i][k - 1] % 24;
                if (temp <= 8) {
                    plantime[i][k] = plantime[i][k - 1] + 8 - temp; k++;
                    planrisk[i] += cityrisk * (8 - temp);
                }
                else if (temp > 8 && temp <= 12) {
                    plantime[i][k] = plantime[i][k - 1] + 12 - temp; k++;
                    planrisk[i] += cityrisk * (12 - temp);
                }
                else if (temp > 12 && temp <= 16) {
                    plantime[i][k] = plantime[i][k - 1] + 16 - temp; k++;
                    planrisk[i] += cityrisk * (16 - temp);
                }
                else if (temp > 16 && temp <= 20) {
                    plantime[i][k] = plantime[i][k - 1] + 20 - temp; k++;
                    planrisk[i] += cityrisk * (20 - temp);
                }
                else {
                    plantime[i][k] = plantime[i][k - 1] + 32 - temp; k++;
                    planrisk[i] += cityrisk * (32 - temp);
                }
                plantime[i][k] = plantime[i][k - 1] + vehi_time;
                k++;
                planrisk[i] += tranrisk * vehi_time;
            }
            else if (type == type_3) {
                temp = plantime[i][k - 1] % 24;
                tranrisk = Train_Risk;
                planvehi[i][j] = type_3;
                vehi_time = Get_Vehi_Time(record[i][j], record[i][j + 1], type_3);
                planprice[i] += Traintime_Price * vehi_time;
                if (temp <= 7) {
                    plantime[i][k] = plantime[i][k - 1] + 7 - temp; k++;
                    planrisk[i] += cityrisk * (7 - temp);
                    plantime[i][k] = plantime[i][k - 1] + vehi_time; k++;
                    planrisk[i] += tranrisk * vehi_time;
                }
                else {
                    plantime[i][k] = plantime[i][k - 1] + 31 - temp; k++;
                    planrisk[i] += cityrisk * (31 - temp);
                    plantime[i][k] = plantime[i][k - 1] + vehi_time; k++;
                    planrisk[i] += tranrisk * vehi_time;
                }
            }
            else if (type == type_4) {
                temp = plantime[i][k - 1] % 24;
                if (temp > 20) {
                    tranrisk = Train_Risk;
                    planvehi[i][j] = type_3;
                    plantime[i][k] = plantime[i][k - 1] + 31 - temp; k++;
                    planrisk[i] += cityrisk * (31 - temp);
                    vehi_time = Get_Vehi_Time(record[i][j], record[i][j + 1], type_3);
                    planprice[i] += Traintime_Price * vehi_time;
                    plantime[i][k] = plantime[i][k - 1] + vehi_time; k++;
                    planrisk[i] += tranrisk * vehi_time;
                }
                else if (temp <= 7) {
                    tranrisk = Train_Risk;
                    planvehi[i][j] = type_3;
                    plantime[i][k] = plantime[i][k - 1] + 7 - temp; k++;
                    planrisk[i] += cityrisk * (7 - temp);
                    vehi_time = Get_Vehi_Time(record[i][j], record[i][j + 1], type_3);
                    planprice[i] += Traintime_Price * vehi_time;
                    plantime[i][k] = plantime[i][k - 1] + vehi_time; k++;
                    planrisk[i] += tranrisk * vehi_time;
                }
                else if (temp == 8) {
                    tranrisk = Bus_Risk;
                    planvehi[i][j] = type_2;
                    plantime[i][k] = plantime[i][k - 1]; k++;
                    vehi_time = Get_Vehi_Time(record[i][j], record[i][j + 1], type_2);
                    planprice[i] += Bustime_Price * vehi_time;
                    plantime[i][k] = plantime[i][k - 1] + vehi_time; k++;
                    planrisk[i] += tranrisk * vehi_time;
                }
                else if (temp > 8 && temp <= 12) {
                    tranrisk = Bus_Risk;
                    planvehi[i][j] = type_2;
                    plantime[i][k] = plantime[i][k - 1] + 12 - temp; k++;
                    planrisk[i] += cityrisk * (12 - temp);
                    vehi_time = Get_Vehi_Time(record[i][j], record[i][j + 1], type_2);
                    planprice[i] += Bustime_Price * vehi_time;
                    plantime[i][k] = plantime[i][k - 1] + vehi_time; k++;
                    planrisk[i] += tranrisk * vehi_time;
                }
                else if (temp > 12 && temp <= 16) {
                    tranrisk = Bus_Risk;
                    planvehi[i][j] = type_2;
                    plantime[i][k] = plantime[i][k - 1] + 16 - temp; k++;
                    planrisk[i] += cityrisk * (16 - temp);
                    vehi_time = Get_Vehi_Time(record[i][j], record[i][j + 1], type_2);
                    planprice[i] += Bustime_Price * vehi_time;
                    plantime[i][k] = plantime[i][k - 1] + vehi_time; k++;
                    planrisk[i] += tranrisk * vehi_time;
                }
                else if (temp > 16 && temp <= 20) {
                    tranrisk = Bus_Risk;
                    planvehi[i][j] = type_2;
                    plantime[i][k] = plantime[i][k - 1] + 20 - temp; k++;
                    planrisk[i] += cityrisk * (20 - temp);
                    vehi_time = Get_Vehi_Time(record[i][j], record[i][j + 1], type_2);
                    planprice[i] += Bustime_Price * vehi_time;
                    plantime[i][k] = plantime[i][k - 1] + vehi_time; k++;
                    planrisk[i] += tranrisk * vehi_time;
                }
            }
        }
        k = 0;
    }


}

void Out_Record(void) {
    int i = 0, j = 0;
    for (i = 0; record[i][0] != ""; i++) {
        for (j = 0; record[i][j] != ""; j++) {
            if (record[i][j + 1] == "")
                cout << record[i][j];
            else
                cout << record[i][j] << "-->>>";
        }
        cout << endl;
    }
}

//Storage all possible path
void Record_All_Path(C* Start, C* End) {//only record path's length <=5
    int i = 0, j = 0, k = 0;
    while (Start->City_Name != End->City_Name) {
        record[a][b] = Start->City_Name;
        b++;
        Start = Start->next;
    }
    record[a][b] = Start->City_Name;
    i = a, j = b;
    count_record_num[a] = b + 1;

    if (b >= 5) {
        for (k = 0; k < j; k++) {
            record[i][k] = "";
        }
    }
    else {
        a++;
    }

    b = 0;
}

//Match the cityname with the map's city
C* Match_Start(M* Map_China, C* Start, QString name) {
    for (int i = 0; i < 12; i++) {
        if (Map_China->Map_City[i]->City_Name == name) {
            Start = Map_China->Map_City[i];
        }
    }
    Start->City_State = START_CITY;
    return Start;
}

//Match the cityname with the map's city
C* Match_End(M* Map_China, C* End, QString name) {
    for (int i = 0; i < 12; i++) {
        if (Map_China->Map_City[i]->City_Name == name) {
            End = Map_China->Map_City[i];
        }
    }
    End->City_State = END_CITY;
    return End;
}

//Use DFS to get all path
void Get_All_Path(C* Depart, C* Dest, int City_Num, M* map) {
    int i = 0, j = 0, count = 0;
    C* Start = NULL, * End = NULL;
    Start = new City;
    End = new City;


    for (i = 0; i < Depart->Count_Adj_City; i++) {
        if (Depart->Adj_City[i]->City_State == UNPASSED_CITY) {
            Depart->Adj_City[i]->City_State = PASSED_CITY;
            Depart->next = Depart->Adj_City[i];
            Get_All_Path(Depart->Adj_City[i], Dest, City_Num, map);
            Depart->next = NULL;
        }
    }

    for (i = 0; i < Depart->Count_Adj_City; i++) {
        if (Depart->Adj_City[i]->City_State == END_CITY) {
            if (Depart->City_State == START_CITY) {

                record[a][0] = Depart->City_Name;
                record[a][1] = Dest->City_Name;
                count_record_num[a] = 2;
                a++;
                return;
            }
            else {
                Depart->next = Depart->Adj_City[i];
                for (j = 0; j < City_Num; j++) {
                    if (map->Map_City[j]->City_State == START_CITY) {
                        Start = map->Map_City[j];
                    }
                    if (map->Map_City[j]->City_State == END_CITY) {
                        End = map->Map_City[j];
                    }
                }

                Record_All_Path(Start, End);
                Depart->City_State = UNPASSED_CITY;
                Depart->next = NULL;
                return;
            }
        }
    }

    for (i = 0; i < Depart->Count_Adj_City; i++) {
        if (Depart->Adj_City[i]->City_State == PASSED_CITY) {
            Depart->City_State = UNPASSED_CITY;
            return;
        }
    }

    for (i = 0; i < Depart->Count_Adj_City; i++) {
        if (Depart->Adj_City[i]->City_State == START_CITY) {
            Depart->City_State = UNPASSED_CITY;
        }
    }

}

//Judge whether the request is available, and return
int Judge_Req_avail(QString s, QString e) {
    M* Map_China = new Map;
    Init_Map(Map_China, 12);
    QString Start_City_Name = "";
    QString End_City_Name = "";
    Start_City_Name.append(s);
    End_City_Name.append(e);

    int i = 0, markstart = 0, markend = 0;

    for(i=0;i<12;i++){
        if(Start_City_Name == Map_China->Map_City[i]->City_Name){
            markstart = 1;
            break;
        }
    }

    i = 0;

    for(i=0;i<12;i++){
        if(End_City_Name == Map_China->Map_City[i]->City_Name){
            markend = 1;
            break;
        }
    }

    Free_Map(Map_China);
    delete Map_China;

    if(markend == 1 && markstart == 1)
        return 1;
    else
        return 0;
}

//init function
void Find_All_Path(QString s, QString e) {
    M* Map_China = new Map;
    Init_Map(Map_China, 12);
    QString Start_City_Name = s;
    QString End_City_Name = e;
    C* Start = NULL; Start = Match_Start(Map_China, Start, Start_City_Name);
    C* End = NULL; End = Match_End(Map_China, End, End_City_Name);

    Get_All_Path(Start, End, 12, Map_China);

    Free_Map(Map_China);
    delete Map_China;
}



#endif
