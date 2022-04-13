#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    //设置密码隐藏
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    this->setFixedSize(400,300);;
    QPixmap myPix(":/img/login.jpg");
    ui->label_4->setStyleSheet("QLabel {background-color: transparent;}");
    ui->label_3->stackUnder(ui->label_4);
    ui->label_3->setPixmap(myPix);
    ui->label_3->setScaledContents(true);
    setWindowTitle(QString::fromUtf8("登录"));
    sock.connectToHost("192.168.170.128",8888);
    connect(&sock, SIGNAL(connected()), this,SLOT(handConnect()));
}

login::~login()
{
    delete ui;
}

void login::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void login::on_pushButton_2_clicked()//登录按钮
{
    uName = ui->lineEdit->text();
    pWord = ui->lineEdit_2->text();
    if(uName.isEmpty())
    {
        QMessageBox::warning(this,QString::fromUtf8("警告"), QString::fromUtf8("用户名不能为空"));
        return;
    }
    if(pWord.isEmpty())
    {
        QMessageBox::warning(this, QString::fromUtf8("警告"),QString::fromUtf8("密码不能为空"));
        return;
    }
    QString sendBuf = "2|";
    sendBuf += uName;
    sendBuf += "|";
    sendBuf += pWord;
    qDebug()<<sendBuf;
    //sendBuf.toUtf8();
    sock.write(sendBuf.toUtf8());
}

void login::on_pushButton_clicked()//注册按钮
{
    ZhuCe *c = new ZhuCe(this);
    c->show();
    sock.disconnectFromHost();//断开连接
    this->hide();
}

void login::handConnect()
{
    ui->pushButton->setEnabled(true);
    connect(&sock,SIGNAL(readyRead()),this, SLOT(handData()));
}

void login::handData()
{

    QByteArray recvBuf = sock.readAll();
    QString buf ;
    buf = QTextCodec::codecForName("UTF-8")->toUnicode(recvBuf);

    //buf.toUtf8();
    QStringList slist = buf.split("|");
    if (slist.at(0)=="1")
    {
        QMessageBox::information(this,QString::fromUtf8("提示"),slist.at(1));
        MainWindow *mWind = new MainWindow(this);
        mWind->show();
        connect(this,SIGNAL(account(QString)),mWind,SLOT(revid(QString)));
        emit account(slist.at(2)+"|"+uName);//发送用户名
        this->hide();
        sock.disconnectFromHost();//断开连接
        return;
    }
    else
    {
        QMessageBox::information(this,QString::fromUtf8("警告"),slist.at(1));
    }
}

