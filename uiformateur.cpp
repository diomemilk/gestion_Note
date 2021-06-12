#include "uiformateur.h"
#include "ui_uiformateur.h"

UIFormateur::UIFormateur(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UIFormateur)
{
    ui->setupUi(this);
}
UIFormateur::UIFormateur(QObject *controller)
    : ui(new Ui::UIFormateur)
{
    ui->setupUi(this);

}

UIFormateur::~UIFormateur()
{
    delete ui;
}
