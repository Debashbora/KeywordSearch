#ifndef KEYWORDSEARCH_H
#define KEYWORDSEARCH_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class KeywordSearch; }
QT_END_NAMESPACE

class KeywordSearch : public QWidget
{
    Q_OBJECT

public:
    KeywordSearch(QWidget *parent = nullptr);
    ~KeywordSearch();



private slots:
    void on_pushButton_clicked();

private:
     Ui::KeywordSearch *ui;
     void loadTextFile();
};
#endif // KEYWORDSEARCH_H
