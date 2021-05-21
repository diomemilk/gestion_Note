#ifndef UIFARMATEUR_H
#define UIFARMATEUR_H

#include <QMainWindow>

namespace Ui {
class UIFarmateur;
}

class UIFarmateur : public QMainWindow
{
    Q_OBJECT

public:
    explicit UIFarmateur(QWidget *parent = nullptr);
     UIFarmateur(QObject *controller = nullptr);
    ~UIFarmateur();

private:
    Ui::UIFarmateur *ui;
};

#endif // UIFARMATEUR_H
