#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QMainWindow>

#include <QTextEdit>

#include <QMenuBar>
#include <QMenu>


#include <QToolBar>
#include <QMessageBox>
QT_BEGIN_NAMESPACE
namespace Ui { class TextEdit; }
QT_END_NAMESPACE

class TextEdit : public QMainWindow
{

    Q_OBJECT

public:
    TextEdit(QWidget *parent = nullptr);
    ~TextEdit();


private slots:
    void slotNoImpl();
    void aboutSlot();
private:
    Ui::TextEdit *ui;
    QTextEdit *textEdit;
    /*QToolBar* createToolBar()
    {
        QToolBar* ptb = new QToolBar("Linker ToolBar");
        ptb->addAction( "File", this, SLOT(slotNoImpl()));
        ptb->addSeparator();
        ptb->addAction( "Print", this, SLOT(slotNoImpl()));
        return ptb;
    }
    */

    QMenuBar* createMenuBar(){

        QMenuBar* menuBar = new QMenuBar();
        menuBar->addMenu(createFileMenu());
        menuBar->addMenu(createEditMenu());
        menuBar->addMenu(createHelpMenu());
        return menuBar;
    }
    QMenu* createFileMenu()
    {
        QMenu* fileMenu = new QMenu("File");
        fileMenu->addAction("Открыть");
        fileMenu->addAction("Сохранить");
        fileMenu->addAction("Выход");
        return fileMenu;
    }
    QMenu* createEditMenu()
    {
        QMenu* editMenu = new QMenu("Edit");
        editMenu->addAction("Найти");
        editMenu->addAction("Заменить");
        editMenu->addAction("Вырезать");
        return editMenu;
    }
    QMenu* createHelpMenu(){
        QMenu* helpMenu = new QMenu("Help");
        helpMenu->addAction("Справка");
        helpMenu->addAction("О программе");
        return helpMenu;
    }
};
#endif // TEXTEDIT_H
