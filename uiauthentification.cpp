#include "uiauthentification.h"
#include "ui_uiauthentification.h"
#include "QMessageBox"
#include <QTimer>
#include <QTime>
#include <QDateTime>

UiAuthentification::UiAuthentification(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UiAuthentification)
{

    ui->setupUi(this);
}

UiAuthentification::UiAuthentification(QObject *controller)
    : ui(new Ui::UiAuthentification)
{
    ui->setupUi(this);
    connect(ui->pushButtonLogin, SIGNAL(clicked()), controller, SLOT(onAuthentificationLoginClicked()));
    connect(ui->shutdownButton, SIGNAL(clicked()), controller, SLOT(onAuthentificationExitClicked()));

    time_ls = new QTimer(this);
    time_ls->setInterval(1000); // Une seconde
    connect(time_ls, SIGNAL(timeout()), this, SLOT(updateTime()));
    time_ls->start();
}

UiAuthentification::~UiAuthentification()
{
    delete ui;
}


bool UiAuthentification::getInputs(QString &login, QString &password){

    login = ui->lineEdit_login->text();
    password = ui->lineEdit_password->text();
    if(login.compare("") == 0 || password.compare("") ==0){

        QMessageBox::critical(this,"info","isImptu",QMessageBox::Ok);
        return false;
    }

    return true;
}


QString UiAuthentification::getusername(){
    return ui->lineEdit_login->text();

}
QString UiAuthentification::getpassword(){
    return ui->lineEdit_password->text();
}



void  UiAuthentification::notificationErrer(QString message){
       QMessageBox::critical(this,"Erro",message,QMessageBox::Ok);
}
void  UiAuthentification::notificationInfo(QString message){

    QMessageBox::information(this,"information",message);
}


void  UiAuthentification::updateTime(){
     QString sDate = QDateTime::currentDateTime().toString("dddd dd MMMM yyyy hh:mm:ss");
    ui->currentDateTime->setText(sDate);

}






















