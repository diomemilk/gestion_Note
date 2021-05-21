#ifndef UIRESPONSABLE_H
#define UIRESPONSABLE_H

#include <QMainWindow>

namespace Ui {
class UIResponsable;
}

class UIResponsable : public QMainWindow
{
    Q_OBJECT

public:
    explicit UIResponsable(QWidget *parent = nullptr);
     UIResponsable(QObject *controller = nullptr);
    ~UIResponsable();

private:
    Ui::UIResponsable *ui;
};

#endif // UIRESPONSABLE_H
