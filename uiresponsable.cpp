#include "uiresponsable.h"
#include "ui_uiresponsable.h"

uiresponsable::uiresponsable(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::uiresponsable)
{
    ui->setupUi(this);
}

uiresponsable::~uiresponsable()
{
    delete ui;
}
