#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QMainWindow>

#include <QTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class TextEdit; }
QT_END_NAMESPACE

class TextEdit : public QMainWindow
{
    Q_OBJECT

public:
    TextEdit(QWidget *parent = nullptr);
    ~TextEdit();

private:
    Ui::TextEdit *ui;
    QTextEdit *textEdit;

};
#endif // TEXTEDIT_H
