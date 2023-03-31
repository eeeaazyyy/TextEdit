#include "textedit.h"

#include <QApplication>
#include <QTextEdit>

int main(int argc, char *argv[])
{
    QApplication a (argc, argv);
    TextEdit     w;
    w.show();
    return a.exec();
}
