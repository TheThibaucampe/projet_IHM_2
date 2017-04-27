#ifndef SERVEUR_H
#define SERVEUR_H

#include <QObject>
#include <QLocalServer>
#include <QTcpSocket>
#include <QLocalSocket>
#include <QtConcurrent/QtConcurrent>
#include <QVector>
#include <QTcpServer>

class Serveur: public QObject
{
    Q_OBJECT
public:
    explicit Serveur(QObject *parent = 0);
    ~Serveur();
    bool pause = false;

public slots :
    void newConnection();
    void disconnected();
    void readyRead();

    void play_f();
    void pause_f();
//    void pause_f();
    void chgtVolume(int value);
    void mute();
    void chgtMusique(QString Name);
    void avanceMusique();
    void reculeMusique();
    void chgtEndroitMusique(int time);

    bool writeData(QString dataString, QTcpSocket* socket);








    void cible();

private:
    QLocalSocket *mpv=NULL;
    QVector<QTcpSocket*> VClient;
    QTcpServer * m_server;
    bool m_running;
    bool mute_flag;


};

#endif // SERVEUR_H
