#ifndef RADIOFILE_H
#define RADIOFILE_H

#include <QObject>

/* Afin de attribuer des propriétés à un état, il faut attribuer un Q_Object auquel
 * nous associons des propriétés, d'où le rôle de radiofile.
 */

class radiofile : public QObject
{
    Q_OBJECT
public:
    //Constructeur / Destructeur
    radiofile();
    ~radiofile();

    //Propriétés
    QString url;    //URL de la radio
    QString name;   //Nom de la radio
    bool play;      //Flag indiquant que la chaine radio est jouée
    int volume;     //Volume
    bool mute;      //Falg indiquant que la chaine radio est mutée

    //Get & Set
    QString get_url();
    QString get_name();
    bool get_play();
    int get_volume();
    bool get_mute();

    void set_url(QString u);
    void set_name(QString n);
    void set_play(bool p);
    void set_volume(int v);
    void set_mute(bool m);
};
#endif // RADIOFILE_H
