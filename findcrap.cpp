#include "findcrap.h"
#include "ui_findcrap.h"
#include <QFile>
#include <QTextStream>

findcrap::findcrap(QWidget *parent) :QWidget(parent),ui(new Ui::findcrap)
{
    ui->setupUi(this);      // sets up the user interface
    getTextFile();
}

findcrap::~findcrap()
{
    delete ui;
}

void findcrap::on_goButton_clicked()
{
    QString word = ui->lineEdit->text();
    ui->textEdit->find(word,QTextDocument::FindWholeWords);
}

void findcrap::getTextFile()
{
    QFile myfile(":/crap.txt");
    myfile.open(QIODevice::ReadOnly);
    QTextStream textStream(&myfile);

    QString line=textStream.readAll();
    myfile.close();

    ui->textEdit->setPlainText(line);
    QTextCursor textCursor = ui->textEdit->textCursor();
    textCursor.movePosition(QTextCursor::Start,QTextCursor::MoveAnchor,1);
}
