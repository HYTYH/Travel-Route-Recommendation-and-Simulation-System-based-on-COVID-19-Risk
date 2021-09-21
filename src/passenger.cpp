#ifndef PASSENGER_CPP
#define PASSENGER_CPP

#include "pathsolution.cpp"
QString SetInfo = "";
QString SetAddText = "";
QString SetChangeText = "";
QString Setpara = "";
QString city[20];
int ttime[40];
int vehi[20];
int markajcity_index = 0;
int markvehic_index = 0;
int markstate = 0;
int markcity_index = 0;
using namespace std;

//Judge if the number of Pas is available
QString Search_Pas_avail(int Seq, int Time){
    Pas_List* temp = NULL;
    temp = Pas_ptr;

    if(temp == NULL)
        return "no";

    while(temp != NULL){
        if(temp->Seq == Seq)
            break;

        temp = temp->next;
        if(temp == NULL)
            return "no";
    }

    return "yes";
}

//Return the on searching Pas's state
QString Search_Pas_State(int Seq, int Time){
    int i = 0;

    QString s = "";
    QString v = "";

    QString a = "";
    QString b = "";

    markajcity_index = 0;
    markvehic_index = 0;
    markstate = 0;
    markcity_index = 0;

    for(i=0; i < 20; i++){
        city[i] = "";
    }
    for(i=0; i < 40; i++){
        ttime[i] = 0;
    }
    for(i=0; i < 20; i++){
        vehi[i] = 0;
    }

    while(Pas_ptr->Seq != Seq){
        Pas_ptr = Pas_ptr->next;
    }

    a.append(Pas_ptr->Depart_Place);
    b.append(Pas_ptr->Dest_Place);

    for(i=1; Pas_ptr->Plan.Plan_Time[i] != 0 && Pas_ptr->Plan.Plan_Time[i] < 99999; i++){
        ttime[i-1] = Pas_ptr->Plan.Plan_Time[i];
    }

    for(i=0; Pas_ptr->Plan.Plan_Vehicle[i] != 0 && Pas_ptr->Plan.Plan_Vehicle[i] < 4; i++){
        vehi[i] = Pas_ptr->Plan.Plan_Vehicle[i];
    }

    for(i=0; ; i++){
        city[i].append(Pas_ptr->Plan.Plan_City[i]);
        if(city[i] == b)
            break;
    }

    if(Time < Pas_ptr->Plan.Plan_Time[0]){
        s = "";
        s.append(Pas_ptr->Plan.Plan_City[0]);
        markstate = 1;
        markcity_index = 0;
    }
    else{
        for(i=0; ttime[i] != 0; i++){
            if(Time >= ttime[i] && Time < ttime[i+1]){
                if(i % 2 == 1){
                    s = "";
                    s.append(city[(i+1)/2]);
                    markstate = 1;
                    markcity_index = (i+1)/2;
                    break;
                }
                else if (i % 2 == 0){
                    s = "";
                    markstate = 0;
                    s.append("在");
                    s.append(city[i/2]);
                    markajcity_index = i/2;
                    s.append("与");
                    s.append(city[(i/2)+1]);
                    s.append("之间的");
                    if(vehi[i/2] == 1){
                        s.append("飞机");
                        markvehic_index = i/2;
                    }
                    else if(vehi[i/2] == 2){
                        s.append("汽车");
                        markvehic_index = i/2;
                    }
                    else if(vehi[i/2] == 3){
                        s.append("火车");
                        markvehic_index = i/2;
                    }

                    s.append("上");
                    break;
                }
            }
            else if(Time >= ttime[i] && ttime[i+1] == 0){
                s = "";
                s.append(b);
                markstate = 1;
                markcity_index = (i+1)/2;
                break;
            }
        }
    }

    while(Pas_ptr->Seq != 0)
        Pas_ptr = Pas_ptr->prev;

    return s;
}

//Output infor of new added Pas
void PrintAdd(int j, int m) {
    int i = 0;
    int time_index = Get_time_index(j);
    SetAddText = "";
    Setpara = "";
    SetInfo = "";

    SetInfo.append("旅客编号：");
    SetInfo.append(QString::number(Current_ptr->Seq));
    SetInfo.append("   出发地：");
    SetInfo.append(Current_ptr->Depart_Place);
    SetInfo.append("   目的地：");
    SetInfo.append(Current_ptr->Dest_Place);

    QString a = "出发地: ";
    QString b = "目的地: ";
    QString c = "旅客编号: ";
    QString d = "时间要求: ";
    QString e = "风险要求: ";
    QString f = "价格要求: ";

    SetAddText.append("路线:(括号内内容为城市的到达与出发时间)\n");
    while (Current_ptr->Plan.Plan_City[i] != "") {
        if (Current_ptr->Plan.Plan_City[i + 1] == "") {
            //cout << Current_ptr->Plan.Plan_City[i] << endl;
            SetAddText.append(Current_ptr->Plan.Plan_City[i]);
            SetAddText.append("(");
            SetAddText.append(QString::number(m));
            SetAddText.append(")");
        }
        else if(i == 0){
            SetAddText.append(Current_ptr->Plan.Plan_City[i]);
            SetAddText.append("(");
            SetAddText.append(QString::number(Current_ptr->Plan.Plan_Time[1]));
            SetAddText.append(")");
            SetAddText.append(" -> ");
        }
        else {
            //cout << Current_ptr->Plan.Plan_City[i] << " -> ";
            SetAddText.append(Current_ptr->Plan.Plan_City[i]);
            SetAddText.append("(");
            SetAddText.append(QString::number(Current_ptr->Plan.Plan_Time[i*2]));
            SetAddText.append(",");
            SetAddText.append(QString::number(Current_ptr->Plan.Plan_Time[i*2 + 1]));
            SetAddText.append(")");
            SetAddText.append(" -> ");
        }
        i++;
    }
    QString g = "此条路线时间: ";
    QString h = "旅行时常: ";
    QString x = "旅行风险: ";
    QString y = "   旅行价格: ";

    Setpara.append("此条路线: 时间: ");
    Setpara.append(QString::number(Current_ptr->Plan.Plan_Time[0]));
    Setpara.append("->");
    Setpara.append(QString::number(m));
    Setpara.append("   旅行时常:");
    Setpara.append(QString::number(m - Current_ptr->Plan.Plan_Time[0]));
    Setpara.append("\n");
    Setpara.append("旅行风险: ");
    Setpara.append(QString::number(Current_ptr->Plan.Plan_risk));
    Setpara.append("   旅行价格:");
    Setpara.append(QString::number(Current_ptr->Plan.Plan_Price));
}

//store pas's infor
int Assign_To_Pas(int i) {
    int j = 0;
    int result = 0;
    for (j = 0; record[i][j] != ""; j++) {
        Current_ptr->Plan.Plan_City[j] = record[i][j];
    }
    for (j = 0; plantime[i][j] != 0; j++) {
        if(plantime[i][j+1] == 0){
            result = plantime[i][j];
        }
        Current_ptr->Plan.Plan_Time[j] = plantime[i][j];
    }
    for (j = 0; planvehi[i][j] != 0; j++) {
        Current_ptr->Plan.Plan_Vehicle[j] = planvehi[i][j];
    }
    Current_ptr->Plan.Plan_risk = planrisk[i];
    Current_ptr->Plan.Plan_Price = planprice[i];

    return result;
}

//allocate route to Pas
void Add_Pas(int Seq, int Time_Req, int Risk_Req, int Price_Req, QString Depart, QString Dest, int plantype){
    Current_ptr = new Pas_List;
    a = 0, b = 0;
    init_planprice();
    init_planrisk();
    init_plantime();
    init_planvehi();
    init_record();
    init_countrecordnum();

    if (Current_ptr != NULL)
    {
        Current_ptr->Depart_Place = Depart;
        Current_ptr->Dest_Place = Dest;
        Current_ptr->Seq = Seq;
        Current_ptr->Time_Req = Time_Req;
        Current_ptr->Risk_Req = Risk_Req;
        Current_ptr->Price_Req = Price_Req;

        if (Pas_ptr == NULL)
        {
            Pas_ptr = Current_ptr;
            Pas_ptr->prev = NULL;
            Last_ptr = Current_ptr;
            Last_ptr->next = NULL;
        }
        else
        {
            Last_ptr->next = Current_ptr;
            Current_ptr->prev = Last_ptr;
            Last_ptr = Last_ptr->next;
            Last_ptr->next = NULL;
        }
    }

    if (Last_ptr != NULL)
        Last_ptr->next = NULL;

    if (Pas_ptr != NULL)
        Pas_ptr->prev = NULL;

    //Use DFS to find all path
    Find_All_Path(Current_ptr->Depart_Place, Current_ptr->Dest_Place);

    //get and store the pas plan
    Get_Pas_Plan(Timer_Time);

    //Output pas plan
    int i = Out_Pas_Plan(Time_Req, Risk_Req, Price_Req, plantype);
    int j = Assign_To_Pas(i);
    PrintAdd(i, j);

    Current_ptr = Current_ptr->next;
}

//Free the Pas
void Free_Pas(Pas_List* hPtr){
    Pas_List* freePtr;
    Pas_List* cuPtr;

    cuPtr = hPtr;

    while (cuPtr != NULL)
    {
        freePtr = cuPtr;
        cuPtr = cuPtr->next;
        delete freePtr;
    }

    freePtr = NULL;
}
#endif
