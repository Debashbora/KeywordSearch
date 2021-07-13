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
   QTextEdit* edit = ui->textEdit;
  QString content = edit->toPlainText();
  QString target = ui->lineEdit->text();

  QTextCharFormat fmt;
  fmt.setBackground(Qt::Yellow);
  
  int start = content.indexOf(target, 0);
  QTextCursor cursor(edit->document());
  while(start != -1){
    cursor.setPosition(start, QTextCursor::MoveAnchor);
    cursor.setPosition(start + target.size(), QTextCursor::KeepAnchor);
    cursor.setCharFormat(fmt);
    start = content.indexOf(target, start + 1);
  }

}

