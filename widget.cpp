#include "widget.h"
#include "ui_widget.h"
#include <QString>
#include <qapplication.h>
#include <qmessagebox.h>
#include <qmenubar.h>
#include<QSound>
#include<unistd.h>
#include<QTime>
int a,b,c,state=1;
void delay500ms()
{
    QTime dieTime= QTime::currentTime().addMSecs(500);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void delay1000ms()
{
    QTime dieTime= QTime::currentTime().addMSecs(1000);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
void delay2000ms()
{
    QTime dieTime= QTime::currentTime().addMSecs(2000);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
void satuan (long a)
{
if (a==1) {
    QSound::play(":/satu.wav");
delay500ms();
}
else if (a==2) {

    QSound::play(":/dua.wav");
delay500ms();
  }
else if (a==3) {
    
    QSound::play(":/tiga.wav");
delay500ms();
}
else if (a==4) {
    QSound::play(":/empat.wav");
delay500ms();
}
else if (a==5) {
    QSound::play(":/lima.wav");
delay500ms();
}
else if (a==6) {
    QSound::play(":/enam.wav");
delay500ms();
}
else if (a==7) {
    QSound::play(":/tujuh.wav");
delay500ms();
}
else if (a==8) {
    QSound::play(":/delapan.wav");
delay500ms();
}
else if (a==9) {
    QSound::play(":/sembilan.wav");
delay500ms();
}
else if (a==10) {
    QSound::play(":/sepuluh.wav");
delay500ms();
}
else if (a==11) {
    QSound::play(":/sebelas.wav");
delay500ms();
}
}
void terbilang (long b)
{
  

if (b<=11) {
satuan(b);
}
else if ((b>11) && (b<=19)) {
terbilang(b%10);
QSound::play(":/belas.wav");
delay500ms();
}
else if ((b>=20)&&(b<=99)) {
terbilang(b/10);
QSound::play(":/puluh.wav");
delay500ms();
terbilang(b%10);
}
delay500ms();

}



Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    

    m_autoResizeHandler=new AutoResize(this,this->rect().width(),this->rect().height());
    m_autoResizeHandler->setAutoResizeFlag(
            AutoResize::INCLUDE_BUTTON|AutoResize::INCLUDE_COMBOBOX|
            AutoResize::INCLUDE_EDITOR|AutoResize::INCLUDE_LABEL
            );
 //   add widget* manualy;
    //m_autoResizeHandler->addOtherItem(ui->frame);
   // m_autoResizeHandler->pushAllResizeItem();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::resizeEvent(QResizeEvent *event)
{
    m_autoResizeHandler->doAutoResize();
}
void Widget::on_pushButton_clicked(){
  if(state==1){
      state=0;

  c=c+1;
b=c/10;
b=b%10;
a=c%10;
  ui->label_2->setText(QString::number(a));
  
  ui->label_3->setText(QString::number(b));
  ui->label_6->setText(tr("1"));
  QSound::play(":/Nomor_Antrian.wav");
delay2000ms();
  terbilang(c);
  QSound::play(":/di_loket.wav");
  delay1000ms();
    QSound::play(":/satu.wav");
     delay500ms();
     state=1;
     }

    }
void Widget::on_pushButton_2_clicked(){
  if(state==1){
      state=0;
  c=c+1;
  b=c/10;
  b=b%10;
  a=c%10;  
    ui->label_2->setText(QString::number(a));
    
    ui->label_3->setText(QString::number(b));
     ui->label_6->setText(tr("2"));
     QSound::play(":/Nomor_Antrian.wav");
   delay2000ms();
     terbilang(c);
     QSound::play(":/di_loket.wav");
     delay1000ms();
         QSound::play(":/dua.wav");
    state=1;
    }

}

void Widget::on_pushButton_3_clicked(){
  if(state==1){
      state=0;
  
  c=c+1;
  b=c/10;
  b=b%10;
  a=c%10;

    ui->label_2->setText(QString::number(a));
    
    ui->label_3->setText(QString::number(b));

    
    ui->label_6->setText(tr("3"));
    QSound::play(":/Nomor_Antrian.wav");
  delay2000ms();
terbilang(c);
QSound::play(":/di_loket.wav");
delay1000ms();
    QSound::play(":/tiga.wav");

    state=1;
    }

    }
  

void Widget::on_pushButton_4_clicked(){
  c=0;
  b=c/10;
  b=b%10;
  a=c%10;
  ui->label_2->setText(QString::number(a));
  ui->label_3->setText(QString::number(b));
}
