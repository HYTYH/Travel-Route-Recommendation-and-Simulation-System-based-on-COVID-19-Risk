#ifndef PARAMETERS_H
#define PARAMETERS_H
const float City_High_Risk = 0.9;
const float City_Medium_Risk = 0.5;
const float City_Low_Risk = 0.2;
#define UNPASSED_CITY 0
#define PASSED_CITY 1
#define START_CITY 2
#define END_CITY 3
#define Airtime_Price 600
#define Traintime_Price 150
#define Bustime_Price 25
#define Bus_Risk 2
#define Train_Risk 5
#define Air_Risk 9
int count_record_num[20];
int planprice[20];
float planrisk[20];
int planvehi[20][8];
int plantime[20][16];
int a = 0, b = 0;

#endif // PARAMETERS_H
