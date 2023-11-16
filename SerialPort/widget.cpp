#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("../img/OIG.jpg"));
    //初始化接收字节数与发送字节数
    recvNum = 0;
    sendNum = 0;

    // 状态栏
//    QStatusBar *sBar = statusBar();
    // 状态栏的收、发计数标签
    lblSendNum = new QLabel(this);
    lblRecvNum = new QLabel(this);

    //初始化发送定时器计时栏
    ui->time_lineEdit->setText("1000");
    //默认定时器发送关闭
    ui->time_checkBox->setChecked(false);

    //配置hex接收与发送，默认关闭
    ui->hex_accept_checkBox->setChecked(false);
    ui->hex_send_checkBox->setChecked(false);

    //配置波特率选项
    QStringList BaudRate;
    BaudRate << "9600" << "38400" << "115200";
    ui->BaudRate_comboBox->addItems(BaudRate);
    ui->BaudRate_comboBox->setCurrentIndex(2);

    //配置停止位
    QStringList StopBit;
    StopBit << "1" << "1.5" << "2";
    ui->Stop_comboBox->addItems(StopBit);
    ui->Stop_comboBox->setCurrentIndex(0);

    //配置数据位
    QStringList DataBit;
    DataBit << "5" << "6" << "7" << "8";
    ui->Data_comboBox->addItems(DataBit);
    ui->Data_comboBox->setCurrentIndex(3);

    //配置奇偶校验
    QStringList ParityCheck;
    ParityCheck << "无" << "奇校验" << "偶校验";
    ui->Check_comboBox->addItems(ParityCheck);

    //配置接收文本框，禁止编辑
    ui->accept_textEdit->setReadOnly(true);

    //定时器初始化
    sendTimer = new QTimer;
    sendTimer->setInterval(1000);
    QRegularExpression exp("[0-9\\.]+$");
    QValidator *validator = new QRegularExpressionValidator(exp);
    ui->time_lineEdit->setValidator(validator);
    connect(sendTimer, &QTimer::timeout, this, &Widget::Timer_Send_Slot);

    // 初始化串口
    mySerialPort = new QSerialPort(this);
    //串口接收槽函数关联
    connect(mySerialPort, &QSerialPort::readyRead , this, &Widget::serialPortRead_Slot);
    connect(mySerialPort, &QSerialPort::errorOccurred , this, &Widget::Serial_Error_Slot);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_choice_pushButton_clicked()
{
    QSerialPort::BaudRate baudRate;
    QSerialPort::DataBits dataBits;
    QSerialPort::StopBits stopBits;
    QSerialPort::Parity   checkBits;

    if(ui->BaudRate_comboBox->currentText() == "9600")
        baudRate = QSerialPort::Baud9600;
    else if(ui->BaudRate_comboBox->currentText() == "9600")
        baudRate = QSerialPort::Baud38400;
    else if(ui->BaudRate_comboBox->currentText() == "115200")
        baudRate = QSerialPort::Baud115200;
    else
    {
        QMessageBox::warning(this, "连接错误", "波特率有误");
        return;
    }

    if(ui->Stop_comboBox->currentText() == "1")
        stopBits = QSerialPort::OneStop;
    else if(ui->Stop_comboBox->currentText() == "1.5")
        stopBits = QSerialPort::OneAndHalfStop;
    else if(ui->Stop_comboBox->currentText() == "2")
        stopBits = QSerialPort::TwoStop;
    else
    {
        QMessageBox::warning(this, "连接错误", "停止位有误");
        return;
    }

    if(ui->Data_comboBox->currentText() == "5")
        dataBits = QSerialPort::Data5;
    else if(ui->Data_comboBox->currentText() == "6")
        dataBits = QSerialPort::Data6;
    else if(ui->Data_comboBox->currentText() == "7")
        dataBits = QSerialPort::Data7;
    else if(ui->Data_comboBox->currentText() == "8")
        dataBits = QSerialPort::Data8;
    else
    {
        QMessageBox::warning(this, "连接错误", "数据位有误");
        return;
    }

    if(ui->Check_comboBox->currentText() == "无")
        checkBits = QSerialPort::NoParity;
    else if(ui->Check_comboBox->currentText() == "奇校验")
        checkBits = QSerialPort::OddParity;
    else if(ui->Check_comboBox->currentText() == "偶校验")
        checkBits = QSerialPort::EvenParity;
    else
    {
        QMessageBox::warning(this, "连接错误", "校验位有误");
        return;
    }

    mySerialPort->setBaudRate(baudRate);
    mySerialPort->setStopBits(stopBits);
    mySerialPort->setDataBits(dataBits);
    mySerialPort->setParity(checkBits);

    // 匹配带有串口设备信息的文本
    QString spTxt = ui->Port_comboBox->currentText();
    spTxt = spTxt.section(':', 0, 0);//spTxt.mid(0, spTxt.indexOf(":"));
    qDebug() << spTxt;
    mySerialPort->setPortName(spTxt);

    if(ui->choice_pushButton->text() == "打开串口")
    {
        if(mySerialPort->open(QIODevice::ReadWrite) == true)
        {
            // 让端口号下拉框不可选，避免误操作（选择功能不可用，控件背景为灰色）
            ui->Port_comboBox->setEnabled(false);
            ui->BaudRate_comboBox->setEnabled(false);
            ui->Stop_comboBox->setEnabled(false);
            ui->Data_comboBox->setEnabled(false);
            ui->Check_comboBox->setEnabled(false);
        }
        else
        {
            QMessageBox::warning(this, "错误提示", "串口打开失败！！！\r\n该串口可能被占用\r\n请选择正确的串口");
            return;
        }
        ui->choice_pushButton->setText("关闭串口");
    }

    else
    {
        mySerialPort->close();
        ui->Port_comboBox->setEnabled(true);
        ui->BaudRate_comboBox->setEnabled(true);
        ui->Stop_comboBox->setEnabled(true);
        ui->Data_comboBox->setEnabled(true);
        ui->Check_comboBox->setEnabled(true);
        ui->choice_pushButton->setText("打开串口");
    }
}


void Widget::serialPortRead_Slot()
{

    QByteArray recvbuf;
    recvbuf = mySerialPort->readAll();

    //接收字节数
    recvNum += recvbuf.size();

    if(ui->hex_accept_checkBox->checkState() == Qt::Unchecked)
    {
        ui->accept_textEdit->moveCursor(QTextCursor::End);
        ui->accept_textEdit->insertPlainText(recvbuf);
    }
    else
    {
        // 16进制显示，并转换为大写
        QString str1 = recvbuf.toHex().toUpper();//.data();
        // 添加空格
        QString str2;
        for(int i = 0; i<str1.length(); i+=2)
        {
            str2 += str1.mid(i, 2);
            str2 += " ";
        }
        ui->accept_textEdit->insertPlainText(str2);
    }
}

void Widget::on_clear_accept_pushButton_clicked()
{
    ui->accept_textEdit->clear();
}

void Widget::on_clear_send_pushButton_clicked()
{
    ui->send_textEdit->clear();
}


void Widget::on_send_pushButton_clicked()
{
    if(!mySerialPort->isOpen())
    {
        QMessageBox::warning(this, "错误提示", "请连接串口再来尝试");
        return;
    }
    // 获取文本字符串
    QString sendbuf = ui->send_textEdit->toPlainText();

    if(ui->time_checkBox->checkState() == Qt::Checked && !sendTimer->isActive())
    {
        Widget::Timer_Send_Slot();
    }

    // 获取多选框状态，未选为0，选中为2
    // 为0时，多选框未被勾选，将先前的发送区的16进制字符串转换为asc2字符串

    if(ui->hex_send_checkBox->checkState() == Qt::Unchecked)
    {
        ui->accept_textEdit->insertPlainText(sendbuf);
    }
    else
    {

        QByteArray str1 = sendbuf.toUtf8().toHex().toUpper();
        // 添加空格
        QByteArray str2;
        for(int i = 0; i<str1.length (); i+=2)
        {
            str2 += str1.mid (i,2);
            str2 += " ";
        }
        // 更新发送栏
        // ui->send_textEdit->setText(str2);
        // 移动光标到文本结尾
        ui->accept_textEdit->moveCursor(QTextCursor::End);
        // 文本控件清屏，显示新文本
        ui->accept_textEdit->insertPlainText(str2);
    }
    mySerialPort->write(sendbuf.toUtf8());
}

void Widget::Timer_Send_Slot()
{
    if(ui->time_checkBox->checkState() == Qt::Unchecked)
    {
        sendTimer->stop();
        ui->send_textEdit->setEnabled(true);
        ui->time_lineEdit->setEnabled(true);
        return;
    }
    ui->send_textEdit->setEnabled(false);
    sendTimer->setInterval(ui->time_lineEdit->text().toInt());
    ui->time_lineEdit->setEnabled(false);
    sendTimer->start();
    Widget::on_send_pushButton_clicked();
}

void Widget::Serial_Error_Slot(QSerialPort::SerialPortError error)
{
    // qDebug()  << qPrintable(QLatin1String(QMetaEnum::fromType<QSerialPort::SerialPortError>().valueToKey(error)));
    if(error ==  QSerialPort::PermissionError && mySerialPort->isOpen())
    {
        mySerialPort->close();
        ui->Port_comboBox->setEnabled(true);
        ui->BaudRate_comboBox->setEnabled(true);
        ui->Stop_comboBox->setEnabled(true);
        ui->Data_comboBox->setEnabled(true);
        ui->Check_comboBox->setEnabled(true);
        ui->choice_pushButton->setText("打开串口");
        QMessageBox::warning(this, "错误提示", "串口断开连接");
    }

}

