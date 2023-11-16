#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSerialPort>
#include <QLabel>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QTimer>
#include <QMetaEnum>
#include <QRegularExpression>
#include <QValidator>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_choice_pushButton_clicked();

    void on_clear_accept_pushButton_clicked();

    void on_clear_send_pushButton_clicked();

    void serialPortRead_Slot();

    void on_send_pushButton_clicked();

    void Timer_Send_Slot();

    void Serial_Error_Slot(QSerialPort::SerialPortError error);

private:
    Ui::Widget *ui;
    //接收字节数,发送字节数
    long recvNum, sendNum;
    QLabel *lblSendNum;
    QLabel *lblRecvNum;
    QSerialPort *mySerialPort;
    QTimer *sendTimer;
};
#endif // WIDGET_H
