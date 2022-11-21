#include "optionswindow.h"
#include "ui_optionswindow.h"

OptionsWindow::OptionsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionsWindow)
{
    ui->setupUi(this);
    setWindowTitle("Options");
    this->setFixedSize(this->size()); //fixe la taille de la fenetre definitivement

    config = new Configuration;
    codeFaux = false;

    //Configuration du bouton Retour
    ui->bRetour->setStyleSheet("QPushButton{font-size: 14px;font-family: Arial}");
    ui->bRetour->setIcon(QIcon (":/images/Icones/retour.png"));
    ui->bRetour->setIconSize(QSize (15,15));

    ui->bRetour->setAutoDefault(false); //donne le focus en priorite au bouton Valider (en tapant entree)
    this->setFocus(Qt::MouseFocusReason);
}

void OptionsWindow::paintEvent(QPaintEvent* e) {
     QWidget::paintEvent(e);
     QPainter painter(this);

     painter.setPen(QPen(Qt::darkBlue,1));
     painter.setFont(QFont("Mingzat",15));
     painter.drawText(0,30,QString("Saisir le code d'un niveau : "));

     if (codeFaux)  //Si le code d'acces saisi ne correspond a aucun niveau, on affiche un message
     {
         painter.setPen(QPen(Qt::red,1));
         painter.setFont(QFont("Monospace",12));
         painter.drawText(140,110,QString("Code incorrect"));
     }
}

OptionsWindow::~OptionsWindow()
{
    delete ui;
    delete config;
}

void OptionsWindow::on_bRetour_clicked()
{
    this->close();
}

//Renvoi le numero du niveau associe au code donne en entree si celui-ci est dans m_listeCodes. Renvoie -1 sinon.
int OptionsWindow::trouve(QString code){

    for(int i=0; i<config->m_nbNiveau; i++){
        if (config->m_listeCodes[i] == code)
            return i+1;  //On retourne i+1 car la liste commence a l'indice 0
    }
    return -1;
}

void OptionsWindow::on_bValider_clicked()
{
   int niv = trouve(ui->codeEdit->text());
   if (niv != -1){
       codeFaux = false; //Le code est correct

       //MessageBox precisant le lancement du niveau a venir
       msgBox.setWindowTitle("Code correct");
       msgBox.setText("Lancer le niveau " + QString::number(niv) + " ?");
       msgBox.setIcon(QMessageBox::Question);
       msgBox.setStandardButtons(QMessageBox::Yes);
       msgBox.setDefaultButton(QMessageBox::Yes);
       msgBox.addButton(QMessageBox::No);
       msgBox.setButtonText(QMessageBox::Yes,"Oui");
       msgBox.setButtonText(QMessageBox::No,"Non");

       if (msgBox.exec() == QMessageBox::Yes){
           config->m_niveauALancer = niv;
           this->close();
       }
   }
   else
        codeFaux = true; //Le code est incorrect

   this->repaint();
}
