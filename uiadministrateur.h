#ifndef UIADMINISTRATEUR_H
#define UIADMINISTRATEUR_H

#include <QMainWindow>
#include "QSqlQueryModel"
#include <QSqlDatabase>

namespace Ui {
class UIAdministrateur;
}

class UIAdministrateur : public QMainWindow
{
    Q_OBJECT

public:
    // rega_explicit
    UIAdministrateur(QWidget *parent = nullptr);
    UIAdministrateur(QObject *controller = nullptr);
    ~UIAdministrateur();
    bool getInputs(int* identifiant,QString &nom,QString &prenom, QString &login,QString &password,QString &type,bool* operation);
    bool getId(int* identifiant,QString &login);
    void setNam(QString login);
    void getTable(QSqlQueryModel* model );
    void viderInputs();
    void notificationInfo(QString message);
    void findText(const QString & text, int from);
    void onClicked();

private slots:
    void on_tableView_activated(const QModelIndex &index);


private:
    Ui::UIAdministrateur *ui;
    QSqlDatabase db;
    int index = -1;
};

#endif // UIADMINISTRATEUR_H
