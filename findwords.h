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
    QTextDocument* document;

signals:
    void sendSignalDocument(QTextDocument* document);

private:
    Ui::FindWords *ui;

public slots:

    void On_btFindWord();
    void Off_btFindWord();
};

#endif // FINDWORDS_H
