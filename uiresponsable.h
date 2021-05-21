#ifndef UIRESPONSABLE_H
#define UIRESPONSABLE_H

#include <QMainWindow>

namespace Ui {
class uiresponsable;
}

class uiresponsable : public QMainWindow
{
    Q_OBJECT

public:
    explicit uiresponsable(QWidget *parent = nullptr);
    ~uiresponsable();

private:
    Ui::uiresponsable *ui;
};

#endif // UIRESPONSABLE_H
