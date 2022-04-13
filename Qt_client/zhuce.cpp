#include "zhuce.h"
#include "ui_zhuce.h"

ZhuCe::ZhuCe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ZhuCe)
{
    ui->setupUi(this);
    //设置密码隐藏
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->lineEdit_3->setEchoMode(QLineEdit::Password);
   setWindowTitle(QString::fromUtf8("注册"));
    sock.connectToHost("192.168.170.128",8888);
    connect(&sock,SIGNAL(connected()),this,SLOT(handConnected()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(clean()));
}

ZhuCe::~ZhuCe()
{
    delete ui;
}

void ZhuCe::changeEvent(QEvent *e)
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

void ZhuCe::on_pushButton_clicked(){
    QString newuname = ui->lineEdit->text();
    QString newpassword = ui->lineEdit_2->text();
    QString newpasswordagain = ui->lineEdit_3->text();
    QString newquestion = ui->lineEdit_4->text();
    QString newanswer = ui->lineEdit_5->text();

    if(newuname.isEmpty()){
        QMessageBox::warning(this,QString::fromUtf8("警告"),QString::fromUtf8("用户名不能为空"));
        return;
    }
    if(newpassword.isEmpty()){
        QMessageBox::warning(this,QString::fromUtf8("警告"),QString::fromUtf8("密码不能为空"));
        return;
    }
    if(!(newpassword == newpasswordagain)){
        QMessageBox::warning(this,QString::fromUtf8("警告"),QString::fromUtf8("两次密码输入不一样"));
        return;
    }
    if(newquestion.isEmpty()){
        QMessageBox::warning(this,QString::fromUtf8("警告"),QString::fromUtf8("问题不能为空"));
        return;
    }

    if(newanswer.isEmpty()){
        QMessageBox::warning(this,QString::fromUtf8("警告"),QString::fromUtf8("答案不能为空"));
        return;
    }

    //发出用户名、密码
    QString sendBuf = "1|";
    sendBuf += newuname;
    sendBuf += "|";
    sendBuf += newpassword;
    sendBuf += "|";
    sendBuf += newquestion;
    sendBuf += "|";
    sendBuf += newanswer;
    qDebug()<<sendBuf;
    sendBuf.toStdString().c_str();

    sock.write(sendBuf.toUtf8());


}

void ZhuCe::handConnected(){
    connect(&sock,SIGNAL(readyRead()),this,SLOT(handData()));
}

void ZhuCe::handData(){
    QByteArray recvBuf = sock.readAll();
    QString buf ;
    buf = QTextCodec::codecForName("UTF-8")->toUnicode(recvBuf);

    qDebug()<<buf;
    QStringList slist = buf.split("|");
    if(slist.at(0) == "1"){
        QMessageBox::information(this,QString::fromUtf8("提示"),slist.at(1));
        this->hide();
        return;
    }else{
        QMessageBox::warning(this,QString::fromUtf8("警告"),slist.at(1));
        return;
    }
}

void ZhuCe::clean(){
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
}
