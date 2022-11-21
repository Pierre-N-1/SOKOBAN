#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "optionswindow.h"
#include "aidewindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("MonSokoban");
    part = new Partie;
    menu = true;
    pas=50; //correspond à la distance entre chaque centre d'objet (caisse, mur...)

    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center()); //deplace la fenetre au centre de l'ecran
    this->setFixedSize(this->size()); //fixe la taille de la fenetre definitivement

    //Configuration du bouton Recommencer
    ui->bRecommencerNiv->setStyleSheet("QPushButton{font-size: 21px;font-family: Montserrat;font-weight: bold;color: rgb(255, 255, 255);background-color: rgb(220,20,60);border-radius: 10px;}");
    ui->bRecommencerNiv->setIcon(QIcon (":/images/Icones/restart.png"));
    ui->bRecommencerNiv->setIconSize(QSize (30,30));

    //Configuration du bouton Menu
    ui->bMenu->setStyleSheet("QPushButton{font-size: 22px;font-family: Montserrat;font-weight: bold;color: rgb(255, 255, 255);background-color: rgb(60,179,113);border-radius: 10px;}");
    ui->bMenu->setIcon(QIcon (":/images/Icones/menu.png"));
    ui->bMenu->setIconSize(QSize (30,30));

    //Configuration du bouton Configuration
    ui->bOptions->setStyleSheet("QPushButton{font-size: 20px;font-family: Montserrat;font-weight: bold;color: rgb(255, 255, 255);background-color: rgb(138,43,226);border-radius: 10px;}");
    ui->bOptions->setIcon(QIcon (":/images/Icones/options.png"));
    ui->bOptions->setIconSize(QSize (40,40));

    //Configuration du bouton Jouer
    ui->bJouer->setStyleSheet("QPushButton{font-size: 30px;font-family: Montserrat;font-weight: bold;color: rgb(255, 255, 255);background-color: rgb(251,177,13);border-radius: 10px;}");
    ui->bJouer->setIcon(QIcon (":/images/Icones/play.png"));
    ui->bJouer->setIconSize(QSize (40,40));

    //Configuration du bouton Aide
    ui->bAide->setStyleSheet("QPushButton{font-size: 20px;font-family: Montserrat;font-weight: bold;color: rgb(255, 255, 255);background-color: rgb(254,168,119);border-radius: 10px;}");
    ui->bAide->setIcon(QIcon (":/images/Icones/aide.png"));
    ui->bAide->setIconSize(QSize (20,20));

    //Placement du plateau de jeu et lancement du premier niveau
    part->m_plat.setX(1);
    part->m_plat.setY(2);
    part->lancerNiveau(1);

    this->setFocus(Qt::TabFocusReason); //permet de "focus" les entrees clavier sur le deplacement du personnage et non sur les boutons
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent* e) {
     QWidget::paintEvent(e);
     QPainter painter(this);
     char type;

     if (menu) //on affiche le menu
     {
        painter.drawPixmap(0,0,1310,580,QPixmap(":/images/menu.png"));

        //Sur le menu, on rend invisible les boutons Menu et Recommencer et visible le bouton Jouer
        ui->bRecommencerNiv->setVisible(false);
        ui->bMenu->setVisible(false);
        ui->bJouer->setVisible(true);
        ui->line->setVisible(false);
     }

     else {
         painter.drawPixmap(0,0,1000,580,QPixmap(":/images/background.png"));

         //Sur l'interface de jeu, on rend invisible le bouton Jouer et visible les boutons Menu et Recommencer
         ui->bJouer->setVisible(false);
         ui->bRecommencerNiv->setVisible(true);
         ui->bMenu->setVisible(true);
         ui->line->setVisible(true);

         //Affichage du plateau du niveau charge
         for (int i=0; i<part->m_plat.m_la; i++){
             for (int j=0; j<part->m_plat.m_lo; j++){
                 type = part->m_plat.tab[i][j].m_type;
                 if ( type == '#'){
                     painter.drawPixmap((j+part->m_plat.getX())*pas,(i+part->m_plat.getY())*pas,50,50,QPixmap(":/images/Autres/vide.png"));
                     painter.drawPixmap((j+part->m_plat.getX())*pas,(i+part->m_plat.getY())*pas,50,50,QPixmap(":/images/Autres/mur.png"));
                 }
                 else if (type == '.' or type== '*' or type == '+'){
                     painter.drawPixmap((j+part->m_plat.getX())*pas,(i+part->m_plat.getY())*pas,50,50,QPixmap(":/images/Autres/vide.png"));
                     painter.drawPixmap((j+part->m_plat.getX())*pas,(i+part->m_plat.getY())*pas,50,50,QPixmap(":/images/Autres/cible.png"));
                 }
                 else
                     painter.drawPixmap((j+part->m_plat.getX())*pas,(i+part->m_plat.getY())*pas,50,50,QPixmap(":/images/Autres/vide.png"));
             }
         }

         //Affichage des caises et du personnage du niveau charge
         for (int i=0; i<part->m_nbCaisses; i++)
             painter.drawPixmap((part->m_c[i].getX()+ part->m_plat.getX())*pas,(part->m_c[i].getY()+ part->m_plat.getY())*pas,50,50,QPixmap(part->m_c[i].img));

         painter.drawPixmap((part->m_perso.getX() + part->m_plat.getX())*pas,(part->m_perso.getY()+ part->m_plat.getY())*pas,50,50,QPixmap(part->m_perso.img));

        //Affichage du numero du niveau actuel
         painter.setPen(QPen(Qt::darkGreen,1));
         painter.setFont(QFont("Molot",38));
         painter.drawText(10,50,QString("Niveau "+QString::number(part->getNiv())));

         //Affichage du code d'acces du niveau
         painter.setPen(QPen(Qt::black,1));
         painter.setFont(QFont("Arial",15,QFont::Bold));
         painter.drawText(1030,80,QString("Code du niveau : " + part->config.m_listeCodes[part->getNiv()-1]));

     }
}

void MainWindow::keyPressEvent (QKeyEvent * event) {
    int numCaisse;
    int x_perso = part->m_perso.getX();
    int y_perso = part->m_perso.getY();

    switch(event->key()){
     case Qt::Key_Up :
        numCaisse = part->estCaisse(x_perso,y_perso-1);
        if (part->estVide(x_perso,y_perso-1)) //Si la case en haut du personnage est vide, on le deplace
            part->m_perso.deplacerDe(0,-1);
        else if (numCaisse!=-1 and part->estVide(x_perso,y_perso-2)) //Sinon si la case en haut du personnage contient une caisse et que la case d'apres est vide, on deplace les deux
        {
            part->m_c[numCaisse].deplacerDe(0,-1);
            part->m_perso.deplacerDe(0,-1);
        }
        part->m_perso.img = ":/images/Joueur/playerUp.png";  //On affiche le personnage dans la direction du deplacement effectue
        break;

     case Qt::Key_Left :
        numCaisse = part->estCaisse(x_perso-1,y_perso);
        if (part->estVide(x_perso-1,y_perso)) //Si la case a gauche du personnage est vide, on le deplace
            part->m_perso.deplacerDe(-1,0);
        else if (numCaisse!=-1 and part->estVide(x_perso-2,y_perso)) //Sinon si la case a gauche du personnage contient une caisse et que la case d'apres est vide, on deplace les deux
        {
            part->m_c[numCaisse].deplacerDe(-1,0);
            part->m_perso.deplacerDe(-1,0);
        }
        part->m_perso.img = ":/images/Joueur/playerLeft.png";  //On affiche le personnage dans la direction du deplacement effectue
        break;

     case Qt::Key_Down :
        numCaisse = part->estCaisse(x_perso,y_perso+1);
        if (part->estVide(x_perso,y_perso + 1))  //Si la case en bas du personnage est vide, on le deplace
            part->m_perso.deplacerDe(0,1);
        else if (numCaisse!=-1 and part->estVide(x_perso,y_perso+2))  //Sinon si la case en bas du personnage contient une caisse et que la case d'apres est vide, on deplace les deux
        {
            part->m_c[numCaisse].deplacerDe(0,1);
            part->m_perso.deplacerDe(0,1);
        }
        part->m_perso.img = ":/images/Joueur/playerDown.png";  //On affiche le personnage dans la direction du deplacement effectue
        break;

     case Qt::Key_Right :
        numCaisse = part->estCaisse(x_perso+1,y_perso); //Si la case a droite du personnage est vide, on le deplace
        if (part->estVide(x_perso + 1,y_perso))
            part->m_perso.deplacerDe(1,0);
        else if (numCaisse!=-1 and part->estVide(x_perso+2,y_perso))  //Sinon si la case a droite du personnage contient une caisse et que la case d'apres est vide, on deplace les deux
        {
            part->m_c[numCaisse].deplacerDe(1,0);
            part->m_perso.deplacerDe(1,0);
        }
        part->m_perso.img = ":/images/Joueur/playerRight.png";  //On affiche le personnage dans la direction du deplacement effectue
        break;

     //Supplements : raccourci des boutons via le clavier
     case Qt::Key_R : this->on_bRecommencerNiv_clicked();
        break;
     case Qt::Key_O : this->on_bOptions_clicked();
        break;
     case Qt::Key_A : this->on_bAide_clicked();
        break;
     }

     bool finNiv = part->victoire();
     this->repaint();

     if (part->m_niv == part->config.m_nbNiveau && finNiv) //Si le dernier niveau est termine, on affiche le message special
         this->messageFinal();

     if (finNiv && part->m_niv != part->config.m_nbNiveau)  //Si un niveau quelconque est termine, on affiche le message de fin de niveau classique
         this->messageVictoire();
}

//MessageBox affichant un message de victoire
void MainWindow::messageVictoire(){
    msgBox.setWindowTitle("Bravo");
    msgBox.setText("Vous avez reussi le niveau " + QString::number(part->getNiv()));
    msgBox.setButtonText(QMessageBox::Ok,"Niveau suivant");
    msgBox.exec();

    part->lancerNiveau(part->getNiv()+1); //Suite au message, on lance le niveau suivant

    this->repaint();
}

//MessageBox affichant un message de victoire special pour le dernier niveau
void MainWindow::messageFinal(){
    msgBox.setWindowTitle("Felicitations");
    msgBox.setText("Vous avez termine le dernier niveau !!!\nToutes les caisses de l'entrepot sont rangees.");
    msgBox.setButtonText(QMessageBox::Ok,"Retour au menu");
    msgBox.exec();
    menu = true;
    this->repaint();
    this->setFocus(Qt::MouseFocusReason); //Sur le menu, on focus les entrees sur la souris
}

//Bouton permettant de recommencer le niveau
void MainWindow::on_bRecommencerNiv_clicked()
{
    part->recommencerNiveau(part->getNiv());
    this->repaint();
    this->setFocus(Qt::TabFocusReason);
}

//Bouton ramenant au menu
void MainWindow::on_bMenu_clicked()
{
    msgBox2.setWindowTitle("Retour au menu");
    msgBox2.setText("Cette action est irreversible !\nToute progression sera perdue.");  //On affiche un message de prevention en cas de miss-click
    msgBox2.setIcon(QMessageBox::Warning);
    msgBox2.setStandardButtons(QMessageBox::Yes);
    msgBox2.setDefaultButton(QMessageBox::Yes);
    msgBox2.addButton(QMessageBox::No);
    msgBox2.setButtonText(QMessageBox::Yes,"Continuer");
    msgBox2.setButtonText(QMessageBox::No,"Annuler");

    if(msgBox2.exec() == QMessageBox::Yes){
        menu = true;
        this->repaint();
    }
    this->setFocus(Qt::MouseFocusReason); //Sur le menu, on focus les entrees sur la souris
}

//Bouton ouvrant la fenetre des options (aussi nommee configuration)
void MainWindow::on_bOptions_clicked()
{
    OptionsWindow f(this);
    f.exec();
    if (f.config->m_niveauALancer != -1) //Si le niveau a lancer de cette fenetre est different de -1, alors la fenetre principale doit lancer le niveau
    {
        part->lancerNiveau(f.config->m_niveauALancer);
        menu = false;
        f.close();
    }
    this->repaint();
    this->setFocus(Qt::TabFocusReason);
}

//Bouton du menu lancant le premier niveau
void MainWindow::on_bJouer_clicked()
{
    menu = false;
    part->lancerNiveau(1);
    this->repaint();
    this->setFocus(Qt::TabFocusReason);
}

//Bouton ouvrant la fenetre d'aide
void MainWindow::on_bAide_clicked()
{
    AideWindow f(this);
    f.exec();
    this->setFocus(Qt::TabFocusReason);
}
