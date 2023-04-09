#include "findwords.h"
#include "ui_findwords.h"

FindWords::FindWords(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindWords)
{
    ui->setupUi(this);
    //connect(ui->btFindWord, &QPushButton::clicked,[this, document](){ this->On_btFindWord(document); });
}

FindWords::~FindWords()
{
    delete ui;
}

void FindWords::On_btFindWord(QTextDocument* document)
{
    QString searchString = ui->lineEditFindWord->text();
    bool found = false;
    document->undo();
    if (searchString.isEmpty()) {
            QMessageBox::information(this, tr("Empty Search Field"),
                                     tr("The search field is empty. "
                                        "Please enter a word and click Find."));
        } else {
            QTextCursor highlightCursor(document);
            QTextCursor cursor(document);

            cursor.beginEditBlock();

            QTextCharFormat plainFormat(highlightCursor.charFormat());
            QTextCharFormat colorFormat = plainFormat;
            colorFormat.setForeground(Qt::red);

            while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
                highlightCursor = document->find(searchString, highlightCursor,
                                                 QTextDocument::FindWholeWords);

                if (!highlightCursor.isNull()) {
                    found = true;
                    highlightCursor.movePosition(QTextCursor::WordRight,
                                                 QTextCursor::KeepAnchor);
                    highlightCursor.mergeCharFormat(colorFormat);
                }
            }

            cursor.endEditBlock();

            if (found == false) {
                QMessageBox::information(this, tr("Word Not Found"),
                                         tr("Sorry, the word cannot be found."));
            }
    }
}

