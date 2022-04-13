#include "chat.h"
#include "ui_chat.h"


void Chat::revinf(QString str,QTcpSocket* sock,Chat *w){
    if(this==w){
        QString buf(str);
        QStringList slist = buf.split("|");
        sendid = slist.at(0);
        recvid = slist.at(1);
        recvname = slist.at(2);
        setWindowTitle("chatting with "+ recvname);
        soc=sock;
        talker = recvid;
    }
    else
        return;
}





Chat::Chat(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Chat)
{
    ui->setupUi(this);
//    sock.connectToHost("192.168.47.1",8887);
//    connect(&sock,SIGNAL(connected()),this,SLOT(handConnected()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(clean()));
    connect(this,SIGNAL(destroyed()),this,SLOT(closeEvent()));
}

Chat::~Chat()
{
    delete ui;
}

void Chat::closeEvent(QCloseEvent *event)
{
    QString sendBuf="d|"+recvid+"|"+sendid;
    soc->write(sendBuf.toUtf8());
}

void Chat::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}



void Chat::handData(QString str2){

    //qDebug()<<buf;
    QStringList slist = str2.split("|");
    QString time = slist.at(1);
    QStringList timeslist = time.split(":");
    if(talker==slist.at(3)){
        ui->textBrowser->insertHtml(time+"&nbsp;");
        ui->textBrowser->insertHtml(slist.at(3)+":<br>");
        ui->textBrowser->insertHtml(slist.at(2)+"<br>");
    }


}



void Chat::on_pushButton_clicked()//发送
{
     text = ui->textEdit->toPlainText();

    if(text.isEmpty())
    {
        QMessageBox::warning(this, QString::fromUtf8("提示"), QString::fromUtf8("无发送内容"));
        return;
    }

    else
    {
    QDateTime dateTime = QDateTime::currentDateTime();
    QString sendtext="5|";
    sendtext += dateTime.toString("yyyy-MM-dd hh:mm:ss");
    sendtext +="|";
    sendtext +=text;
    sendtext +="|";
    sendtext +=sendid;
    sendtext +="|";
    sendtext +=recvid;
    //qDebug()<<sendtext;
    ui->textBrowser->insertHtml(dateTime.toString("yyyy-MM-dd hh:mm:ss")+"&nbsp;");
    ui->textBrowser->insertHtml(sendid+":<br>");
    ui->textBrowser->insertHtml(text+"<br>");
    soc->write(sendtext.toUtf8());
    //connect(this,SIGNAL(sendmsg(QString)),mWind,SLOT(recivemsg(QString)));
    //emit sendmsg(sendtext);
    }
}


void Chat::on_pushButton_2_clicked()//关闭
{
   this->close();
}

void Chat::on_pushButton_3_clicked()
{
 QString signal = "6|";
 signal +=sendid;
 signal +="|";
 signal +=recvid;
 soc->write(signal.toUtf8());
 //connect(this,SIGNAL(sendmsg(QString)),mWind,SLOT(recivemsg(QString)));
 //emit sendmsg(signal);

 //connect(this,SIGNAL(account(QString)),record,SLOT(dsb(QString)));
 //emit account();
 record * m= new record(this);
 m->show();
 connect(this,SIGNAL(account(QString)),m,SLOT(dsb(QString)));
}
void Chat::recivrec(QString str){
    emit account(str);
}

void Chat::clean()
{
    ui->textEdit->clear();
}
