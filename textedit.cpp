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

    connect(actionAbout, &QAction::triggered, this, &TextEdit::aboutSlot);
    connect(actionFileOpen, &QAction::triggered, this, &TextEdit::actionOpenFile);
    connect(actionFileSave, &QAction::triggered, this, &TextEdit::actionSaveFile);
}

TextEdit::~TextEdit()
{
    delete ui;
}

void TextEdit::aboutSlot()
{
    QMessageBox::information(0, "Message", "Not implemented");
}

void TextEdit::actionOpenFile()
{
    QString fileName = QFileDialog::getOpenFileName(nullptr,  "Выберите приложение",
                                                   QString(), "Исполняемые файлы (*.txt)");
    QFile file(fileName);
    if (fileName.isEmpty())
        return;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        textEdit->setText(file.readAll());
    }
    else
        qDebug()<<"Не робит"<<Qt::endl;


}

void TextEdit::actionSaveFile()
{
    QString nomeFile = QFileDialog::getSaveFileName(this, tr("Save File"), "",
                                                        tr("Исполняемые файлы (*.txt);;C++ File (*.cpp *.h)"));
        if (nomeFile != "") {
            QFile file(nomeFile);

            if (file.open(QIODevice::ReadWrite)) {
                QTextStream stream(&file);
                stream << textEdit->toPlainText();
                file.flush();
                file.close();
            }
            else {
                QMessageBox::critical(this, tr("Errore"), tr("Non posso salvare il file"));
                return;
            }
        }
        else qDebug()<<"Error"<<Qt::endl;
}

