#ifndef UIFORMATEUR_H
#define UIFORMATEUR_H

#include <QMainWindow>

namespace Ui {
class UIFormateur;
}

class UIFormateur : public QMainWindow
{
    Q_OBJECT

public:
    explicit UIFormateur(QWidget *parent = nullptr);
     UIFormateur(QObject *controller = nullptr);
    ~UIFormateur();
     bool getInputs(int* identifiant,QString &nom,QString &prenom, QString &login,QString &password,QString &type,bool* operation);
     bool getId(int* identifiant,QString &login);
     void setNam(QString login);
     void viderInputs();
     void notificationInfo(QString message);
     void findText(const QString & text, int from);
     void onClicked();

private:
    Ui::UIFormateur *ui;
};

#endif // UIFORMATEUR_H
