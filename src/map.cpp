#ifndef MAP_CPP
#define MAP_CPP
#include "map.h"
#include "parameters.h"

#include <QTextStream>
QTextStream cin(stdin, QIODevice::ReadOnly);
QTextStream cout(stdout, QIODevice::WriteOnly);
QTextStream cerr(stderr, QIODevice::WriteOnly);
#include <QFile>

//Free the map
void Free_Map(M* This) {
    delete This->Map_City[0];
    delete This->Map_City[1];
    delete This->Map_City[2];
    delete This->Map_City[3];
    delete This->Map_City[4];
    delete This->Map_City[5];
    delete This->Map_City[6];
    delete This->Map_City[7];
    delete This->Map_City[8];
    delete This->Map_City[9];
    delete This->Map_City[10];
    delete This->Map_City[11];
}

//初始化，从文件读入地图信息
//read map infor from map.txt
void Init_Map(M* This, int Num_City) {
    This->Map_City[0] = new City;
    This->Map_City[1] = new City;
    This->Map_City[2] = new City;
    This->Map_City[3] = new City;
    This->Map_City[4] = new City;
    This->Map_City[5] = new City;
    This->Map_City[6] = new City;
    This->Map_City[7] = new City;
    This->Map_City[8] = new City;
    This->Map_City[9] = new City;
    This->Map_City[10] = new City;
    This->Map_City[11] = new City;

    QFile map("map.txt");
    if(!map.exists())
        exit(2);
    map.open(QIODevice::ReadOnly);
    QTextStream read(&map);
    read.setAutoDetectUnicode(true);


    for(int i = 0;i<12;i++){
        QString cityinfo = "";
        cityinfo = read.readLine();
        int linelength = cityinfo.length();

        QString cityname = "";
        QString cityrisk = "";
        QString cityaja = "";
        int markrisk = 0, markaja = 0;

        for(int j = 0; j < linelength;j++){
            if(cityinfo.at(j)==" "){

                if(markaja == 0 && markrisk == 1){
                    markaja =1;
                }

                if(markrisk == 0 && markaja == 0){
                    markrisk = 1;
                }
            }
            else{
                if(markrisk == 0 && markaja == 0){
                    cityname.append(cityinfo.at(j));
                }
                else if(markrisk == 1 && markaja == 0){
                    cityrisk.append(cityinfo.at(j));
                }
                else if(markrisk == 1 && markaja == 1){
                    cityaja.append(cityinfo.at(j));
                }
            }
        }

        This->Map_City[i]->City_Name = cityname;
        int ajanum = cityaja.toInt();
        This->Map_City[i]->Count_Adj_City = ajanum;
        if(cityrisk == "0")
            This->Map_City[i]->City_Risk = City_Low_Risk;
        else if(cityrisk == "1")
            This->Map_City[i]->City_Risk = City_Medium_Risk;\
        else if(cityrisk == "2")
            This->Map_City[i]->City_Risk = City_High_Risk;


        for(int k=0; k<ajanum; k++){
            QString ajacityinfo = "";
            ajacityinfo = read.readLine();
            int ajalinelen = ajacityinfo.length();
            QString ajaname = "";
            QString ajaseq = "";
            QString ajamair = "";
            QString ajamtrain = "";
            QString ajambus = "";
            QString ajaairt = "";
            QString ajatraint = "";
            QString ajabust = "";
            int mseq = 0, mma = 0, mmt = 0, mmb = 0, mat = 0, mtt = 0, mbt = 0;



            for(int j = 0; j < ajalinelen;j++){
                if(ajacityinfo.at(j)==" "){

                    if(mseq == 1 && mma == 1 && mmt == 1 && mmb == 1 && mat == 1 && mtt == 1 && mbt == 0){
                        mbt = 1;
                    }
                    if(mseq == 1 && mma == 1 && mmt == 1 && mmb == 1 && mat == 1 && mtt == 0 && mbt == 0){
                        mtt = 1;
                    }
                    if(mseq == 1 && mma == 1 && mmt == 1 && mmb == 1 && mat == 0 && mtt == 0 && mbt == 0){
                        mat = 1;
                    }
                    if(mseq == 1 && mma == 1 && mmt == 1 && mmb == 0 && mat == 0 && mtt == 0 && mbt == 0){
                        mmb = 1;
                    }
                    if(mseq == 1 && mma == 1 && mmt == 0 && mmb == 0 && mat == 0 && mtt == 0 && mbt == 0){
                        mmt = 1;
                    }
                    if(mseq == 1 && mma == 0 && mmt == 0 && mmb == 0 && mat == 0 && mtt == 0 && mbt == 0){
                        mma = 1;
                    }
                    if(mseq == 0 && mma == 0 && mmt == 0 && mmb == 0 && mat == 0 && mtt == 0 && mbt == 0){
                        mseq = 1;
                    }



                }
                else{
                    if(mseq == 0 && mma == 0 && mmt == 0 && mmb == 0 && mat == 0 && mtt == 0 && mbt == 0){
                        ajaname.append(ajacityinfo.at(j));
                    }
                    else if(mseq == 1 && mma == 0 && mmt == 0 && mmb == 0 && mat == 0 && mtt == 0 && mbt == 0){
                        ajaseq.append(ajacityinfo.at(j));
                    }
                    else if(mseq == 1 && mma == 1 && mmt == 0 && mmb == 0 && mat == 0 && mtt == 0 && mbt == 0){
                        ajamair.append(ajacityinfo.at(j));
                    }
                    else if(mseq == 1 && mma == 1 && mmt == 1 && mmb == 0 && mat == 0 && mtt == 0 && mbt == 0){
                        ajamtrain.append(ajacityinfo.at(j));
                    }
                    else if(mseq == 1 && mma == 1 && mmt == 1 && mmb == 1 && mat == 0 && mtt == 0 && mbt == 0){
                        ajambus.append(ajacityinfo.at(j));
                    }
                    else if(mseq == 1 && mma == 1 && mmt == 1 && mmb == 1 && mat == 1 && mtt == 0 && mbt == 0){
                        ajaairt.append(ajacityinfo.at(j));
                    }
                    else if(mseq == 1 && mma == 1 && mmt == 1 && mmb == 1 && mat == 1 && mtt == 1 && mbt == 0){
                        ajatraint.append(ajacityinfo.at(j));
                    }
                    else if(mseq == 1 && mma == 1 && mmt == 1 && mmb == 1 && mat == 1 && mtt == 1 && mbt == 1){
                        ajabust.append(ajacityinfo.at(j));
                    }

                }
            }

            This->Map_City[i]->Record_Adj_City[k].Adj_Name = ajaname;
            This->Map_City[i]->Record_Adj_City[k].Seq_Name = ajaseq.toInt();
            This->Map_City[i]->Record_Adj_City[k].Mark_Air = ajamair.toInt();
            This->Map_City[i]->Record_Adj_City[k].Mark_Train = ajamtrain.toInt();
            This->Map_City[i]->Record_Adj_City[k].Mark_BUS = ajambus.toInt();
            This->Map_City[i]->Record_Adj_City[k].Air_Time = ajaairt.toInt();
            This->Map_City[i]->Record_Adj_City[k].Train_Time = ajatraint.toInt();
            This->Map_City[i]->Record_Adj_City[k].Bus_Time = ajabust.toInt();

        }
    }

    map.close();

    //Preparation to DFS
    int i = 0, j = 0;

    for(i = 0; i< 12;i++){
        This->Map_City[i]->City_State = UNPASSED_CITY;
    }

    for (i = 0; i < Num_City; i++) {
        for (j = 0; j < This->Map_City[i]->Count_Adj_City; j++) {
            This->Map_City[i]->Adj_City[j] = This->Map_City[This->Map_City[i]->Record_Adj_City[j].Seq_Name - 1];
        }
    }

}
//old version,将地图写死在程序里，现已改为上面从txt读入地图的版本
/*
void Init_Map(M* This, int Num_City) {
    This->Map_City[0] = new City;
    This->Map_City[1] = new City;
    This->Map_City[2] = new City;
    This->Map_City[3] = new City;
    This->Map_City[4] = new City;
    This->Map_City[5] = new City;
    This->Map_City[6] = new City;
    This->Map_City[7] = new City;
    This->Map_City[8] = new City;
    This->Map_City[9] = new City;
    This->Map_City[10] = new City;
    This->Map_City[11] = new City;

    cout << "in" << endl;


    FILE* map_file = fopen("map.txt", "r");
    if (!map_file)
    {
        printf("can not find file");
        exit(2);
    }

    for (int i = 0; i < 12; i++)
    {
        int risk_index = -1;
        fscanf(map_file, "%s", &This->Map_City[i]->City_Name);//读入城市名字
        fscanf(map_file, "%d", &risk_index); //读入城市风险索引
        if (0 == risk_index)
            This->Map_City[i]->City_Risk = City_Low_Risk;
        else if (1 == risk_index)
            This->Map_City[i]->City_Risk = City_Medium_Risk;
        else if (2 == risk_index)
            This->Map_City[i]->City_Risk = City_High_Risk;
        else  //出现读入错误
        {
            printf("位置 init_map 错误类型 risk_index");
            exit(0);
        }

        cout << This->Map_City[i]->City_Risk << endl;


        This->Map_City[i]->City_State = UNPASSED_CITY;
        fscanf(map_file, "%d", &This->Map_City[i]->Count_Adj_City);
        int total_adjust_city = This->Map_City[i]->Count_Adj_City;
        for (int j = 0; j < total_adjust_city; j++)
        {
            fscanf(map_file, "%s", &This->Map_City[i]->Record_Adj_City[j].Adj_Name);
            fscanf(map_file, "%d", &This->Map_City[i]->Record_Adj_City[j].Seq_Name);
            fscanf(map_file, "%d", &This->Map_City[i]->Record_Adj_City[j].Mark_Air);
            fscanf(map_file, "%d", &This->Map_City[i]->Record_Adj_City[j].Mark_Train);
            fscanf(map_file, "%d", &This->Map_City[i]->Record_Adj_City[j].Mark_BUS);
            fscanf(map_file, "%d", &This->Map_City[i]->Record_Adj_City[j].Air_Time);
            fscanf(map_file, "%d", &This->Map_City[i]->Record_Adj_City[j].Train_Time);
            fscanf(map_file, "%d", &This->Map_City[i]->Record_Adj_City[j].Bus_Time);
            cout << "name"<<This->Map_City[i]->Record_Adj_City[j].Adj_Name << endl;
            cout <<"seq"<<This->Map_City[i]->Record_Adj_City[j].Seq_Name<<endl;
        }
    }
    cout << "outt???" << endl;
    fclose(map_file);
    map_file = nullptr;
    cout << "out!" << endl;
    int i = 0, j = 0;

    for (i = 0; i < Num_City; i++) {
        for (j = 0; j < This->Map_City[i]->Count_Adj_City; j++) {
            This->Map_City[i]->Adj_City[j] = This->Map_City[This->Map_City[i]->Record_Adj_City[j].Seq_Name - 1];
        }
    }
}
*/
/*
void Init_Map(M* This, int Num_City) {
    This->Map_City[0] = new City;
    This->Map_City[1] = new City;
    This->Map_City[2] = new City;
    This->Map_City[3] = new City;
    This->Map_City[4] = new City;
    This->Map_City[5] = new City;
    This->Map_City[6] = new City;
    This->Map_City[7] = new City;
    This->Map_City[8] = new City;
    This->Map_City[9] = new City;
    This->Map_City[10] = new City;
    This->Map_City[11] = new City;

    //beijing 1
    This->Map_City[0]->City_Name = "北京";
    This->Map_City[0]->City_Risk = City_High_Risk;
    This->Map_City[0]->City_State = UNPASSED_CITY;
    This->Map_City[0]->Count_Adj_City = 4;

    This->Map_City[0]->Record_Adj_City[0].Adj_Name = "武汉";
    This->Map_City[0]->Record_Adj_City[0].Seq_Name = 6;
    This->Map_City[0]->Record_Adj_City[0].Mark_Air = 1;
    This->Map_City[0]->Record_Adj_City[0].Mark_Train = 0;
    This->Map_City[0]->Record_Adj_City[0].Mark_BUS = 0;
    This->Map_City[0]->Record_Adj_City[0].Air_Time = 2;
    This->Map_City[0]->Record_Adj_City[0].Train_Time = -1;
    This->Map_City[0]->Record_Adj_City[0].Bus_Time = -1;

    This->Map_City[0]->Record_Adj_City[1].Adj_Name = "沈阳";
    This->Map_City[0]->Record_Adj_City[1].Seq_Name = 2;
    This->Map_City[0]->Record_Adj_City[1].Mark_Air = 0;
    This->Map_City[0]->Record_Adj_City[1].Mark_Train = 0;
    This->Map_City[0]->Record_Adj_City[1].Mark_BUS = 1;
    This->Map_City[0]->Record_Adj_City[1].Air_Time = -1;
    This->Map_City[0]->Record_Adj_City[1].Train_Time = -1;
    This->Map_City[0]->Record_Adj_City[1].Bus_Time = 12;

    This->Map_City[0]->Record_Adj_City[2].Adj_Name = "南京";
    This->Map_City[0]->Record_Adj_City[2].Seq_Name = 7;
    This->Map_City[0]->Record_Adj_City[2].Mark_Air = 0;
    This->Map_City[0]->Record_Adj_City[2].Mark_Train = 1;
    This->Map_City[0]->Record_Adj_City[2].Mark_BUS = 1;
    This->Map_City[0]->Record_Adj_City[2].Air_Time = -1;
    This->Map_City[0]->Record_Adj_City[2].Train_Time = 4;
    This->Map_City[0]->Record_Adj_City[2].Bus_Time = 12;

    This->Map_City[0]->Record_Adj_City[3].Adj_Name = "西安";
    This->Map_City[0]->Record_Adj_City[3].Seq_Name = 5;
    This->Map_City[0]->Record_Adj_City[3].Mark_Air = 0;
    This->Map_City[0]->Record_Adj_City[3].Mark_Train = 1;
    This->Map_City[0]->Record_Adj_City[3].Mark_BUS = 1;
    This->Map_City[0]->Record_Adj_City[3].Air_Time = -1;
    This->Map_City[0]->Record_Adj_City[3].Train_Time = 6;
    This->Map_City[0]->Record_Adj_City[3].Bus_Time = 18;


    //shenyang 2
    This->Map_City[1]->City_Name = "沈阳";
    This->Map_City[1]->City_Risk = City_Medium_Risk;
    This->Map_City[1]->City_State = UNPASSED_CITY;
    This->Map_City[1]->Count_Adj_City = 3;

    This->Map_City[1]->Record_Adj_City[0].Adj_Name = "北京";
    This->Map_City[1]->Record_Adj_City[0].Seq_Name = 1;
    This->Map_City[1]->Record_Adj_City[0].Mark_Air = 0;
    This->Map_City[1]->Record_Adj_City[0].Mark_Train = 0;
    This->Map_City[1]->Record_Adj_City[0].Mark_BUS = 1;
    This->Map_City[1]->Record_Adj_City[0].Air_Time = -1;
    This->Map_City[1]->Record_Adj_City[0].Train_Time = -1;
    This->Map_City[1]->Record_Adj_City[0].Bus_Time = 12;

    This->Map_City[1]->Record_Adj_City[1].Adj_Name = "哈尔滨";
    This->Map_City[1]->Record_Adj_City[1].Seq_Name = 3;
    This->Map_City[1]->Record_Adj_City[1].Mark_Air = 0;
    This->Map_City[1]->Record_Adj_City[1].Mark_Train = 1;
    This->Map_City[1]->Record_Adj_City[1].Mark_BUS = 1;
    This->Map_City[1]->Record_Adj_City[1].Air_Time = -1;
    This->Map_City[1]->Record_Adj_City[1].Train_Time = 2;
    This->Map_City[1]->Record_Adj_City[1].Bus_Time = 6;

    This->Map_City[1]->Record_Adj_City[2].Adj_Name = "兰州";
    This->Map_City[1]->Record_Adj_City[2].Seq_Name = 4;
    This->Map_City[1]->Record_Adj_City[2].Mark_Air = 1;
    This->Map_City[1]->Record_Adj_City[2].Mark_Train = 0;
    This->Map_City[1]->Record_Adj_City[2].Mark_BUS = 0;
    This->Map_City[1]->Record_Adj_City[2].Air_Time = 3;
    This->Map_City[1]->Record_Adj_City[2].Train_Time = -1;
    This->Map_City[1]->Record_Adj_City[2].Bus_Time = -1;


    //haerbin 3
    This->Map_City[2]->City_Name = "哈尔滨";
    This->Map_City[2]->City_Risk = City_Low_Risk;
    This->Map_City[2]->City_State = UNPASSED_CITY;
    This->Map_City[2]->Count_Adj_City = 1;

    This->Map_City[2]->Record_Adj_City[0].Adj_Name = "沈阳";
    This->Map_City[2]->Record_Adj_City[0].Seq_Name = 2;
    This->Map_City[2]->Record_Adj_City[0].Mark_Air = 0;
    This->Map_City[2]->Record_Adj_City[0].Mark_Train = 1;
    This->Map_City[2]->Record_Adj_City[0].Mark_BUS = 1;
    This->Map_City[2]->Record_Adj_City[0].Air_Time = -1;
    This->Map_City[2]->Record_Adj_City[0].Train_Time = 2;
    This->Map_City[2]->Record_Adj_City[0].Bus_Time = 6;


    //lanzhou 4
    This->Map_City[3]->City_Name = "兰州";
    This->Map_City[3]->City_Risk = City_Low_Risk;
    This->Map_City[3]->City_State = UNPASSED_CITY;
    This->Map_City[3]->Count_Adj_City = 2;

    This->Map_City[3]->Record_Adj_City[0].Adj_Name = "沈阳";
    This->Map_City[3]->Record_Adj_City[0].Seq_Name = 2;
    This->Map_City[3]->Record_Adj_City[0].Mark_Air = 1;
    This->Map_City[3]->Record_Adj_City[0].Mark_Train = 0;
    This->Map_City[3]->Record_Adj_City[0].Mark_BUS = 0;
    This->Map_City[3]->Record_Adj_City[0].Air_Time = 3;
    This->Map_City[3]->Record_Adj_City[0].Train_Time = -1;
    This->Map_City[3]->Record_Adj_City[0].Bus_Time = -1;

    This->Map_City[3]->Record_Adj_City[1].Adj_Name = "西安";
    This->Map_City[3]->Record_Adj_City[1].Seq_Name = 5;
    This->Map_City[3]->Record_Adj_City[1].Mark_Air = 0;
    This->Map_City[3]->Record_Adj_City[1].Mark_Train = 1;
    This->Map_City[3]->Record_Adj_City[1].Mark_BUS = 1;
    This->Map_City[3]->Record_Adj_City[1].Air_Time = -1;
    This->Map_City[3]->Record_Adj_City[1].Train_Time = 3;
    This->Map_City[3]->Record_Adj_City[1].Bus_Time = 9;


    //xian 5
    This->Map_City[4]->City_Name = "西安";
    This->Map_City[4]->City_Risk = City_Medium_Risk;
    This->Map_City[4]->City_State = UNPASSED_CITY;
    This->Map_City[4]->Count_Adj_City = 5;

    This->Map_City[4]->Record_Adj_City[0].Adj_Name = "北京";
    This->Map_City[4]->Record_Adj_City[0].Seq_Name = 1;
    This->Map_City[4]->Record_Adj_City[0].Mark_Air = 0;
    This->Map_City[4]->Record_Adj_City[0].Mark_Train = 1;
    This->Map_City[4]->Record_Adj_City[0].Mark_BUS = 1;
    This->Map_City[4]->Record_Adj_City[0].Air_Time = -1;
    This->Map_City[4]->Record_Adj_City[0].Train_Time = 6;
    This->Map_City[4]->Record_Adj_City[0].Bus_Time = 18;

    This->Map_City[4]->Record_Adj_City[1].Adj_Name = "成都";
    This->Map_City[4]->Record_Adj_City[1].Seq_Name = 8;
    This->Map_City[4]->Record_Adj_City[1].Mark_Air = 0;
    This->Map_City[4]->Record_Adj_City[1].Mark_Train = 1;
    This->Map_City[4]->Record_Adj_City[1].Mark_BUS = 1;
    This->Map_City[4]->Record_Adj_City[1].Air_Time = -1;
    This->Map_City[4]->Record_Adj_City[1].Train_Time = 4;
    This->Map_City[4]->Record_Adj_City[1].Bus_Time = 12;

    This->Map_City[4]->Record_Adj_City[2].Adj_Name = "武汉";
    This->Map_City[4]->Record_Adj_City[2].Seq_Name = 6;
    This->Map_City[4]->Record_Adj_City[2].Mark_Air = 0;
    This->Map_City[4]->Record_Adj_City[2].Mark_Train = 1;
    This->Map_City[4]->Record_Adj_City[2].Mark_BUS = 1;
    This->Map_City[4]->Record_Adj_City[2].Air_Time = -1;
    This->Map_City[4]->Record_Adj_City[2].Train_Time = 4;
    This->Map_City[4]->Record_Adj_City[2].Bus_Time = 12;

    This->Map_City[4]->Record_Adj_City[3].Adj_Name = "昆明";
    This->Map_City[4]->Record_Adj_City[3].Seq_Name = 9;
    This->Map_City[4]->Record_Adj_City[3].Mark_Air = 1;
    This->Map_City[4]->Record_Adj_City[3].Mark_Train = 0;
    This->Map_City[4]->Record_Adj_City[3].Mark_BUS = 0;
    This->Map_City[4]->Record_Adj_City[3].Air_Time = 2;
    This->Map_City[4]->Record_Adj_City[3].Train_Time = -1;
    This->Map_City[4]->Record_Adj_City[3].Bus_Time = -1;

    This->Map_City[4]->Record_Adj_City[4].Adj_Name = "兰州";
    This->Map_City[4]->Record_Adj_City[4].Seq_Name = 4;
    This->Map_City[4]->Record_Adj_City[4].Mark_Air = 0;
    This->Map_City[4]->Record_Adj_City[4].Mark_Train = 1;
    This->Map_City[4]->Record_Adj_City[4].Mark_BUS = 1;
    This->Map_City[4]->Record_Adj_City[4].Air_Time = -1;
    This->Map_City[4]->Record_Adj_City[4].Train_Time = 3;
    This->Map_City[4]->Record_Adj_City[4].Bus_Time = 9;


    //wuhan 6
    This->Map_City[5]->City_Name = "武汉";
    This->Map_City[5]->City_Risk = City_High_Risk;
    This->Map_City[5]->City_State = UNPASSED_CITY;
    This->Map_City[5]->Count_Adj_City = 5;

    This->Map_City[5]->Record_Adj_City[0].Adj_Name = "北京";
    This->Map_City[5]->Record_Adj_City[0].Seq_Name = 1;
    This->Map_City[5]->Record_Adj_City[0].Mark_Air = 1;
    This->Map_City[5]->Record_Adj_City[0].Mark_Train = 0;
    This->Map_City[5]->Record_Adj_City[0].Mark_BUS = 0;
    This->Map_City[5]->Record_Adj_City[0].Air_Time = 2;
    This->Map_City[5]->Record_Adj_City[0].Train_Time = -1;
    This->Map_City[5]->Record_Adj_City[0].Bus_Time = -1;

    This->Map_City[5]->Record_Adj_City[1].Adj_Name = "南京";
    This->Map_City[5]->Record_Adj_City[1].Seq_Name = 7;
    This->Map_City[5]->Record_Adj_City[1].Mark_Air = 0;
    This->Map_City[5]->Record_Adj_City[1].Mark_Train = 1;
    This->Map_City[5]->Record_Adj_City[1].Mark_BUS = 1;
    This->Map_City[5]->Record_Adj_City[1].Air_Time = -1;
    This->Map_City[5]->Record_Adj_City[1].Train_Time = 3;
    This->Map_City[5]->Record_Adj_City[1].Bus_Time = 9;

    This->Map_City[5]->Record_Adj_City[2].Adj_Name = "西安";
    This->Map_City[5]->Record_Adj_City[2].Seq_Name = 5;
    This->Map_City[5]->Record_Adj_City[2].Mark_Air = 0;
    This->Map_City[5]->Record_Adj_City[2].Mark_Train = 1;
    This->Map_City[5]->Record_Adj_City[2].Mark_BUS = 1;
    This->Map_City[5]->Record_Adj_City[2].Air_Time = -1;
    This->Map_City[5]->Record_Adj_City[2].Train_Time = 4;
    This->Map_City[5]->Record_Adj_City[2].Bus_Time = 12;

    This->Map_City[5]->Record_Adj_City[3].Adj_Name = "长沙";
    This->Map_City[5]->Record_Adj_City[3].Seq_Name = 10;
    This->Map_City[5]->Record_Adj_City[3].Mark_Air = 0;
    This->Map_City[5]->Record_Adj_City[3].Mark_Train = 1;
    This->Map_City[5]->Record_Adj_City[3].Mark_BUS = 1;
    This->Map_City[5]->Record_Adj_City[3].Air_Time = -1;
    This->Map_City[5]->Record_Adj_City[3].Train_Time = 1;
    This->Map_City[5]->Record_Adj_City[3].Bus_Time = 3;

    This->Map_City[5]->Record_Adj_City[4].Adj_Name = "福州";
    This->Map_City[5]->Record_Adj_City[4].Seq_Name = 11;
    This->Map_City[5]->Record_Adj_City[4].Mark_Air = 0;
    This->Map_City[5]->Record_Adj_City[4].Mark_Train = 1;
    This->Map_City[5]->Record_Adj_City[4].Mark_BUS = 1;
    This->Map_City[5]->Record_Adj_City[4].Air_Time = -1;
    This->Map_City[5]->Record_Adj_City[4].Train_Time = 5;
    This->Map_City[5]->Record_Adj_City[4].Bus_Time = 15;



    //nanjing 7
    This->Map_City[6]->City_Name = "南京";
    This->Map_City[6]->City_Risk = City_Medium_Risk;
    This->Map_City[6]->City_State = UNPASSED_CITY;
    This->Map_City[6]->Count_Adj_City = 3;

    This->Map_City[6]->Record_Adj_City[0].Adj_Name = "北京";
    This->Map_City[6]->Record_Adj_City[0].Seq_Name = 1;
    This->Map_City[6]->Record_Adj_City[0].Mark_Air = 0;
    This->Map_City[6]->Record_Adj_City[0].Mark_Train = 1;
    This->Map_City[6]->Record_Adj_City[0].Mark_BUS = 1;
    This->Map_City[6]->Record_Adj_City[0].Air_Time = -1;
    This->Map_City[6]->Record_Adj_City[0].Train_Time = 4;
    This->Map_City[6]->Record_Adj_City[0].Bus_Time = 12;

    This->Map_City[6]->Record_Adj_City[1].Adj_Name = "广州";
    This->Map_City[6]->Record_Adj_City[1].Seq_Name = 12;
    This->Map_City[6]->Record_Adj_City[1].Mark_Air = 1;
    This->Map_City[6]->Record_Adj_City[1].Mark_Train = 0;
    This->Map_City[6]->Record_Adj_City[1].Mark_BUS = 0;
    This->Map_City[6]->Record_Adj_City[1].Air_Time = 2;
    This->Map_City[6]->Record_Adj_City[1].Train_Time = -1;
    This->Map_City[6]->Record_Adj_City[1].Bus_Time = -1;

    This->Map_City[6]->Record_Adj_City[2].Adj_Name = "武汉";
    This->Map_City[6]->Record_Adj_City[2].Seq_Name = 6;
    This->Map_City[6]->Record_Adj_City[2].Mark_Air = 0;
    This->Map_City[6]->Record_Adj_City[2].Mark_Train = 1;
    This->Map_City[6]->Record_Adj_City[2].Mark_BUS = 1;
    This->Map_City[6]->Record_Adj_City[2].Air_Time = -1;
    This->Map_City[6]->Record_Adj_City[2].Train_Time = 3;
    This->Map_City[6]->Record_Adj_City[2].Bus_Time = 9;


    //chengdu 8
    This->Map_City[7]->City_Name = "成都";
    This->Map_City[7]->City_Risk = City_High_Risk;
    This->Map_City[7]->City_State = UNPASSED_CITY;
    This->Map_City[7]->Count_Adj_City = 4;

    This->Map_City[7]->Record_Adj_City[0].Adj_Name = "西安";
    This->Map_City[7]->Record_Adj_City[0].Seq_Name = 5;
    This->Map_City[7]->Record_Adj_City[0].Mark_Air = 0;
    This->Map_City[7]->Record_Adj_City[0].Mark_Train = 1;
    This->Map_City[7]->Record_Adj_City[0].Mark_BUS = 1;
    This->Map_City[7]->Record_Adj_City[0].Air_Time = -1;
    This->Map_City[7]->Record_Adj_City[0].Train_Time = 4;
    This->Map_City[7]->Record_Adj_City[0].Bus_Time = 12;

    This->Map_City[7]->Record_Adj_City[1].Adj_Name = "昆明";
    This->Map_City[7]->Record_Adj_City[1].Seq_Name = 9;
    This->Map_City[7]->Record_Adj_City[1].Mark_Air = 0;
    This->Map_City[7]->Record_Adj_City[1].Mark_Train = 1;
    This->Map_City[7]->Record_Adj_City[1].Mark_BUS = 1;
    This->Map_City[7]->Record_Adj_City[1].Air_Time = -1;
    This->Map_City[7]->Record_Adj_City[1].Train_Time = 6;
    This->Map_City[7]->Record_Adj_City[1].Bus_Time = 18;

    This->Map_City[7]->Record_Adj_City[2].Adj_Name = "长沙";
    This->Map_City[7]->Record_Adj_City[2].Seq_Name = 10;
    This->Map_City[7]->Record_Adj_City[2].Mark_Air = 0;
    This->Map_City[7]->Record_Adj_City[2].Mark_Train = 1;
    This->Map_City[7]->Record_Adj_City[2].Mark_BUS = 0;
    This->Map_City[7]->Record_Adj_City[2].Air_Time = -1;
    This->Map_City[7]->Record_Adj_City[2].Train_Time = 7;
    This->Map_City[7]->Record_Adj_City[2].Bus_Time = -1;

    This->Map_City[7]->Record_Adj_City[3].Adj_Name = "福州";
    This->Map_City[7]->Record_Adj_City[3].Seq_Name = 11;
    This->Map_City[7]->Record_Adj_City[3].Mark_Air = 1;
    This->Map_City[7]->Record_Adj_City[3].Mark_Train = 0;
    This->Map_City[7]->Record_Adj_City[3].Mark_BUS = 0;
    This->Map_City[7]->Record_Adj_City[3].Air_Time = 4;
    This->Map_City[7]->Record_Adj_City[3].Train_Time = -1;
    This->Map_City[7]->Record_Adj_City[3].Bus_Time = -1;


    //kunming 9
    This->Map_City[8]->City_Name = "昆明";
    This->Map_City[8]->City_Risk = City_Medium_Risk;
    This->Map_City[8]->City_State = UNPASSED_CITY;
    This->Map_City[8]->Count_Adj_City = 3;

    This->Map_City[8]->Record_Adj_City[0].Adj_Name = "成都";
    This->Map_City[8]->Record_Adj_City[0].Seq_Name = 8;
    This->Map_City[8]->Record_Adj_City[0].Mark_Air = 0;
    This->Map_City[8]->Record_Adj_City[0].Mark_Train = 1;
    This->Map_City[8]->Record_Adj_City[0].Mark_BUS = 1;
    This->Map_City[8]->Record_Adj_City[0].Air_Time = -1;
    This->Map_City[8]->Record_Adj_City[0].Train_Time = 6;
    This->Map_City[8]->Record_Adj_City[0].Bus_Time = 18;

    This->Map_City[8]->Record_Adj_City[1].Adj_Name = "西安";
    This->Map_City[8]->Record_Adj_City[1].Seq_Name = 5;
    This->Map_City[8]->Record_Adj_City[1].Mark_Air = 1;
    This->Map_City[8]->Record_Adj_City[1].Mark_Train = 0;
    This->Map_City[8]->Record_Adj_City[1].Mark_BUS = 0;
    This->Map_City[8]->Record_Adj_City[1].Air_Time = 2;
    This->Map_City[8]->Record_Adj_City[1].Train_Time = -1;
    This->Map_City[8]->Record_Adj_City[1].Bus_Time = -1;

    This->Map_City[8]->Record_Adj_City[2].Adj_Name = "长沙";
    This->Map_City[8]->Record_Adj_City[2].Seq_Name = 10;
    This->Map_City[8]->Record_Adj_City[2].Mark_Air = 0;
    This->Map_City[8]->Record_Adj_City[2].Mark_Train = 1;
    This->Map_City[8]->Record_Adj_City[2].Mark_BUS = 1;
    This->Map_City[8]->Record_Adj_City[2].Air_Time = -1;
    This->Map_City[8]->Record_Adj_City[2].Train_Time = 5;
    This->Map_City[8]->Record_Adj_City[2].Bus_Time = 15;


    //changsha 10
    This->Map_City[9]->City_Name = "长沙";
    This->Map_City[9]->City_Risk = City_Low_Risk;
    This->Map_City[9]->City_State = UNPASSED_CITY;
    This->Map_City[9]->Count_Adj_City = 4;

    This->Map_City[9]->Record_Adj_City[0].Adj_Name = "成都";
    This->Map_City[9]->Record_Adj_City[0].Seq_Name = 8;
    This->Map_City[9]->Record_Adj_City[0].Mark_Air = 0;
    This->Map_City[9]->Record_Adj_City[0].Mark_Train = 1;
    This->Map_City[9]->Record_Adj_City[0].Mark_BUS = 0;
    This->Map_City[9]->Record_Adj_City[0].Air_Time = -1;
    This->Map_City[9]->Record_Adj_City[0].Train_Time = 7;
    This->Map_City[9]->Record_Adj_City[0].Bus_Time = -1;

    This->Map_City[9]->Record_Adj_City[1].Adj_Name = "广州";
    This->Map_City[9]->Record_Adj_City[1].Seq_Name = 12;
    This->Map_City[9]->Record_Adj_City[1].Mark_Air = 0;
    This->Map_City[9]->Record_Adj_City[1].Mark_Train = 1;
    This->Map_City[9]->Record_Adj_City[1].Mark_BUS = 1;
    This->Map_City[9]->Record_Adj_City[1].Air_Time = -1;
    This->Map_City[9]->Record_Adj_City[1].Train_Time = 2;
    This->Map_City[9]->Record_Adj_City[1].Bus_Time = 6;

    This->Map_City[9]->Record_Adj_City[2].Adj_Name = "武汉";
    This->Map_City[9]->Record_Adj_City[2].Seq_Name = 6;
    This->Map_City[9]->Record_Adj_City[2].Mark_Air = 0;
    This->Map_City[9]->Record_Adj_City[2].Mark_Train = 1;
    This->Map_City[9]->Record_Adj_City[2].Mark_BUS = 1;
    This->Map_City[9]->Record_Adj_City[2].Air_Time = -1;
    This->Map_City[9]->Record_Adj_City[2].Train_Time = 1;
    This->Map_City[9]->Record_Adj_City[2].Bus_Time = 3;

    This->Map_City[9]->Record_Adj_City[3].Adj_Name = "昆明";
    This->Map_City[9]->Record_Adj_City[3].Seq_Name = 9;
    This->Map_City[9]->Record_Adj_City[3].Mark_Air = 0;
    This->Map_City[9]->Record_Adj_City[3].Mark_Train = 1;
    This->Map_City[9]->Record_Adj_City[3].Mark_BUS = 1;
    This->Map_City[9]->Record_Adj_City[3].Air_Time = -1;
    This->Map_City[9]->Record_Adj_City[3].Train_Time = 5;
    This->Map_City[9]->Record_Adj_City[3].Bus_Time = 15;


    //fuzhou 11
    This->Map_City[10]->City_Name = "福州";
    This->Map_City[10]->City_Risk = City_Low_Risk;
    This->Map_City[10]->City_State = UNPASSED_CITY;
    This->Map_City[10]->Count_Adj_City = 3;

    This->Map_City[10]->Record_Adj_City[0].Adj_Name = "成都";
    This->Map_City[10]->Record_Adj_City[0].Seq_Name = 8;
    This->Map_City[10]->Record_Adj_City[0].Mark_Air = 1;
    This->Map_City[10]->Record_Adj_City[0].Mark_Train = 0;
    This->Map_City[10]->Record_Adj_City[0].Mark_BUS = 0;
    This->Map_City[10]->Record_Adj_City[0].Air_Time = 4;
    This->Map_City[10]->Record_Adj_City[0].Train_Time = -1;
    This->Map_City[10]->Record_Adj_City[0].Bus_Time = -1;

    This->Map_City[10]->Record_Adj_City[1].Adj_Name = "广州";
    This->Map_City[10]->Record_Adj_City[1].Seq_Name = 12;
    This->Map_City[10]->Record_Adj_City[1].Mark_Air = 0;
    This->Map_City[10]->Record_Adj_City[1].Mark_Train = 1;
    This->Map_City[10]->Record_Adj_City[1].Mark_BUS = 1;
    This->Map_City[10]->Record_Adj_City[1].Air_Time = -1;
    This->Map_City[10]->Record_Adj_City[1].Train_Time = 5;
    This->Map_City[10]->Record_Adj_City[1].Bus_Time = 15;

    This->Map_City[10]->Record_Adj_City[2].Adj_Name = "武汉";
    This->Map_City[10]->Record_Adj_City[2].Seq_Name = 6;
    This->Map_City[10]->Record_Adj_City[2].Mark_Air = 0;
    This->Map_City[10]->Record_Adj_City[2].Mark_Train = 1;
    This->Map_City[10]->Record_Adj_City[2].Mark_BUS = 1;
    This->Map_City[10]->Record_Adj_City[2].Air_Time = -1;
    This->Map_City[10]->Record_Adj_City[2].Train_Time = 5;
    This->Map_City[10]->Record_Adj_City[2].Bus_Time = 15;


    //guangzhou 12
    This->Map_City[11]->City_Name = "广州";
    This->Map_City[11]->City_Risk = City_High_Risk;
    This->Map_City[11]->City_State = UNPASSED_CITY;
    This->Map_City[11]->Count_Adj_City = 3;

    This->Map_City[11]->Record_Adj_City[0].Adj_Name = "南京";
    This->Map_City[11]->Record_Adj_City[0].Seq_Name = 7;
    This->Map_City[11]->Record_Adj_City[0].Mark_Air = 1;
    This->Map_City[11]->Record_Adj_City[0].Mark_Train = 0;
    This->Map_City[11]->Record_Adj_City[0].Mark_BUS = 0;
    This->Map_City[11]->Record_Adj_City[0].Air_Time = 2;
    This->Map_City[11]->Record_Adj_City[0].Train_Time = -1;
    This->Map_City[11]->Record_Adj_City[0].Bus_Time = -1;

    This->Map_City[11]->Record_Adj_City[1].Adj_Name = "长沙";
    This->Map_City[11]->Record_Adj_City[1].Seq_Name = 10;
    This->Map_City[11]->Record_Adj_City[1].Mark_Air = 0;
    This->Map_City[11]->Record_Adj_City[1].Mark_Train = 1;
    This->Map_City[11]->Record_Adj_City[1].Mark_BUS = 1;
    This->Map_City[11]->Record_Adj_City[1].Air_Time = -1;
    This->Map_City[11]->Record_Adj_City[1].Train_Time = 2;
    This->Map_City[11]->Record_Adj_City[1].Bus_Time = 6;

    This->Map_City[11]->Record_Adj_City[2].Adj_Name = "福州";
    This->Map_City[11]->Record_Adj_City[2].Seq_Name = 11;
    This->Map_City[11]->Record_Adj_City[2].Mark_Air = 0;
    This->Map_City[11]->Record_Adj_City[2].Mark_Train = 1;
    This->Map_City[11]->Record_Adj_City[2].Mark_BUS = 1;
    This->Map_City[11]->Record_Adj_City[2].Air_Time = -1;
    This->Map_City[11]->Record_Adj_City[2].Train_Time = 5;
    This->Map_City[11]->Record_Adj_City[2].Bus_Time = 15;

    int i = 0, j = 0;

    for (i = 0; i < Num_City; i++) {
        for (j = 0; j < This->Map_City[i]->Count_Adj_City; j++) {
            This->Map_City[i]->Adj_City[j] = This->Map_City[This->Map_City[i]->Record_Adj_City[j].Seq_Name - 1];
        }
    }
}
*/
#endif
