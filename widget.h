#ifndef WIDGET_H
#define WIDGET_H
#include <QtMultimedia/QSound>
#include <QWidget>
#include "AutoResize.h"
#include<QTimer>
namespace Ui {
class Widget;
}
class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);

    ~Widget();
public slots:

 // void play();
 // void stop();
private slots:
  void on_pushButton_clicked();
  void on_pushButton_2_clicked();
  void on_pushButton_3_clicked();
  void on_pushButton_4_clicked();
private:
    Ui::Widget *ui;
    AutoResize *m_autoResizeHandler;
    void resizeEvent(QResizeEvent * event);
  QSound *Player;
  int m_a;
    
};
#endif // WIDGET_H
