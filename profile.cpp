#include "profile.h"
#include "ui_profile.h"

profile::profile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::profile)
{
    ui->setupUi(this);
}
profile::profile(QObject *controller)
    : ui(new Ui::profile)
{
    ui->setupUi(this);
    connect(ui->pushButton_retour, SIGNAL(clicked()), controller, SLOT(onAuthentificationLoginClickedeeee()));
}

profile::~profile()
{
    delete ui;
}
