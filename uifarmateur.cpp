#include "uifarmateur.h"
#include "ui_uifarmateur.h"

UIFarmateur::UIFarmateur(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UIFarmateur)
{
    ui->setupUi(this);
}
UIFarmateur::UIFarmateur(QObject *controller)
    : ui(new Ui::UIFarmateur)
{
    ui->setupUi(this);

}

UIFarmateur::~UIFarmateur()
{
    delete ui;
}
