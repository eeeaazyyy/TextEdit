#include "replacewords.h"
#include "ui_replacewords.h"

ReplaceWords::ReplaceWords(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReplaceWords)
{
    ui->setupUi(this);

}

ReplaceWords::~ReplaceWords()
{
    delete ui;
}

void ReplaceWords::OnReplaceWords()
{
}
