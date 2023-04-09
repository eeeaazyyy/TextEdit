#ifndef FINDWORDS_H
#define FINDWORDS_H

#include <QDialog>
#include <QTextDocument>
#include <QMessageBox>


namespace Ui {
class FindWords;
}

class FindWords : public QDialog
{
    Q_OBJECT

public:
    explicit FindWords(QWidget *parent = nullptr);
    ~FindWords();

signals:


private:
    Ui::FindWords *ui;

public slots:
    void On_btFindWord(QTextDocument* document);
};

#endif // FINDWORDS_H
