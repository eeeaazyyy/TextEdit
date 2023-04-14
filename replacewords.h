#ifndef REPLACEWORDS_H
#define REPLACEWORDS_H

#include <QDialog>
#include <QTextDocument>
#include <QMessageBox>

namespace Ui {
class ReplaceWords;
}

class ReplaceWords : public QDialog
{
    Q_OBJECT

public:
    explicit ReplaceWords(QWidget *parent = nullptr);
    ~ReplaceWords();
    QTextDocument* document;
private:
    Ui::ReplaceWords *ui;
private slots:
    void OnReplaceWords();
    void ExitFunction();
};

#endif // REPLACEWORDS_H
