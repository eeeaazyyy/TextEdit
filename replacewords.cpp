#include "replacewords.h"
#include "ui_replacewords.h"

ReplaceWords::ReplaceWords(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReplaceWords)
{
    ui->setupUi(this);

    connect(ui->btReplaceOneWord,&QPushButton::clicked,this,&ReplaceWords::OnReplaceOneWord);
    connect(ui->btReplaceAll, &QPushButton::clicked,this, &ReplaceWords::OnReplaceAllWords);
    connect(ui->btCancel,  &QPushButton::clicked,this, &ReplaceWords::ExitFunction);
}

ReplaceWords::~ReplaceWords()
{
    delete ui;
}

void ReplaceWords::OnReplaceAllWords()
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

void ReplaceWords::OnReplaceOneWord()
{
    QString replacerString = ui->replacerLineInput->text();
    QString replacerInsert = ui->insertLine->text();
    QTextCursor cursor(document);
    cursor = document->find(replacerString,cursor);
    if (!cursor.isNull()){
        cursor.insertText(replacerInsert);
    }
    if (cursor.atEnd()){
        QMessageBox::information(this, tr("Замена слов завершена"),
                                 tr("Слов которые можно заменить больше нет. "));

    }

}

void ReplaceWords::ExitFunction()
{
    this -> hide();
    ui   -> replacerLineInput -> clear();
    ui   -> insertLine        -> clear();
}
