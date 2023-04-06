#include "textedit.h"
#include "findwords.h"

#include <QApplication>
#include <QTextEdit>

int main(int argc, char *argv[])
{
    QApplication a (argc, argv);
    TextEdit     w;
    FindWords f;
    w.show();
    //f.show();

    return a.exec();
}
