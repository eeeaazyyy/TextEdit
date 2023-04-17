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
#include             <QPrinter>
#include          <QFontDialog>
#include     <QContextMenuEvent>

#include "findwords.h"
#include "replacewords.h"

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
    void signalTextDocumentForReplace(QTextDocument* document);

private slots:
    void aboutSlot();

    void functionFileOpen();
    void functionFileSave();
    void functionFileExit();

    void functionEditFind();
    void functionEditFont();
    void functionEditReplace();
    void functionEditCut();

    void showContextMenu(const QPoint &pt);
    void functionContextEditFont();


private:
    Ui::TextEdit *ui;

    ReplaceWords*      replaceClass;
    FindWords*         findClass;
    QTextEdit*         textEdit;
    QContextMenuEvent* event;

    QAction* actionFileOpen = new QAction ("Открыть",   this);
    QAction* actionFileSave = new QAction ("Сохранить", this);
    QAction* actionFileExit = new QAction ("Выход",     this);
    QAction* actionAbout    = new QAction ("Справка",   this);

    QAction* actionEditFind    = new QAction ("Найти",    this);
    QAction* actionEditFont    = new QAction ("Шрифт",    this);
    QAction* actionEditReplace = new QAction ("Заменить", this);
    QAction* actionEditCut     = new QAction ("Вырезать", this);


    QAction* actionContextFont = new QAction("Изменить выделенный шрифт", this);

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

               actionFileSave -> setShortcut (Qt::CTRL|Qt::Key_S);
        return fileMenu;
    }
    QMenu* createEditMenu()
    {
        QMenu* editMenu =  new QMenu ("Edit");
               editMenu -> addAction (actionEditFind);
               editMenu -> addAction (actionEditFont);
               editMenu -> addAction (actionEditReplace);
               editMenu -> addAction (actionEditCut);

               actionEditFind -> setShortcut (Qt::CTRL|Qt::Key_F);
               actionEditCut  -> setShortcut (Qt::CTRL|Qt::Key_X);

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
