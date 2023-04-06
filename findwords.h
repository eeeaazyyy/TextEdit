#ifndef FINDWORDS_H
#define FINDWORDS_H

#include <QDialog>



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


};

#endif // FINDWORDS_H
