#ifndef FINDCRAP_H
#define FINDCRAP_H

#include <QWidget>

namespace Ui {      //namespace groups all classes together
class findcrap;
}

class findcrap : public QWidget
{
    Q_OBJECT
    
public:
    explicit findcrap(QWidget *parent = 0);
    ~findcrap();
    
private slots:
    void on_goButton_clicked();

private:
    Ui::findcrap *ui;
    void getTextFile();
};

#endif // FINDCRAP_H
