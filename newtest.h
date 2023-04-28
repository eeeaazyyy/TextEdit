#ifndef NEWTEST_H
#define NEWTEST_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class NewTest;
}

class NewTest : public QWidget
{
    Q_OBJECT

public:
    explicit NewTest(QWidget *parent = nullptr);
    ~NewTest();

private:
    Ui::NewTest *ui;
    QPushButton* button = new QPushButton("hello");
};

#endif // NEWTEST_H
