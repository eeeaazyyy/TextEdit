#include "replacewords.h"
#include "ui_replacewords.h"

ReplaceWords::ReplaceWords(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReplaceWords)
{
    ui->setupUi(this);
    connect(ui->btReplace, &QPushButton::clicked,this, &ReplaceWords::OnReplaceWords);
    connect(ui->btCancel,  &QPushButton::clicked,this, &ReplaceWords::ExitFunction);
}

ReplaceWords::~ReplaceWords()
{
    delete ui;
}

void ReplaceWords::OnReplaceWords()
{
    QString replacerString = ui->replacerLineInput->text();
    QString replacerInsert = ui->insertLine->text();

    QTextCursor cursor(document);
    while(!cursor.isNull()&&!cursor.atEnd()){
        cursor = document->find(replacerString,cursor);
        if (!cursor.isNull()){
            cursor.insertText(replacerInsert);
        }
    }
}

void ReplaceWords::ExitFunction()
{
    this -> hide();
    ui   -> replacerLineInput -> clear();
    ui   -> insertLine        -> clear();
}
