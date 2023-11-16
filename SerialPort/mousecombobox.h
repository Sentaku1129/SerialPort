#ifndef MOUSECOMBOBOX_H
#define MOUSECOMBOBOX_H

#include <QWidget>
#include <QComboBox>
#include <QMouseEvent>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>

class mousecombobox : public QComboBox
{
    Q_OBJECT
public:
    mousecombobox(QWidget *parent = 0);

    //重写鼠标点击事件
    void mousePressEvent(QMouseEvent *event);

private:
    void scanActivePort();
};

#endif // MOUSECOMBOBOX_H
