#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "unistd.h"
#include "stdio.h"
#include "iostream"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Connexion des langues
    QObject::connect (ui->actionDeutsch, &QAction::triggered, this, [this] { change_languages(1); });
    QObject::connect (ui->actionEnglish, &QAction::triggered, this, [this] { change_languages(2); });
    QObject::connect (ui->actionFrancais, &QAction::triggered, this, [this]{ change_languages(3); });
    QObject::connect (ui->actionOccitan, &QAction::triggered, this, [this] { change_languages(4); });

    QObject::connect(ui->actionMorceaux, &QAction::triggered, this, [this] { change_mode(false); });
    QObject::connect(ui->actionRadio, &QAction::triggered, this, [this] { change_mode(true); });

    ui->Nom_utilisateur->setFixedWidth(400);
    ui->Connexion->setFixedWidth(130);

    Loadwidget* loading = new Loadwidget();
    ui->LoadLayout->addWidget(loading);
    loading->show();

    /*
     * Ajouter un thread de la forme
     * QTransform t; t.rotate(30);
    while(condition de chargement)
    {
        QThread::sleep(1);
        image = image.transformed(t);
        show();
    }
    */

    //Définition d'une norme (arbitraire) de taille de boutons : 70x50 pixels
    size.setWidth(50); size.setHeight(70);

    //Redimensionnement des boutons
    pix_rewind.load(":/pics/rewind.png");
    icon_rewind.addPixmap(pix_rewind);
    ui->Rewind->setIcon(icon_rewind);
    ui->Rewind->setIconSize(size);

    pix_previous.load(":/pics/previous.png");
    icon_previous.addPixmap(pix_previous);
    ui->Previous->setIcon(icon_previous);
    ui->Previous->setIconSize(size);

    pix_play.load(":/pics/play.jpg");
    icon_play.addPixmap(pix_play);
    ui->Play_pause->setIcon(icon_play);
    ui->Play_pause->setIconSize(size);

    pix_next.load(":/pics/previous.png");
    //Rotation de 180° d'une flèche allant de droite à gauche = une flèche de gauche à droite
    QTransform transform_next; transform_next.rotate(180); pix_next = pix_next.transformed(transform_next);
    icon_next.addPixmap(pix_next);
    ui->Next->setIcon(icon_next);
    ui->Next->setIconSize(size);

    pix_foward.load(":/pics/rewind.png");
    //Rotation de 180° d'une flèche allant de droite à gauche = une flèche de gauche à droite
    QTransform transform_foward; transform_foward.rotate(180); pix_foward = pix_foward.transformed(transform_foward);
    icon_foward.addPixmap(pix_foward);
    ui->Foward->setIcon(icon_foward);
    ui->Foward->setIconSize(size);

    pix_sound.load(":/pics/sound.png");
    icon_sound.addPixmap(pix_sound);
    ui->Mute->setIcon(icon_sound);
    ui->Mute->setIconSize(size);

    QSize main_size; main_size.setHeight(330); main_size.setWidth(330);
    ui->Image->setFixedSize(size);
    pix_music.load(":/pics/music.png");
    pix_music = pix_music.scaled(330,330);
    ui->Image->setPixmap(pix_music);
    ui->Image->setFixedSize(main_size);

    //Définition initiale du volume
    //Utiliser des automates
    memVolume = 50;
    ui->Volume->setValue(memVolume);

    flag_play = false;
    flag_mute = false;
    flag_radio = false;

    Automate_morceaux *automate_morceaux = new Automate_morceaux();
    Automate_radio *automate_radio = new Automate_radio();
    Automate_son *automate_son = new Automate_son();

    // On se connecte à l'automate morceaux
    QObject::connect(automate_morceaux, SIGNAL(signalMachine(signalType,bool,int,int)), this, SLOT(message(signalType,bool,int,int)));
    // On se connecte à l'automate radio
    QObject::connect(automate_radio, SIGNAL(signalMachine(signalType,bool,int,int)), this, SLOT(message(signalType,bool,int,int)));
    // On se connecte à l'automate son
    QObject::connect(automate_son, SIGNAL(signalMachine(signalType,bool,int,int)), this, SLOT(message(signalType,bool,int,int)));
}

MainWindow::~MainWindow()
{
    //SegFault quand on delete les automates
    delete ui;
}

void MainWindow::on_Connexion_toggled(bool checked)
{
    if (checked)                      // Si l'utilisateur est déjà connecté
    {
        deconnexion();                //On interrompt la connexion avec le serveur
    } else                            // Si l'utilisateur n'est pas connecté
    {
        connexion();                  //On lance la connexion
    }
}

void MainWindow::on_Progression_sliderMoved(int position)
{
    //Pause de la lecture
    pause();

    //Déplacement de la lecture
    //Fonction avec le serveur et la valeur

    //Lancement de la lecture
    play();
}

void MainWindow::on_Rewind_pressed()
{
    /*int speed_factors[7] = {1,2,5,10,20,30,60}; int i = 0;
    while(ui->Rewind->isChecked()) //Pas sûr
    {
        rewind(speed_factors[i]);
        QThread::sleep(speed_factors[i]); //Attente de speed_factors[id] secondes avant d'augmenter la vitesse
        if (i < 6) i++;
        //Déplacement de la barre
    }*/
    rewind(1);
}

void MainWindow::on_Rewind_released()
{
    play();
}

void MainWindow::on_Previous_clicked()
{
    //Pause de la lecture
    pause();

    //Envoi de la demande de previous au serveur
    previous();

    //Lancement de la lecture du morceau précédent
    play();
}

void MainWindow::on_Play_pause_clicked()
{
    if (flag_play)                      //Si un morceau est joué, l'image de pause est affichée
    {
        //Arrêt de la lecture
        pause();

        //MAJ de l'état de lecture
        flag_play = false;

        //Changement de l'icône du bouton
        pix_play.load(":/pics/play.jpg"); //Bug incompréhensible les images ne veulent plus se charger une fois que play.jpg est chargé
        icon_play.addPixmap(pix_play);
        ui->Play_pause->setIcon(icon_play);
        ui->Play_pause->setIconSize(size);
        std::cout << "popause" << std::endl;

    } else                              //Le lecteur est en pause, l'image de play est affichée
    {
        //Lancement de la lecture
        play();

        //MAJ de l'état de lecture
        flag_play = true;

        //Changement de l'icône du bouton
        pix_play.load(":/pics/pause.jpg");      //Bug : Ne s'affiche pas
        icon_play.addPixmap(pix_play);
        ui->Play_pause->setIcon(icon_play);
        ui->Play_pause->setIconSize(size);
        std::cout << "plplay" << std::endl;

    }
}

void MainWindow::on_Next_clicked()
{
    //Pause de la lecture
    pause();

    //Envoi de la demande de next au serveur
    next();

    //Lancement de la lecture du morceau précédent
    play();
}

void MainWindow::on_Foward_pressed()
{
    /*int speed_factors[7] = {1,2,5,10,20,30,60}; int i = 0;
    while(ui->Foward->isChecked()) //Pas sûr
    {
        foward(speed_factors[i]);
        QThread::sleep(speed_factors[i]);         //Attente de speed_factors[i] secondes avant d'augmenter la vitesse
        if (i < 6) i++;
    }*/
    foward(1);
}

void MainWindow::on_Foward_released()
{
    play();
}

void MainWindow::on_Mute_clicked()
{
    if (flag_mute)                      //Si le mode mute est activé
    {
        //Déclenchement de la fonction mute et récupération du pourcentage de son max enregistré
        //mute(-1);

        //MAJ de l'état de lecture
        flag_mute = false;

        //Changement de l'icône du bouton
        pix_sound.load(":/pics/sound.png");
        icon_sound.addPixmap(pix_sound);
        ui->Mute->setIcon(icon_sound);
        ui->Mute->setIconSize(size);

        //Restauration du volume
        setVolume(memVolume);

        //Repositionnement de la barre
        ui->Volume->setValue(memVolume);

    } else                          //Le mute est désactivé
    {
        //Déclenchement de la fonction mute et stockage du pourcentage de son max enregistré
        mute(ui->Volume->value());

        //MAJ de l'état de lecture
        flag_mute = true;

        //Changement de l'icône du bouton
        pix_sound.load(":/pics/mute.jpg");
        icon_sound.addPixmap(pix_sound);
        ui->Mute->setIcon(icon_sound);
        ui->Mute->setIconSize(size);

        //Stockage de la valeur du volume
        memVolume = ui->Volume->value();

        //Repositionnement de la barre
        ui->Volume->setValue(0);
    }
}

void MainWindow::on_Volume_sliderMoved(int position)
{
    if (flag_mute)                        //Si le mode mute est activé, il devient désactivé automatiquement
    {
        //Déclenchement de la fonction mute
        mute(-1);             //Désactivation du mute

        //MAJ de l'état de lecture
        flag_mute = false;

        //Changement de l'icône du bouton
        pix_sound.load(":/pics/sound.png");
        icon_sound.addPixmap(pix_sound);
        ui->Mute->setIcon(icon_sound);
        ui->Mute->setIconSize(size);

        //Modification du volume
        setVolume(position);
    } else                                //Si le mode mute n'est pas activé
    {
        //Modification du volume
        setVolume(position);

        if (position == 0)
        {
            flag_mute = true;

            //Changement de l'icône du bouton
            pix_sound.load(":/pics/mute.jpg");
            icon_sound.addPixmap(pix_sound);
            ui->Mute->setIcon(icon_sound);
            ui->Mute->setIconSize(size);
        }

    }
}

void MainWindow::change_languages(int language_id)
{
    switch (language_id)
    {
        case 1: //Deutsch
            ui->menuModes->setTitle(QString::fromStdString("Modus"));
            ui->actionMorceaux->setText(QString::fromStdString("Musik"));
            ui->actionRadio->setText(QString::fromStdString("Radiofunk"));

            ui->menuLangues->setTitle(QString::fromStdString("Sprachen"));
            //Noms des langues non modifiées

            ui->Connexion->setText(QString::fromStdString("Verbindet"));

            ui->actionDeutsch->setChecked(true);
            ui->actionEnglish->setChecked(false);
            ui->actionFrancais->setChecked(false);
            ui->actionOccitan->setChecked(false);
        break;
        case 2: //English
            ui->menuModes->setTitle(QString::fromStdString("Modes"));
            ui->actionMorceaux->setText(QString::fromStdString("Music"));
            ui->actionRadio->setText(QString::fromStdString("Radio"));

            ui->menuLangues->setTitle(QString::fromStdString("Languages"));
            //Noms des langues non modifiées

            ui->Connexion->setText(QString::fromStdString("Connected"));

            ui->actionDeutsch->setChecked(false);
            ui->actionEnglish->setChecked(true);
            ui->actionFrancais->setChecked(false);
            ui->actionOccitan->setChecked(false);
        break;
        case 3: //Français
            ui->menuModes->setTitle(QString::fromStdString("Modes"));
            ui->actionMorceaux->setText(QString::fromStdString("Morceaux"));
            ui->actionRadio->setText(QString::fromStdString("Radio"));

            ui->menuLangues->setTitle(QString::fromStdString("Langues"));
            //Noms des langues non modifiées

            ui->Connexion->setText(QString::fromStdString("Connecté"));

            ui->actionDeutsch->setChecked(false);
            ui->actionEnglish->setChecked(false);
            ui->actionFrancais->setChecked(true);
            ui->actionOccitan->setChecked(false);
        break;
        case 4: //Occitan
            ui->menuModes->setTitle(QString::fromStdString("Mòu"));
            ui->actionMorceaux->setText(QString::fromStdString("Musica"));
            ui->actionRadio->setText(QString::fromStdString("Radia"));

            ui->menuLangues->setTitle(QString::fromStdString("Lenga"));
            //Noms des langues non modifiées

            ui->Connexion->setText(QString::fromStdString("Noselança"));

            ui->actionDeutsch->setChecked(false);
            ui->actionEnglish->setChecked(false);
            ui->actionFrancais->setChecked(false);
            ui->actionOccitan->setChecked(true);
    }
}

void MainWindow::change_mode(bool radio)
{
    if(!radio) // Si le mode radio doit être désactivé
    {
        //Affichage ce qui a été caché
        ui->Progression->show();
        ui->Temps_lu->show();
        ui->Temps_restant->show();
        ui->Rewind->show();
        ui->Foward->show();

        //MAJ du flag
        flag_radio = false;

        //Récupération de l'état précédent
        //Fonction à définir

        ui->actionMorceaux->setChecked(true);
        ui->actionRadio->setChecked(false);
    } else
    {
        //Cache
        ui->Progression->hide();
        ui->Temps_lu->hide();
        ui->Temps_restant->hide();
        ui->Rewind->hide();
        ui->Foward->hide();

        //MAJ du flag
        flag_radio = true;

        //Récupération de l'état précédent
        //Fonction à définir

        ui->actionMorceaux->setChecked(false);
        ui->actionRadio->setChecked(true);
    }
}

void MainWindow::connexion()
{
    //A définir une fois que la question du serveur est résolue
}

void MainWindow::deconnexion()
{
    //A définir une fois que la question du serveur est résolue
}

QString MainWindow::user_name()
{
    return ui->Nom_utilisateur->text();
}

void MainWindow::get_list_metadata()
{
    //A définir une fois que la structure des métadatas sont comprises
}

void MainWindow::get_music_metadata()
{
    //A définir une fois que la structure des métadatas sont comprises
}

void MainWindow::show_list_metadata()
{
    //A définir une fois que la structure des métadatas sont comprises
}

void MainWindow::show_music_metadata()
{
    //A définir une fois que la structure des métadatas sont comprises
}

void MainWindow::rewind(int speed)
{
    //A définir une fois que le système de messages sera établi et que le fonctionnement audio sera assimilé
}

void MainWindow::previous()
{
    //A définir une fois que le système de messages sera établi et que le fonctionnement audio sera assimilé
}

void MainWindow::play()
{
    //A définir une fois que le système de messages sera établi et que le fonctionnement audio sera assimilé
}

void MainWindow::pause()
{
    //A définir une fois que le système de messages sera établi et que le fonctionnement audio sera assimilé
}

void MainWindow::next()
{
    //A définir une fois que le système de messages sera établi et que le fonctionnement audio sera assimilé
}

void MainWindow::foward(int speed)
{
    //A définir une fois que le système de messages sera établi et que le fonctionnement audio sera assimilé
}

int MainWindow::mute(int vol)
{
    //A définir une fois que le système de messages sera établi et que le fonctionnement audio sera assimilé
    /* Fonctionnnement global :
     * mute prend comme argument le volume enregistré (ex: 42 "pourcents") quand on passe en mute et revoie -1
     * mute prend -1 comme argument quand on sort du mute et renvoie le pourcentage du volume enregistré
     * J'ai choisi -1 plutôt que 0 (qui semble un meilleur choix à première vue) pour éviter un conflit entre la barre de son, qui devient automatiquement mute
     * quand on la diminue à 0, et le mute
     */
   return -1; //Retour par défaut tant que la fonction n'est pas programmée et pour éviter les bugs de compilation
}

void MainWindow::setVolume(int volume)
{
    //A définir une fois que le système de messages sera établi et que le fonctionnement audio sera assimilé
}

void MainWindow::setPhase(phase p, bool on, int param) //A revoir
{
  switch(p)
  {
    case kPhasePlay:

      break;
    case kPhasePause:

      break;
    case kPhaseMute:

      break;
    case kPhaseSound:

      break;
  }
}

void MainWindow::message(signalType sig, bool switchOn, int param1, int param2) //A revoir
{
    switch(sig)
    {
      case kSignalPhase:
        setPhase((phase)param1, switchOn, param2);
        break;
      default:
        break;
      }
}

