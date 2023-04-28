#include "newtest.h"
#include "ui_newtest.h"

NewTest::NewTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewTest)
{
    ui->setupUi(this);
}

NewTest::~NewTest()
{
    delete ui;
}
