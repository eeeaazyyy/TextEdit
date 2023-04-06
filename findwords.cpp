#include "findwords.h"
#include "ui_findwords.h"

FindWords::FindWords(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindWords)
{
    ui->setupUi(this);

}

FindWords::~FindWords()
{
    delete ui;
}

void FindWords::On_btFindWord()
{

}

