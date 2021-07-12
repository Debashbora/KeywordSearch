#include "keywordsearch.h"
#include "ui_keywordsearch.h"
#include <QFile>
#include <QTextStream>
#include<QSyntaxHighlighter>
#include<QString>



KeywordSearch::KeywordSearch(QWidget *parent)
    : QWidget(parent), ui(new Ui::KeywordSearch)
{
    ui->setupUi(this);
    loadTextFile();
    QMetaObject::connectSlotsByName(this);
}

KeywordSearch::~KeywordSearch()
{
    delete ui;
}
void KeywordSearch::loadTextFile()
{
    QFile inputFile(":/input.txt");
    inputFile.open(QIODevice::ReadOnly);

    QTextStream in(&inputFile);
    QString line = in.readAll();
    inputFile.close();

    ui->textEdit->setPlainText(line);


    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);


}
void KeywordSearch::on_pushButton_clicked()
{
    QString searchString=ui->lineEdit->text();
    ui->textEdit->find(searchString, QTextDocument::FindWholeWords);


    int length_of_the_selection=ui->textEdit->toPlainText().length();
    int begin;

    begin=searchString.indexOf(searchString);

    int end = begin + length_of_the_selection;

    QTextCharFormat fmt;

    fmt.setBackground(Qt::yellow);

    QTextCursor cursor(ui->textEdit->document());
    cursor.setPosition(begin, QTextCursor::MoveAnchor);
    cursor.setPosition(end, QTextCursor::KeepAnchor);
    cursor.setCharFormat(fmt);

}

