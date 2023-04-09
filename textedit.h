#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include    <QMainWindow>

#include            <QTextEdit>
#include             <QMenuBar>
#include                <QMenu>
#include              <QAction>
#include             <QToolBar>
#include        <QErrorMessage>
#include          <QFileDialog>
#include          <QMessageBox>
#include  <QTextDocumentWriter>
#include  <QPrinter>


#include "findwords.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TextEdit; }
QT_END_NAMESPACE

class TextEdit : public QMainWindow
{

    Q_OBJECT

public:
    TextEdit(QWidget *parent = nullptr);
    ~TextEdit();
signals:
    void signalTextDocument(QTextDocument* document);

private slots:
    void aboutSlot();

    void functionFileOpen();
    void functionFileSave();
    void functionFileExit();

    void functionEditFind();

private:
    Ui::TextEdit *ui;
    FindWords* findClass;
    QTextEdit *textEdit;

    QAction* actionFileOpen = new QAction ("Открыть",   this);
    QAction* actionFileSave = new QAction ("Сохранить", this);
    QAction* actionFileExit = new QAction ("Выход",     this);
    QAction* actionAbout    = new QAction ("Справка",   this);


    QAction* actionEditFind = new QAction("Найти", this);

    QMenuBar* createMenuBar(){

        QMenuBar* menuBar =  new QMenuBar();
                  menuBar -> addMenu (createFileMenu());
                  menuBar -> addMenu (createEditMenu());
                  menuBar -> addMenu (createHelpMenu());
        return menuBar;
    }
    QMenu* createFileMenu()
    {
        QMenu* fileMenu =  new QMenu ("File");
               fileMenu -> addAction (actionFileOpen);
               fileMenu -> addAction (actionFileSave);
               fileMenu -> addAction (actionFileExit);
        return fileMenu;
    }
    QMenu* createEditMenu()
    {
        QMenu* editMenu =  new QMenu ("Edit");
               editMenu -> addAction (actionEditFind);
               editMenu -> addAction ("Заменить");
               editMenu -> addAction ("Вырезать");
        return editMenu;
    }
    QMenu* createHelpMenu(){
        QMenu* helpMenu =  new QMenu ("Help");
               helpMenu -> addAction (actionAbout);
               helpMenu -> addAction ("О программе");
        return helpMenu;
    }


};
#endif // TEXTEDIT_H
