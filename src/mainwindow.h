#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QTime>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool eventFilter(QObject *watched, QEvent  *event);
    void paint_hashen();
    void paint_shenbei();
    void paint_beinan();
    void paint_beiwu();
    void paint_beixi();
    void paint_lanxi();
    void paint_shenlan();
    void paint_xiwu();
    void paint_nanwu();
    void paint_xicheng();
    void paint_xikun();
    void paint_chengkun();
    void paint_chengchang();
    void paint_wuchang();
    void paint_wufu();
    void paint_changkun();
    void paint_changguang();
    void paint_fuguang();
    void paint_chengfu();
    void paint_nanguang();

private slots:

    void on_AddPas_clicked();

    void on_Start_clicked();

    void on_Pause_clicked();

    void on_Stop_clicked();

    void Update_Num();

    void on_Search_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *ptimer;     //定时器对象指针
    QTime baseTime;     //基准时间
    QString showStr;    //要在LCD中显示的字符串
};

#endif // MAINWINDOW_H
