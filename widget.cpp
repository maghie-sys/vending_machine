#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::dontPhase(){
    ui->pbCoke->setEnabled(false);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbWater->setEnabled(false);
}

void Widget::changeMoney(int n)
{
    money+=n;
    ui->lcdNumber->display(money);
}

void Widget::reSet(){
    dontPhase();
    ui->lcdNumber->display(0);
    ui->lcdNumber10->display(0);
    ui->lcdNumber50->display(0);
    ui->lcdNumber100->display(0);
    ui->lcdNumber500->display(0);
    money=0;
}

void Widget::checkMoney(int n)
{
    dontPhase();
    if (n <0){
        QMessageBox msg;
        dontPhase();
        msg.information(nullptr, "error", "error");
        reSet();
    }
    else if (n >= 1200){
        ui->pbCoke->setEnabled(true);
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbWater->setEnabled(true);
    }
    else if (n<1200 && n >= 950){
        ui->pbCoke->setEnabled(false);
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbWater->setEnabled(true);
    }
    else if (n < 950 && n >= 600){
        ui->pbCoke->setEnabled(false);
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(false);
        ui->pbWater->setEnabled(true);
    }
    else if (n < 600 && n >=450){
        ui->pbCoke->setEnabled(false);
        ui->pbCoffee->setEnabled(false);
        ui->pbTea->setEnabled(false);
        ui->pbWater->setEnabled(true);
    }
}

void Widget::on_pbReturn_clicked()
{
    checkMoney(money);

    ui->lcdNumber->display(0);

    int a,b,c,d;
    d = money /500;
    c = (money-500*d) /100;
    b = ((money-500*d)-100*c)/50;
    a = (((money-500*d)-100*c)-b*50) /10;

    ui->lcdNumber10->display(a);
    ui->lcdNumber50->display(b);
    ui->lcdNumber100->display(c);
    ui->lcdNumber500->display(d);

    dontPhase();
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
    checkMoney(money);

}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
    checkMoney(money);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
    checkMoney(money);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
    checkMoney(money);
}

void Widget::on_pbWater_clicked()
{
    changeMoney(-450);
    checkMoney(money);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-600);
    checkMoney(money);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-950);
    checkMoney(money);
}
void Widget::on_pbCoke_clicked()
{
    changeMoney(-1200);
    checkMoney(money);
}

void Widget::on_pbreSet_clicked()
{
    reSet();
}
