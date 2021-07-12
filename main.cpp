#include "keywordsearch.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    KeywordSearch w;
    w.show();
    return a.exec();
}
