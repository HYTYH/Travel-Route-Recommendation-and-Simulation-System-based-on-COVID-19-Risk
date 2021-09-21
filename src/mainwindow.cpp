#ifndef MAINWINDOW_CPP
#define MAINWINDOW_CPP
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "passenger.cpp"
#include <QPainter>
#include <QFile>
#include <QRect>
#include <QImage>
#include <QPen>
#include <QFont>
#include <QPalette>

//declaration of Passengerlog
QFile filepas("Passengerlog.txt");
QTextStream outp(&filepas);

//declaration of Timelog
QFile filetime("Timelog.txt");
QTextStream outt(&filetime);

//declaration of Searchlog
QFile filesearch("Searchlog.txt");
QTextStream outs(&filesearch);

using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->ptimer = new QTimer;

    //installEventFilter to catch QPainter event
    ui->hashen->installEventFilter(this);
    ui->shenbei->installEventFilter(this);
    ui->beinan->installEventFilter(this);
    ui->beiwu->installEventFilter(this);
    ui->beixi->installEventFilter(this);
    ui->lanxi->installEventFilter(this);
    ui->shenlan->installEventFilter(this);
    ui->xiwu->installEventFilter(this);
    ui->nanwu->installEventFilter(this);
    ui->xicheng->installEventFilter(this);
    ui->xikun->installEventFilter(this);
    ui->chengkun->installEventFilter(this);
    ui->chengchang->installEventFilter(this);
    ui->wuchang->installEventFilter(this);
    ui->wufu->installEventFilter(this);
    ui->changkun->installEventFilter(this);
    ui->changguang->installEventFilter(this);
    ui->fuguang->installEventFilter(this);
    ui->chengfu->installEventFilter(this);
    ui->nanguang->installEventFilter(this);

    //Set visibility of route
    ui->hashen->setVisible(false);
    ui->shenbei->setVisible(false);
    ui->beinan->setVisible(false);
    ui->beiwu->setVisible(false);
    ui->beixi->setVisible(false);
    ui->lanxi->setVisible(false);
    ui->shenlan->setVisible(false);
    ui->xiwu->setVisible(false);
    ui->nanwu->setVisible(false);
    ui->xicheng->setVisible(false);
    ui->xikun->setVisible(false);
    ui->chengkun->setVisible(false);
    ui->chengchang->setVisible(false);
    ui->wuchang->setVisible(false);
    ui->wufu->setVisible(false);
    ui->changkun->setVisible(false);
    ui->changguang->setVisible(false);
    ui->fuguang->setVisible(false);
    ui->chengfu->setVisible(false);
    ui->nanguang->setVisible(false);

    //connecting signal to function
    connect(this->ui->AddPas,SIGNAL(clicked(bool)),this,SLOT(on_AddPas_clicked()),Qt::UniqueConnection);
    connect(this->ui->Stop,SIGNAL(clicked(bool)),this,SLOT(on_Stop_clicked()),Qt::UniqueConnection);
    connect(this->ptimer, SIGNAL(timeout()), this, SLOT(Update_Num()),Qt::UniqueConnection);

    //Set enable of control buttons
    this->ui->Stop->setEnabled(false);
    this->ui->Pause->setEnabled(false);
    this->ui->LBL_PIC->setScaledContents(true);

    //import map picture
    this->ui->LBL_PIC->setPixmap(QPixmap(":/new/mapc.jpg"));

    //clear logs everytime log in system
    filepas.open(QIODevice::WriteOnly);
    filepas.close();
    filetime.open(QIODevice::WriteOnly);
    filetime.close();
    filesearch.open(QIODevice::WriteOnly);
    filesearch.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//installEventFilter to catch QPainter event
bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == ui->hashen && event->type() == QEvent::Paint)
    {
        paint_hashen();
    }
    if(watched == ui->shenbei && event->type() == QEvent::Paint)
    {
        paint_shenbei();
    }
    if(watched == ui->beinan && event->type() == QEvent::Paint)
    {
        paint_beinan();
    }
    if(watched == ui->beiwu && event->type() == QEvent::Paint)
    {
        paint_beiwu();
    }
    if(watched == ui->beixi && event->type() == QEvent::Paint)
    {
        paint_beixi();
    }
    if(watched == ui->lanxi && event->type() == QEvent::Paint)
    {
        paint_lanxi();
    }
    if(watched == ui->shenlan && event->type() == QEvent::Paint)
    {
        paint_shenlan();
    }
    if(watched == ui->xiwu && event->type() == QEvent::Paint)
    {
        paint_xiwu();
    }
    if(watched == ui->nanwu && event->type() == QEvent::Paint)
    {
        paint_nanwu();
    }
    if(watched == ui->xicheng && event->type() == QEvent::Paint)
    {
        paint_xicheng();
    }
    if(watched == ui->xikun && event->type() == QEvent::Paint)
    {
        paint_xikun();
    }
    if(watched == ui->chengkun && event->type() == QEvent::Paint)
    {
        paint_chengkun();
    }
    if(watched == ui->chengchang && event->type() == QEvent::Paint)
    {
        paint_chengchang();
    }
    if(watched == ui->wuchang && event->type() == QEvent::Paint)
    {
        paint_wuchang();
    }
    if(watched == ui->wufu && event->type() == QEvent::Paint)
    {
        paint_wufu();
    }
    if(watched == ui->changkun && event->type() == QEvent::Paint)
    {
        paint_changkun();
    }
    if(watched == ui->changguang && event->type() == QEvent::Paint)
    {
        paint_changguang();
    }
    if(watched == ui->fuguang && event->type() == QEvent::Paint)
    {
        paint_fuguang();
    }
    if(watched == ui->chengfu && event->type() == QEvent::Paint)
    {
        paint_chengfu();
    }
    if(watched == ui->nanguang && event->type() == QEvent::Paint)
    {
        paint_nanguang();
    }

    return QWidget::eventFilter(watched,event);
}

//Use QPainter to paint route
void MainWindow::paint_hashen()
{
    QPainter painter(ui->hashen);
    painter.setPen(Qt::darkGreen);
    painter.drawLine(0,68,41,0);
}

//Use QPainter to paint route
void MainWindow::paint_shenbei()
{
    QPainter painter(ui->shenbei);
    painter.setPen(Qt::darkGreen);
    painter.drawLine(0,21,91,0);
}

//Use QPainter to paint route
void MainWindow::paint_beinan()
{
    QPainter painter(ui->beinan);
    painter.setPen(Qt::darkGreen);
    painter.drawLine(0,0,31,111);
}

//Use QPainter to paint route
void MainWindow::paint_beiwu()
{
    QPainter painter(ui->beiwu);
    painter.setPen(Qt::darkGreen);
    painter.drawLine(0,131,21,0);
}

//Use QPainter to paint route
void MainWindow::paint_beixi()
{
    QPainter painter(ui->beixi);
    painter.setPen(Qt::darkGreen);
    painter.drawLine(0,81,91,0);
}

//Use QPainter to paint route
void MainWindow::paint_lanxi()
{
    QPainter painter(ui->lanxi);
    painter.setPen(Qt::darkGreen);
    painter.drawLine(0,0,71,31);
}

//Use QPainter to paint route
void MainWindow::paint_shenlan()
{
    QPainter painter(ui->shenlan);
    painter.setPen(Qt::darkGreen);
    painter.drawLine(0,81,261,0);
}

//Use QPainter to paint route
void MainWindow::paint_xiwu()
{
    QPainter painter(ui->xiwu);
    painter.setPen(Qt::darkGreen);
    painter.drawLine(0,0,71,51);
}

//Use QPainter to paint route
void MainWindow::paint_nanwu()
{
    QPainter painter(ui->nanwu);
    painter.setPen(Qt::darkGreen);
    painter.drawLine(0,20,61,0);
}

//Use QPainter to paint route
void MainWindow::paint_xicheng()
{
    QPainter painter(ui->xicheng);
    painter.setPen(Qt::darkGreen);
    painter.drawLine(0,51,71,0);
}

//Use QPainter to paint route
void MainWindow::paint_xikun()
{
    QPainter painter(ui->xikun);
    painter.setPen(Qt::darkGreen);
    painter.drawLine(0,121,81,0);
}

//Use QPainter to paint route
void MainWindow::paint_chengkun()
{
    QPainter painter(ui->chengkun);
    painter.setPen(Qt::darkGreen);
    painter.drawLine(4,71,21,0);
}

//Use QPainter to paint route
void MainWindow::paint_chengchang()
{
    QPainter painter(ui->chengchang);
    painter.setPen(Qt::darkGreen);
    painter.drawLine(0,0,121,31);
}

//Use QPainter to paint route
void MainWindow::paint_wuchang()
{
    QPainter painter(ui->wuchang);
    painter.setPen(Qt::darkGreen);
    painter.drawLine(0,31,20,0);
}

//Use QPainter to paint route
void MainWindow::paint_wufu()
{
    QPainter painter(ui->wufu);
    painter.setPen(Qt::darkGreen);
    painter.drawLine(0,0,71,61);
}

//Use QPainter to paint route
void MainWindow::paint_changkun()
{
    QPainter painter(ui->changkun);
    painter.setPen(Qt::darkGreen);
    painter.drawLine(0,49,131,0);
}

//Use QPainter to paint route
void MainWindow::paint_changguang()
{
    QPainter painter(ui->changguang);
    painter.setPen(Qt::darkGreen);
    painter.drawLine(0,0,3,69);
}

//Use QPainter to paint route
void MainWindow::paint_fuguang()
{
    QPainter painter(ui->fuguang);
    painter.setPen(Qt::darkGreen);
    painter.drawLine(2,40,81,0);
}

//Use QPainter to paint route
void MainWindow::paint_chengfu()
{
    QPainter painter(ui->chengfu);
    painter.setPen(Qt::darkGreen);
    painter.drawLine(0,0,200,61);
}

//Use QPainter to paint route
void MainWindow::paint_nanguang()
{
    QPainter painter(ui->nanguang);
    painter.setPen(Qt::darkGreen);
    painter.drawLine(0,120,70,0);
}

//Update information when the timer is exceed
void MainWindow::Update_Num()
{
    //Initiallize
    this->ui->TIME->setStyleSheet("color:black;background:silver;");
    this->ui->TIME->display(Timer_Time);

    Pas_List* temp = NULL;
    temp = Pas_ptr;

    QString d = "";
    QString vehicle = "";
    QString citytemp = "";
    QString text = "";


    //clear old information
    if(this->ui->AddDepart->toPlainText() != "")
        this->ui->AddDepart->clear();

    if(this->ui->AddDest->toPlainText() != "")
        this->ui->AddDest->clear();

    if(this->ui->AddTimeReq->toPlainText() != "")
        this->ui->AddTimeReq->clear();

    if(this->ui->AddRiskReq->toPlainText() != "")
        this->ui->AddRiskReq->clear();

    if(this->ui->AddPriceReq->toPlainText() != "")
        this->ui->AddPriceReq->clear();

    if(this->ui->SeqAllocate->toPlainText() != "")
        this->ui->SeqAllocate->clear();

    if(this->ui->AddPlan->toPlainText() != "")
        this->ui->AddPlan->clear();

    if(this->ui->AddPlan->toPlainText() != "")
        this->ui->AddPlan->clear();

    if(this->ui->RealTimeInfo->toPlainText() != "")
        this->ui->RealTimeInfo->clear();

    if(this->ui->SearchSeq->toPlainText() != "")
        this->ui->SearchSeq->clear();

    if(this->ui->SearchTime->toPlainText() != "")
        this->ui->SearchTime->clear();

    if(this->ui->PasState->toPlainText() != "")
        this->ui->PasState->clear();

    if(this->ui->RealTimeInfo->toPlainText() != "")
        this->ui->RealTimeInfo->clear();

    if(this->ui->beijing->text() != "")
        this->ui->beijing->clear();

    if(this->ui->wuhan->text() != "")
        this->ui->wuhan->clear();

    if(this->ui->haerbin->text() != "")
        this->ui->haerbin->clear();

    if(this->ui->shenyang->text() != "")
        this->ui->shenyang->clear();

    if(this->ui->lanzhou->text() != "")
        this->ui->lanzhou->clear();

    if(this->ui->guangzhou->text() != "")
        this->ui->guangzhou->clear();

    if(this->ui->fuzhou->text() != "")
        this->ui->fuzhou->clear();

    if(this->ui->xian->text() != "")
        this->ui->xian->clear();

    if(this->ui->nanjing->text() != "")
        this->ui->nanjing->clear();

    if(this->ui->chengdu->text() != "")
        this->ui->chengdu->clear();

    if(this->ui->kunming->text() != "")
        this->ui->kunming->clear();

    if(this->ui->changsha->text() != "")
        this->ui->changsha->clear();

    if(this->ui->hashen->text() != "")
        this->ui->hashen->clear();

    if(this->ui->shenbei->text() != "")
        this->ui->shenbei->clear();

    if(this->ui->shenlan->text() != "")
        this->ui->shenlan->clear();

    if(this->ui->beinan->text() != "")
        this->ui->beinan->clear();

    if(this->ui->beiwu->text() != "")
        this->ui->beiwu->clear();

    if(this->ui->beixi->text() != "")
        this->ui->beixi->clear();

    if(this->ui->lanxi->text() != "")
        this->ui->lanxi->clear();

    if(this->ui->xicheng->text() != "")
        this->ui->xicheng->clear();

    if(this->ui->xiwu->text() != "")
        this->ui->xiwu->clear();

    if(this->ui->xikun->text() != "")
        this->ui->xikun->clear();

    if(this->ui->nanwu->text() != "")
        this->ui->nanwu->clear();

    if(this->ui->wufu->text() != "")
        this->ui->wufu->clear();

    if(this->ui->wuchang->text() != "")
        this->ui->wuchang->clear();

    if(this->ui->nanguang->text() != "")
        this->ui->nanguang->clear();

    if(this->ui->chengchang->text() != "")
        this->ui->chengchang->clear();

    if(this->ui->chengkun->text() != "")
        this->ui->chengkun->clear();

    if(this->ui->chengfu->text() != "")
        this->ui->chengfu->clear();

    if(this->ui->changkun->text() != "")
        this->ui->changkun->clear();

    if(this->ui->changguang->text() != "")
        this->ui->changguang->clear();

    if(this->ui->fuguang->text() != "")
        this->ui->fuguang->clear();


    this->ui->hashen->setVisible(false);
    this->ui->shenbei->setVisible(false);
    this->ui->shenlan->setVisible(false);
    this->ui->beinan->setVisible(false);
    this->ui->beiwu->setVisible(false);
    this->ui->beixi->setVisible(false);
    this->ui->lanxi->setVisible(false);
    this->ui->xiwu->setVisible(false);
    this->ui->xicheng->setVisible(false);
    this->ui->xikun->setVisible(false);
    this->ui->wuchang->setVisible(false);
    this->ui->wufu->setVisible(false);
    this->ui->nanwu->setVisible(false);
    this->ui->nanguang->setVisible(false);
    this->ui->fuguang->setVisible(false);
    this->ui->chengchang->setVisible(false);
    this->ui->chengkun->setVisible(false);
    this->ui->chengfu->setVisible(false);
    this->ui->changkun->setVisible(false);
    this->ui->changguang->setVisible(false);

    //获取状态，1城市，2两城市间的交通工具
    //根据状态点亮地图
    while(temp != NULL){

        citytemp = "";
        d = Search_Pas_State(temp->Seq, Timer_Time);

        if(markstate == 1){
            QString lvkexuhao = "    旅客序号:";
            QString nowtime = "时间:   ";
            QString nowstate = "   当前状态: ";
            filetime.open(QIODevice::Append);
            outt << nowtime << Timer_Time << lvkexuhao << temp->Seq << nowstate << d << endl;
            filetime.close();


            QString outrealtime = "";

            outrealtime.append(nowtime);
            outrealtime.append(QString::number(Timer_Time));
            outrealtime.append(lvkexuhao);
            outrealtime.append(QString::number(temp->Seq));
            outrealtime.append(nowstate);
            outrealtime.append(d);

            this->ui->RealTimeInfo->append(outrealtime);

            text = "旅客";
            text.append(QString::number(temp->Seq));

            if(d == "北京"){
                QFont ft;
                ft.setPointSize(9);
                this->ui->beijing->setFont(ft);
                this->ui->beijing->setStyleSheet("color:magenta;");
                this->ui->beijing->setText(text);
            }
            else if(d == "南京"){
                QFont ft;
                ft.setPointSize(9);
                this->ui->nanjing->setFont(ft);
                this->ui->nanjing->setStyleSheet("color:magenta;");
                this->ui->nanjing->setText(text);
            }
            else if(d == "武汉"){
                QFont ft;
                ft.setPointSize(9);
                this->ui->wuhan->setFont(ft);
                this->ui->wuhan->setStyleSheet("color:magenta;");
                this->ui->wuhan->setText(text);
            }
            else if(d == "长沙"){
                QFont ft;
                ft.setPointSize(9);
                this->ui->changsha->setFont(ft);
                this->ui->changsha->setStyleSheet("color:magenta;");
                this->ui->changsha->setText(text);
            }
            else if(d == "广州"){
                QFont ft;
                ft.setPointSize(9);
                this->ui->guangzhou->setFont(ft);
                this->ui->guangzhou->setStyleSheet("color:magenta;");
                this->ui->guangzhou->setText(text);
            }
            else if(d == "福州"){
                QFont ft;
                ft.setPointSize(9);
                this->ui->fuzhou->setFont(ft);
                this->ui->fuzhou->setStyleSheet("color:magenta;");
                this->ui->fuzhou->setText(text);
            }
            else if(d == "兰州"){
                QFont ft;
                ft.setPointSize(9);
                this->ui->lanzhou->setFont(ft);
                this->ui->lanzhou->setStyleSheet("color:magenta;");
                this->ui->lanzhou->setText(text);
            }
            else if(d == "西安"){
                QFont ft;
                ft.setPointSize(9);
                this->ui->xian->setFont(ft);
                this->ui->xian->setStyleSheet("color:magenta;");
                this->ui->xian->setText(text);
            }
            else if(d == "沈阳"){
                QFont ft;
                ft.setPointSize(9);
                this->ui->shenyang->setFont(ft);
                this->ui->shenyang->setStyleSheet("color:magenta;");
                this->ui->shenyang->setText(text);
            }
            else if(d == "哈尔滨"){
                QFont ft;
                ft.setPointSize(9);
                this->ui->haerbin->setFont(ft);
                this->ui->haerbin->setStyleSheet("color:magenta;");
                this->ui->haerbin->setText(text);
            }
            else if(d == "成都"){
                QFont ft;
                ft.setPointSize(9);
                this->ui->chengdu->setFont(ft);
                this->ui->chengdu->setStyleSheet("color:magenta;");
                this->ui->chengdu->setText(text);
            }
            else if(d == "昆明"){
                QFont ft;
                ft.setPointSize(9);
                this->ui->kunming->setFont(ft);
                this->ui->kunming->setStyleSheet("color:magenta;");
                this->ui->kunming->setText(text);
            }
        }
        else{
            if(vehi[markvehic_index] == 1){
                vehicle = "飞机";
            }
            else if(vehi[markvehic_index] == 2){
                vehicle = "汽车";
            }
            else if(vehi[markvehic_index] == 3){
                vehicle = "火车";
            }

            QString lvkexuhao = "    旅客序号:";
            QString nowtime = "时间:   ";
            QString nowstate = "   当前状态: ";
            QString zai = "在";
            QString shang = "上";
            QString he = "和";
            QString de = "之间的";
            filetime.open(QIODevice::Append);
            outt << nowtime << Timer_Time << lvkexuhao << temp->Seq << nowstate << zai << city[markajcity_index] << he << city[markajcity_index+1] << de << vehicle << shang << endl;
            filetime.close();

            //Out realtime information to Timelog

            QString outrealtime = "";

            outrealtime.append(nowtime);
            outrealtime.append(QString::number(Timer_Time));
            outrealtime.append(lvkexuhao);
            outrealtime.append(QString::number(temp->Seq));
            outrealtime.append(nowstate);
            outrealtime.append(zai);
            outrealtime.append(city[markajcity_index]);
            outrealtime.append(he);
            outrealtime.append(city[markajcity_index+1]);
            outrealtime.append(de);
            outrealtime.append(vehicle);
            outrealtime.append(shang);

            this->ui->RealTimeInfo->append(outrealtime);

            text = "";
            text.append(QString::number(temp->Seq));
            text.append(",");
            text.append(vehicle);

            //Display Realtime infor in the map

            if((city[markajcity_index] == "哈尔滨" && city[markajcity_index+1] == "沈阳") || (city[markajcity_index] == "沈阳" && city[markajcity_index+1] == "哈尔滨")){
                this->ui->hashen->setVisible(true);
                QFont ft;
                ft.setPointSize(9);
                this->ui->hashen->setFont(ft);
                this->ui->hashen->setStyleSheet("color:magenta;");
                this->ui->hashen->setText(text);
            }
            else if((city[markajcity_index] == "北京" && city[markajcity_index+1] == "沈阳") || (city[markajcity_index] == "沈阳" && city[markajcity_index+1] == "北京")){
                this->ui->shenbei->setVisible(true);
                QFont ft;
                ft.setPointSize(9);
                this->ui->shenbei->setFont(ft);
                this->ui->shenbei->setStyleSheet("color:magenta;");
                this->ui->shenbei->setText(text);
            }
            else if((city[markajcity_index] == "兰州" && city[markajcity_index+1] == "沈阳") || (city[markajcity_index] == "沈阳" && city[markajcity_index+1] == "兰州")){
                this->ui->shenlan->setVisible(true);
                QFont ft;
                ft.setPointSize(9);
                this->ui->shenlan->setFont(ft);
                this->ui->shenlan->setStyleSheet("color:magenta;");
                this->ui->shenlan->setText(text);
            }
            else if((city[markajcity_index] == "北京" && city[markajcity_index+1] == "南京") || (city[markajcity_index] == "南京" && city[markajcity_index+1] == "北京")){
                this->ui->beinan->setVisible(true);
                QFont ft;
                ft.setPointSize(9);
                this->ui->beinan->setFont(ft);
                this->ui->beinan->setStyleSheet("color:magenta;");
                this->ui->beinan->setText(text);
            }
            else if((city[markajcity_index] == "北京" && city[markajcity_index+1] == "武汉") || (city[markajcity_index] == "武汉" && city[markajcity_index+1] == "北京")){
                this->ui->beiwu->setVisible(true);
                QFont ft;
                ft.setPointSize(9);
                this->ui->beiwu->setFont(ft);
                this->ui->beiwu->setStyleSheet("color:magenta;");
                this->ui->beiwu->setText(text);
            }
            else if((city[markajcity_index] == "北京" && city[markajcity_index+1] == "西安") || (city[markajcity_index] == "西安" && city[markajcity_index+1] == "北京")){
                this->ui->beixi->setVisible(true);
                QFont ft;
                ft.setPointSize(9);
                this->ui->beixi->setFont(ft);
                this->ui->beixi->setStyleSheet("color:magenta;");
                this->ui->beixi->setText(text);
            }
            else if((city[markajcity_index] == "西安" && city[markajcity_index+1] == "兰州") || (city[markajcity_index] == "兰州" && city[markajcity_index+1] == "西安")){
                this->ui->lanxi->setVisible(true);
                QFont ft;
                ft.setPointSize(9);
                this->ui->lanxi->setFont(ft);
                this->ui->lanxi->setStyleSheet("color:magenta;");
                this->ui->lanxi->setText(text);
            }
            else if((city[markajcity_index] == "西安" && city[markajcity_index+1] == "武汉") || (city[markajcity_index] == "武汉" && city[markajcity_index+1] == "西安")){
                this->ui->xiwu->setVisible(true);
                QFont ft;
                ft.setPointSize(9);
                this->ui->xiwu->setFont(ft);
                this->ui->xiwu->setStyleSheet("color:magenta;");
                this->ui->xiwu->setText(text);
            }
            else if((city[markajcity_index] == "西安" && city[markajcity_index+1] == "成都") || (city[markajcity_index] == "成都" && city[markajcity_index+1] == "西安")){
                this->ui->xicheng->setVisible(true);
                QFont ft;
                ft.setPointSize(9);
                this->ui->xicheng->setFont(ft);
                this->ui->xicheng->setStyleSheet("color:magenta;");
                this->ui->xicheng->setText(text);
            }
            else if((city[markajcity_index] == "武汉" && city[markajcity_index+1] == "南京") || (city[markajcity_index] == "南京" && city[markajcity_index+1] == "武汉")){
                this->ui->nanwu->setVisible(true);
                QFont ft;
                ft.setPointSize(9);
                this->ui->nanwu->setFont(ft);
                this->ui->nanwu->setStyleSheet("color:magenta;");
                this->ui->nanwu->setText(text);
            }
            else if((city[markajcity_index] == "武汉" && city[markajcity_index+1] == "长沙") || (city[markajcity_index] == "长沙" && city[markajcity_index+1] == "武汉")){
                this->ui->wuchang->setVisible(true);
                QFont ft;
                ft.setPointSize(9);
                this->ui->wuchang->setFont(ft);
                this->ui->wuchang->setStyleSheet("color:magenta;");
                this->ui->wuchang->setText(text);
            }
            else if((city[markajcity_index] == "武汉" && city[markajcity_index+1] == "福州") || (city[markajcity_index] == "福州" && city[markajcity_index+1] == "武汉")){
                this->ui->wufu->setVisible(true);
                QFont ft;
                ft.setPointSize(9);
                this->ui->wufu->setFont(ft);
                this->ui->wufu->setStyleSheet("color:magenta;");
                this->ui->wufu->setText(text);
            }
            else if((city[markajcity_index] == "南京" && city[markajcity_index+1] == "广州") || (city[markajcity_index] == "广州" && city[markajcity_index+1] == "南京")){
                this->ui->nanguang->setVisible(true);
                QFont ft;
                ft.setPointSize(9);
                this->ui->nanguang->setFont(ft);
                this->ui->nanguang->setStyleSheet("color:magenta;");
                this->ui->nanguang->setText(text);
            }
            else if((city[markajcity_index] == "成都" && city[markajcity_index+1] == "长沙") || (city[markajcity_index] == "长沙" && city[markajcity_index+1] == "成都")){
                this->ui->chengchang->setVisible(true);
                QFont ft;
                ft.setPointSize(9);
                this->ui->chengchang->setFont(ft);
                this->ui->chengchang->setStyleSheet("color:magenta;");
                this->ui->chengchang->setText(text);
            }
            else if((city[markajcity_index] == "成都" && city[markajcity_index+1] == "福州") || (city[markajcity_index] == "福州" && city[markajcity_index+1] == "成都")){
                this->ui->chengfu->setVisible(true);
                QFont ft;
                ft.setPointSize(9);
                this->ui->chengfu->setFont(ft);
                this->ui->chengfu->setStyleSheet("color:magenta;");
                this->ui->chengfu->setText(text);
            }
            else if((city[markajcity_index] == "成都" && city[markajcity_index+1] == "昆明") || (city[markajcity_index] == "昆明" && city[markajcity_index+1] == "成都")){
                this->ui->chengkun->setVisible(true);
                QFont ft;
                ft.setPointSize(9);
                this->ui->chengkun->setFont(ft);
                this->ui->chengkun->setStyleSheet("color:magenta;");
                this->ui->chengkun->setText(text);
            }
            else if((city[markajcity_index] == "长沙" && city[markajcity_index+1] == "昆明") || (city[markajcity_index] == "昆明" && city[markajcity_index+1] == "长沙")){
                this->ui->changkun->setVisible(true);
                QFont ft;
                ft.setPointSize(9);
                this->ui->changkun->setFont(ft);
                this->ui->changkun->setStyleSheet("color:magenta;");
                this->ui->changkun->setText(text);
            }
            else if((city[markajcity_index] == "长沙" && city[markajcity_index+1] == "广州") || (city[markajcity_index] == "广州" && city[markajcity_index+1] == "长沙")){
                this->ui->changguang->setVisible(true);
                QFont ft;
                ft.setPointSize(9);
                this->ui->changguang->setFont(ft);
                this->ui->changguang->setStyleSheet("color:magenta;");
                this->ui->changguang->setText(text);
            }
            else if((city[markajcity_index] == "西安" && city[markajcity_index+1] == "昆明") || (city[markajcity_index] == "昆明" && city[markajcity_index+1] == "西安")){
                this->ui->xikun->setVisible(true);
                QFont ft;
                ft.setPointSize(9);
                this->ui->xikun->setFont(ft);
                this->ui->xikun->setStyleSheet("color:magenta;");
                this->ui->xikun->setText(text);
            }
            else if((city[markajcity_index] == "广州" && city[markajcity_index+1] == "福州") || (city[markajcity_index] == "福州" && city[markajcity_index+1] == "广州")){
                this->ui->fuguang->setVisible(true);
                QFont ft;
                ft.setPointSize(9);
                this->ui->fuguang->setFont(ft);
                this->ui->fuguang->setStyleSheet("color:magenta;");
                this->ui->fuguang->setText(text);
            }
        }

        if(d == temp->Dest_Place){
            if(d == "北京"){
                if(this->ui->beijing->text() != "")
                    this->ui->beijing->clear();
            }
            else if(d == "南京"){
                if(this->ui->nanjing->text() != "")
                    this->ui->nanjing->clear();

            }
            else if(d == "武汉"){
                if(this->ui->wuhan->text() != "")
                    this->ui->wuhan->clear();
            }
            else if(d == "长沙"){
                if(this->ui->changsha->text() != "")
                    this->ui->changsha->clear();
            }
            else if(d == "广州"){
                if(this->ui->guangzhou->text() != "")
                    this->ui->guangzhou->clear();
            }
            else if(d == "福州"){
                if(this->ui->fuzhou->text() != "")
                    this->ui->fuzhou->clear();
            }
            else if(d == "兰州"){
                if(this->ui->lanzhou->text() != "")
                    this->ui->lanzhou->clear();
            }
            else if(d == "西安"){
                if(this->ui->xian->text() != "")
                    this->ui->xian->clear();
            }
            else if(d == "沈阳"){
                if(this->ui->shenyang->text() != "")
                    this->ui->shenyang->clear();
            }
            else if(d == "哈尔滨"){
                if(this->ui->haerbin->text() != "")
                    this->ui->haerbin->clear();
            }
            else if(d == "成都"){
                if(this->ui->chengdu->text() != "")
                    this->ui->chengdu->clear();
            }
            else if(d == "昆明"){
                if(this->ui->kunming->text() != "")
                    this->ui->kunming->clear();
            }

            QString Done = "";
            Done.append(QString::number(temp->Seq));
            Done.append("号旅客已完成行程");
            this->ui->RealTimeInfo->append(Done);
            this->ui->RealTimeInfo->append("\n");
        }

        temp = temp->next;
    }

    delete temp;

    Timer_Time++;
}

//the function connected with click start signal
void MainWindow::on_Start_clicked()
{
    int timeout_time = 1000;

    if(this->ui->Radio_UpdateSpeed_5->isChecked())
        timeout_time = 5000;
    else if(this->ui->Radio_UpdateSpeed_10->isChecked())
        timeout_time = 10000;

    this->ptimer->start(timeout_time);          //设置超时间隔
    this->ui->Start->setEnabled(false);         //关闭开始键的使能
    this->ui->Stop->setEnabled(true);           //同时打开另外三个键的使能
    this->ui->Pause->setEnabled(true);
}

//the function connected with click pause signal
void MainWindow::on_Pause_clicked()
{
    static QTime pauseTime;  //暂停时间
    this->ptimer->stop();
    this->ui->Pause->setEnabled(false);
    this->ui->Start->setEnabled(true);
}

//the function connected with click search signal
void MainWindow::on_Search_clicked()
{
    QString Search_Pas_Seq = this->ui->SearchSeq->toPlainText();
    QString Search_Pas_Time = this->ui->SearchTime->toPlainText();
    int Seq = Search_Pas_Seq.toInt();
    int Time = Search_Pas_Time.toInt();
    int markintseq = 1;
    int markinttime = 1;

    if(Seq == 0 && Search_Pas_Seq != "0")
        markintseq = 0;
    if(Time == 0 && Search_Pas_Time != "0")
        markinttime = 0;

    if(this->ui->SearchSeq->toPlainText() == "" || this->ui->SearchTime->toPlainText() == "" || Seq > Num_Pas || markintseq == 0 || markinttime == 0){
        QString out = "请输入完整且正确的查询信息！";
        this->ui->RealTimeInfo->append(out);
    }
    else{
        filesearch.open(QIODevice::Append);

        //Display the information of on searching Passenger
        QString state = Search_Pas_State(Seq, Time);
        this->ui->PasState->setText(state);

        //Add infor to Searchlog
        QString statelog = "";
        statelog.append("旅客");
        statelog.append(QString::number(Seq));
        statelog.append("在");
        statelog.append(QString::number(Time));
        statelog.append("时刻");
        statelog.append("位于");
        statelog.append(state);
        outs << statelog << endl;
        filesearch.close();
    }

    //Clear
    if(this->ui->SearchSeq->toPlainText() != "")
        this->ui->SearchSeq->clear();
    if(this->ui->SearchTime->toPlainText() != "")
        this->ui->SearchTime->clear();

}

//Allocate travel plan to the new adding Passenger
//the function connected with AddPas signal
void MainWindow::on_AddPas_clicked()
{
    if(this->ui->RealTimeInfo->toPlainText() != "")
        this->ui->RealTimeInfo->clear();

    QString Str_Num_Pas = QString::number(Num_Pas);
    QString Depart = this->ui->AddDepart->toPlainText();
    QString Dest = this->ui->AddDest->toPlainText();
    QString Time_temp = this->ui->AddTimeReq->toPlainText();
    QString Risk_temp = this->ui->AddRiskReq->toPlainText();
    QString Price_temp = this->ui->AddPriceReq->toPlainText();

    if(Time_temp == "")
        Time_temp.append("0");

    if(Risk_temp == "")
        Risk_temp.append("0");

    if(Price_temp == "")
        Price_temp.append("0");

    int Time = Time_temp.toInt();
    int Risk = Risk_temp.toInt();
    int Price = Price_temp.toInt();
    int markrisk = 1, markprice = 1, marktime = 1;

    if(Time == 0 && Time_temp != "0")
        marktime = 0;

    if(Risk == 0 && Risk_temp != "0")
        markrisk = 0;

    if(Price == 0 && Price_temp != "0")
        markprice = 0;

    if(Depart == Dest){
        QString out = "";
        out.append("出发地与目的地不可相同");

        this->ui->RealTimeInfo->append(out);

        if(this->ui->AddDepart->toPlainText() != "")
            this->ui->AddDepart->clear();

        if(this->ui->AddDest->toPlainText() != "")
            this->ui->AddDest->clear();

        if(this->ui->AddTimeReq->toPlainText() != "")
            this->ui->AddTimeReq->clear();

        if(this->ui->AddRiskReq->toPlainText() != "")
            this->ui->AddRiskReq->clear();

        if(this->ui->AddPriceReq->toPlainText() != "")
            this->ui->AddPriceReq->clear();
    }
    else if(marktime == 0 || markrisk == 0 || markprice == 0 || this->ui->AddDepart->toPlainText() == "" || this->ui->AddDest->toPlainText() == "" || Time < 0 || Risk < 0 || Price < 0){
        QString out = "";
        out.append("请输入完整且正确的旅客需求！");

        this->ui->RealTimeInfo->append(out);

        if(this->ui->AddDepart->toPlainText() != "")
            this->ui->AddDepart->clear();

        if(this->ui->AddDest->toPlainText() != "")
            this->ui->AddDest->clear();

        if(this->ui->AddTimeReq->toPlainText() != "")
            this->ui->AddTimeReq->clear();

        if(this->ui->AddRiskReq->toPlainText() != "")
            this->ui->AddRiskReq->clear();

        if(this->ui->AddPriceReq->toPlainText() != "")
            this->ui->AddPriceReq->clear();
    }
    else{
        QString st = "";
        QString en = "";
        QString out = "";
        out.append("请输入完整且正确的旅客需求！");

        st.append(this->ui->AddDepart->toPlainText());
        en.append(this->ui->AddDest->toPlainText());

        if((st == "北京" || st == "昆明" ||  st == "长沙" || st == "武汉" || st == "成都" || st == "哈尔滨" || st == "沈阳" || st == "西安" || st == "兰州" || st == "福州" || st == "广州" || st == "南京") && (en == "北京" || en == "昆明" ||  en == "长沙" || en == "武汉" || en == "成都" || en == "哈尔滨" || en == "沈阳" || en == "西安" || en == "兰州" || en == "福州" || en == "广州" || en == "南京")){
            if(Num_Pas != 0){
                this->ui->SeqAllocate->clear();
                this->ui->AddPlan->clear();
            }

            Num_Pas++;

            QString Str_Num_Pas = QString::number(Num_Pas);
            QString Depart = this->ui->AddDepart->toPlainText();
            QString Dest = this->ui->AddDest->toPlainText();
            QString Time_temp = this->ui->AddTimeReq->toPlainText();
            QString Risk_temp = this->ui->AddRiskReq->toPlainText();
            QString Price_temp = this->ui->AddPriceReq->toPlainText();
            int Time = Time_temp.toInt();
            int Risk = Risk_temp.toInt();
            int Price = Price_temp.toInt();

            this->ui->AddDepart->clear();
            this->ui->AddDest->clear();
            this->ui->AddTimeReq->clear();
            this->ui->AddRiskReq->clear();
            this->ui->AddPriceReq->clear();

            int plantype = 0;
            if(this->ui->Radio_None->isChecked())
                plantype = 0;
            else if(this->ui->Radio_Time->isChecked())
                plantype = 1;
            else if(this->ui->Radio_Risk->isChecked())
                plantype = 0;
            else if(this->ui->Radio_Price->isChecked())
                plantype = 2;
            else
                plantype = 0;

            //main algorithm to allocate route
            Add_Pas(Num_Pas, Time, Risk, Price, Depart, Dest, plantype);

            QString satis = "";

            this->ui->SeqAllocate->setText(Str_Num_Pas);
            this->ui->AddPlan->setText(SetAddText);

            this->ui->RealTimeInfo->append(SetInfo);
            this->ui->RealTimeInfo->append(SetAddText);
            this->ui->RealTimeInfo->append(Setpara);


            filepas.open(QIODevice::Append);
            if(Satisfied == "no"){
                satis.append("无满足需求的路径，分配最小风险旅行策略路径给旅客");
                satis.append(QString::number(Num_Pas));
                this->ui->RealTimeInfo->append(satis);
                this->ui->RealTimeInfo->append("\n");
                outp << satis << endl;
            }
            outp << SetInfo << endl;
            outp << SetAddText << endl;
            outp << Setpara << endl;
            outp << endl;
            filepas.close();
        }
        else{
            this->ui->RealTimeInfo->append(out);
            if(this->ui->AddDepart->toPlainText() != "")
                this->ui->AddDepart->clear();

            if(this->ui->AddDest->toPlainText() != "")
                this->ui->AddDest->clear();

            if(this->ui->AddTimeReq->toPlainText() != "")
                this->ui->AddTimeReq->clear();

            if(this->ui->AddRiskReq->toPlainText() != "")
                this->ui->AddRiskReq->clear();

            if(this->ui->AddPriceReq->toPlainText() != "")
                this->ui->AddPriceReq->clear();
        }


    }

}

//Free the data structure and kill the window
void MainWindow::on_Stop_clicked()
{
    Free_Pas(Pas_ptr);
    this->close();
}
#endif
