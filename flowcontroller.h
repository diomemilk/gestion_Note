#ifndef FRONTCONTROLLER_H
#define FRONTCONTROLLER_H

#include "uiauthentification.h"
#include "uiadministrateur.h"
#include "service.h"
#include "usermodel.h"
#include "profile.h"
#include "uiresponsable.h"
#include "uiformateur.h"


class FlowController : public QObject
{
    Q_OBJECT

private:
    //les interfaces graphique
    UiAuthentification* uiAuthentification;
    UIAdministrateur* uiAdministrateur;
    profile* prof;
    UIResponsable* uiresponsable;
    UIFarmateur* uifarmateur;


   //couche service

    Service* service;


private slots:


    /**
     * @brief onAuthentification buttons clicked
     *
     */
    void onAuthentificationLoginClicked();
    void onAuthentificationSignUpClicked();
    void onAuthentificationExitClicked();

    /**
    * @brief onUIAdministrateur buttons clicked
    *
    */
    void onUIAdministrateurValiderClicked();
    void onUIAdministrateurListerClicked();
    void onUIAdministrateurEffacerClicked();
    void onUIAdministrateurSupprimerClicked();
    void onUIAdministrateurExitClicked();
    void onUIAdministrateurRechercherClicked();
    void onUIAdministrateurProfilClicked();


public:
    void exec();




    FlowController();
    ~FlowController();
};

#endif // FLOWTCONTROLLER_H
