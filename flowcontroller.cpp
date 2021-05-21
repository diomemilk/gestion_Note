#include "flowcontroller.h"

#include "QMessageBox"
#include <QDebug>
#include "QDateTime"
FlowController::FlowController() : uiAuthentification(nullptr), uiAdministrateur (nullptr), prof(nullptr), uiresponsable(nullptr), uifarmateur(nullptr)
{

     service = Service::getInstance();

}



/**
 * @brief onAuthentification buttons clicked
 *
 */
void FlowController::onAuthentificationLoginClicked(){


    QString login ;
    QString password ;


    if (true == uiAuthentification->getInputs(login, password))
    {
          User user;

        if (true == service->authentifier(login, password, &user))
        {
              this->uiAuthentification->close();
               delete uiAuthentification;
              uiAuthentification = nullptr;

            if (user.getType().compare("ADMINISTRATEUR") == 0)
            {
                uiAdministrateur = new UIAdministrateur(this);
                uiAdministrateur->setNam(user.getLogin());
                uiAdministrateur->show();

            }
            else if(user.getType().compare("RESPONSABLE") == 0)
            {
             //on affiche la fenetre RESPONSABLE
                uiresponsable = new UIResponsable(this);
                uiresponsable->show();
            }
            else if(user.getType().compare("ETUDIANT") == 0)
            {
             //on affiche la fenetre ETUDIANT

            }
            else if(user.getType().compare("FORMATEUR") == 0)
            {
             //on affiche la fenetre FORMATEUR
                uifarmateur = new UIFarmateur(this);
                uifarmateur->show();
            }


        }
        else{
           // QMessageBox::information(uiAuthentification,"information","login ou password incorrect");
           QMessageBox::warning(uiAuthentification, "Error","Incorrect Login/Password, please try again !", QMessageBox::Ok);
        }


    }





}
void FlowController::onAuthentificationSignUpClicked(){

}
void FlowController::onAuthentificationExitClicked(){
    bool bCloseWindow(false);

        if(QMessageBox::Yes == QMessageBox::question(uiAuthentification,"Exit", "quitter l’application? . Exit anyway ?",QMessageBox::Yes,QMessageBox::Cancel)){

            bCloseWindow = true;
        }
        if(bCloseWindow){
           this->uiAuthentification->close();
        }


}


/**
* @brief onUIAdministrateur buttons clicked
*
*/
void FlowController::onUIAdministrateurValiderClicked(){
    int identifiant = -1;
    QString login;
    QString nom;
    QString prenom;
    QString password;
    QString type;
    bool operation;
    bool statut = this->uiAdministrateur->getInputs(&identifiant,nom,prenom, login,password,type,&operation);
    if(statut){
        if(operation == true){
            User user ;
            user.setIdentifiant(identifiant);
            user.setNom(nom);
            user.setPrenom(prenom);
            user.setLogin(login);
            user.setPassword(password);
            user.setType(type);
            QString info{ "User "};
            QString info1{ " created successfully!"};
            QString s =  info + nom + info1;
            service->createUser(user);
            this->uiAdministrateur->notificationInfo(s);


        }else {
            User user ;
            user.setIdentifiant(identifiant);
            user.setNom(nom);
            user.setPrenom(prenom);
            user.setLogin(login);
            user.setPassword(password);
            user.setType(type);
            QString info{ "User "};
            QString info1{ " updated successfully!"};
            QString s =  info + nom + info1;
            service->updateUser(user);
            this->uiAdministrateur->notificationInfo(s);

        }
    }

}
void FlowController::onUIAdministrateurListerClicked(){

    this->uiAdministrateur->getTable(service->listerUser());

}
void FlowController::onUIAdministrateurEffacerClicked(){
    this->uiAdministrateur->viderInputs();

}
void FlowController::onUIAdministrateurSupprimerClicked(){
    int identifiant = -1;
    QString login;
    bool statut = this->uiAdministrateur->getId(&identifiant,login);
    if(statut){

        if(login.compare("")==0){
         this->uiAdministrateur->notificationInfo("selectionner le User qui tu vas supprimer !");

        }
        else{
            bool bCloseWindow(false);
            QString info{ "User with login :"};
            QString info1{ " has been deleted successfully!"};
            QString s =  info + login + info1;

                if(QMessageBox::Yes == QMessageBox::question(uiAuthentification,"Exit", s,QMessageBox::Yes,QMessageBox::Cancel)){

                    bCloseWindow = true;
                }
                if(bCloseWindow){
                    service->removeUser(identifiant);
                    this->uiAdministrateur->notificationInfo(s);
                    this->uiAdministrateur->viderInputs();
                }
        }
    }
}
void FlowController::onUIAdministrateurExitClicked(){
    bool bCloseWindow(false);

        if(QMessageBox::Yes == QMessageBox::question(uiAdministrateur,"Exit", "quitter l’application? . Exit anyway ?",QMessageBox::Yes,QMessageBox::Cancel)){

            bCloseWindow = true;
        }
        if(bCloseWindow){
           this->uiAdministrateur->close();
        }

}
void FlowController::onUIAdministrateurRechercherClicked(){
      this->uiAdministrateur->onClicked();
}
void FlowController::onUIAdministrateurProfilClicked(){
    this->uiAdministrateur->close();
    delete uiAdministrateur;
    uiAdministrateur = nullptr;
    prof = new profile(this);
    prof->show();

}



void FlowController::exec()
{
    uiAuthentification = new UiAuthentification(this);

    uiAuthentification->show();
}

FlowController::~FlowController()
{
    if (uiAuthentification != nullptr)
    {
        delete uiAuthentification;
    }

    if (uiAdministrateur != nullptr)
    {
        delete uiAdministrateur;
    }

    if (service != nullptr)
    {
        Service::release();
    }




}




























