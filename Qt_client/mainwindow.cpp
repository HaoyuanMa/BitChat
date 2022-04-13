#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "frilist.h"

void MainWindow::revid(QString str){
    QString buf(str);
    QStringList slist = buf.split("|");
    id = slist.at(1);
    db->sender=id;
    db->soc=&sock;
    ui->label->setText(slist.at(0));
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setMaximumSize(238,525);
    this->setMinimumSize(238,525);
    //设置窗体title
    db=new manage(this);
    setWindowTitle("BitChat");
    FriList *fr = new FriList(this);
    ui->verticalLayout->addWidget(fr);
    QPixmap myPix(":/img/timg.jpg");
    ui->label_4->setPixmap(myPix);
    ui->label_4->setScaledContents(true);
    sock.connectToHost("192.168.170.128",8888);
    connect(&sock, SIGNAL(connected()), this,SLOT(handConnect()));
    connect(this,SIGNAL(destroyed()),this,SLOT(closeEvent()));
    connect(this,SIGNAL(smsg(QString)),this,SLOT(searchresult(QString)));
    connect(this,SIGNAL(mmsg(QString)),db,SLOT(recivemsg(QString)));
    connect(this,SIGNAL(dmsg(QString)),db,SLOT(deletewin(QString)));
    connect(this,SIGNAL(rmsg(QString)),this,SLOT(refresult(QString)));
    connect(this,SIGNAL(recmsg(QString)),db,SLOT(reciverec(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QString sendBuf="0|"+id;
    sock.write(sendBuf.toUtf8());
}

void MainWindow::changeEvent(QEvent *e)
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

void MainWindow::handConnect()
{   QString sendBuf="9|"+id;
    sock.write(sendBuf.toUtf8());
    connect(&sock,SIGNAL(readyRead()),this, SLOT(solvebuf()));
}

void MainWindow::solvebuf()
{
    QByteArray recvBuf = sock.readAll();
    QString buf ;
    buf = QTextCodec::codecForName("UTF-8")->toUnicode(recvBuf);

    QStringList slist = buf.split("|");
    if(slist.at(0)=="0"||slist.at(0)=="1"){
        //connect(this,SIGNAL(smsg(QString)),this,SLOT(searchresult(QString)));
        emit smsg(buf);
    }
    else if(slist.at(0)=="5"){
        //connect(this,SIGNAL(mmsg(QString)),db,SLOT(recivemsg(QString)));
        emit mmsg(buf);
    }
    else if(slist.at(0)=="6"){
        //connect(this,SIGNAL(recmsg(QString)),db,SLOT(reciverec(QString)));
        emit recmsg(buf);
    }
    else if(slist.at(0)=="d"){
        //connect(this,SIGNAL(dmsg(QString)),db,SLOT(deletewin(QString)));
        emit dmsg(buf);
    }
    else{
        //connect(this,SIGNAL(rmsg(QString)),this,SLOT(refresult(QString)));
        emit rmsg(buf);
    }
}

void MainWindow::on_pushButton_2_clicked()
{   //点击搜索好友
    QString searchnum = ui->lineEdit->text();
    if(searchnum.isEmpty()){
        return;
    }
    QString sendBuf = "4|";
    sendBuf += id;
    sendBuf +='|';
    sendBuf += searchnum;
    qDebug()<<sendBuf;
    //sendBuf.toUtf8();
    sock.write(sendBuf.toUtf8());
    ui->lineEdit->clear();
}

void MainWindow::searchresult(QString str)//返回搜索结果
{

    QStringList slist = str.split("|");
    if (slist.at(0)=="1")
    {
        QMessageBox::information(this,QString::fromUtf8("提示"),slist.at(1));//添加成功
        return;
    }
    else if(slist.at(0)=="0")
    {
        QMessageBox::information(this,QString::fromUtf8("警告"),slist.at(1));//未找到联系人
        return;
    }

}



//void MainWindow::on_pushButton_clicked()
//{
    //刷新好友列表
 //   QString sendBuf = "8|";
 //   sendBuf += id;
 //   qDebug()<<sendBuf;
    //sendBuf.toUtf8();
   // sock.write(sendBuf.toUtf8());
//}
void MainWindow::refresult(QString str)
{   QLayoutItem *child;
    while((child=this->ui->verticalLayout->takeAt(0))) {
        delete child;
    }
    QStringList slist = str.split("|");
    int n = slist.length();
    FriList *fr = new FriList(this);
    for(int i = 0;i <= (n-3);i += 3){
        if(slist.at(i+2)=="1")//在线
        {
            fr->addOnline(slist.at(i+1),slist.at(i),id,&sock,db);
        }
        else if(slist.at(i+2)=="0")
        {
            fr->addOffline(slist.at(i+1),slist.at(i),id,&sock,db);
        }
    }
    ui->verticalLayout->addWidget(fr);
}


