#include "textedit.h"
#include "./ui_textedit.h"

TextEdit::TextEdit(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TextEdit)
{
    ui   -> setupUi    (this);
    this -> setMenuBar (createMenuBar());

    textEdit = new QTextEdit (this);
    setCentralWidget         (textEdit);

    connect(actionAbout,    &QAction::triggered, this, &TextEdit::aboutSlot);
    connect(actionFileOpen, &QAction::triggered, this, &TextEdit::functionFileOpen);
    connect(actionFileSave, &QAction::triggered, this, &TextEdit::functionFileSave);
    connect(actionFileExit, &QAction::triggered, this, &TextEdit::functionFileExit);
}

TextEdit::~TextEdit()
{
    delete ui;
}

void TextEdit::aboutSlot()
{
    QMessageBox::information (0, "Message", "Not implemented");
}

void TextEdit::functionFileOpen()
{
    QString fileName = QFileDialog::getOpenFileName(nullptr,  "Выберите приложение",
                                                   QString(), "Исполняемые файлы (*.txt *.doc *.docx)");
    QFile   file(fileName);
    if (fileName.isEmpty()) return;

    if (file.open (QIODevice::ReadOnly | QIODevice::Text)){
        textEdit -> setText (file.readAll());
    }
    else qDebug()<<"Не робит"<<Qt::endl;
}

void TextEdit::functionFileSave()
{
    QString nameFile = QFileDialog::getSaveFileName(this, tr("Save File"), "",
                                                        tr("Исполняемые файлы (*.txt);;Docx Files (*.doc *.docx);;Pdf (*.pdf)"));
        if (nameFile != "")
        {
            QFile file(nameFile);

            QFileInfo fileInfo(nameFile);
            QString ext = fileInfo.completeSuffix();

            qDebug()<<ext<<" Суффикс"<<Qt::endl;

            QTextDocumentWriter textWriter;
            textWriter.setFileName(file.fileName());

            if (file.open(QIODevice::ReadWrite))
            {
                /*QTextStream stream (&file);
                            stream << textEdit->toPlainText();*/
                if (ext == "pdf"){
                      QPrinter printer;
                      printer.setOutputFormat(QPrinter::PdfFormat);
                      printer.setOutputFileName(nameFile);

                      QTextDocument *doc = textEdit->document();
                      doc->print(&printer);
                      qDebug()<<"Файл сохранился в PDF"<<Qt::endl;

                }
                if (ext == "txt"||ext =="docx"||ext=="doc"){

                    QTextDocumentWriter doc;
                    doc.setFileName(nameFile);
                    doc.setFormat(ext.toLatin1());
                    doc.write(textEdit->document());
                    qDebug()<<"Файл сохранился в TXT"<<Qt::endl;
                }



                file.flush();
                file.close();
            }
            else
            {
                QMessageBox::critical(this, tr("Error"),
                                      tr("Нет файла"));
                return;
            }
        }
        else qDebug()<<"Error"<<Qt::endl;
}

void TextEdit::functionFileExit()
{
    QCoreApplication::quit();
}

