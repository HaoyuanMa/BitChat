#include "record.h"
#include "ui_record.h"

record::record(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::record)
{
    ui->setupUi(this);
    setWindowTitle(QString::fromUtf8("聊天记录"));
}

record::~record()
{
    delete ui;
}

void record::dsb(QString str)
{
    QString buf(str);
    QStringList slist = buf.split("|");

    if(slist.at(0)=="6")
    {
        for(int i=0;i<slist.length()-4;i+=4){

         QString time = slist.at(i+1);
         QStringList timeslist = time.split(":");
         ui->textBrowser->insertHtml(time+"&nbsp;");
         ui->textBrowser->insertHtml(slist.at(i+3)+":<br>");
         ui->textBrowser->insertHtml(slist.at(i+2)+"<br>");
     }
    }

}
