#include "findwords.h"
#include "ui_findwords.h"

FindWords::FindWords(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindWords)
{
    ui->setupUi(this);
    //connect(ui->btFindWord, &QPushButton::clicked,this, std::bind(&FindWords::On_btFindWord,this, document)   );
    connect(ui->btFindWord, &QPushButton::clicked, this, &FindWords::On_btFindWord);
    connect(ui->btCancel, &QPushButton::clicked, this, &FindWords::Off_btFindWord);
}

FindWords::~FindWords()
{
    delete ui;
}


void FindWords::On_btFindWord()
{

    QString searchString = ui->lineEditFindWord->text();
    bool found = false;
    //document->undo();
    if (searchString.isEmpty()) {
            QMessageBox::information(this, tr("Empty Search Field"),
                                     tr("The search field is empty. "
                                        "Please enter a word and click Find."));
        } else {
            QTextCursor highlightCursor(document);
            QTextCursor cursor(document);

            cursor.beginEditBlock();

            plainFormat = new QTextCharFormat(highlightCursor.charFormat());
            colorFormat = new QTextCharFormat(*plainFormat);
            colorFormat->setForeground(Qt::red);

            while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
                highlightCursor = document->find(searchString, highlightCursor,
                                                 QTextDocument::FindWholeWords);

                if (!highlightCursor.isNull()) {
                    found = true;
                    highlightCursor.movePosition(QTextCursor::WordRight,
                                                 QTextCursor::KeepAnchor);
                    highlightCursor.mergeCharFormat(*colorFormat);
                }
            }

            cursor.endEditBlock();

            if (found == false) {
                QMessageBox::information(this, tr("Word Not Found"),
                                         tr("Sorry, the word cannot be found."));
            }
    }
}

void FindWords::Off_btFindWord()
{
    delete plainFormat;
    delete colorFormat;
    this->hide();

}

