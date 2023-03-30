#include "textedit.h"
#include "./ui_textedit.h"

TextEdit::TextEdit(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TextEdit)
{


    ui->setupUi(this);
    this->setMenuBar(createMenuBar());

    textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);

}

TextEdit::~TextEdit()
{
    delete ui;
}

void TextEdit::slotNoImpl()
{
    QMessageBox::information(0, "Message", "Not implemented");
}

