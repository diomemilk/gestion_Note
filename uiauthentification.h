#ifndef UIAUTHENTIFICATION_H
#define UIAUTHENTIFICATION_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class UiAuthentification; }
QT_END_NAMESPACE

class UiAuthentification : public QMainWindow
{
    Q_OBJECT

public:
    UiAuthentification(QWidget *parent = nullptr);
    UiAuthentification(QObject *controller = nullptr);
    ~UiAuthentification();
    QString getusername();
    QString getpassword();

    bool getInputs(QString &login, QString &password);
    void notificationErrer(QString message);
    void notificationInfo(QString message);

private slots:
    void updateTime();


private:
    Ui::UiAuthentification *ui;
    QTimer *time_ls;
};
#endif // UIAUTHENTIFICATION_H
