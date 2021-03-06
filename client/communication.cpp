#include "communication.h"
#include <QTcpSocket>
#include <QDataStream>
#include <QJsonObject>
#include <QJsonDocument>
#include <QMainWindow>
#include "mainwindow.h"

Communication::Communication():
    m_socket(new QTcpSocket(this))
{
    if(!connectToHost("localhost"))
    {
        connected = false;
        qDebug() << "Fail connexion to serveur";
    }
    else
        connected =true;
}

bool Communication::connectToHost (QString host)
{
    m_socket->connectToHost(host,3000);
    connect(m_socket, SIGNAL(readyRead()), SLOT(readyRead()));
    return m_socket->waitForConnected();
}

//se deconnect du serveur
void Communication::deconnexion()
{
    writeData(QString::fromStdString("deconnexion ") + QString::number(id));

    m_socket->~QTcpSocket();
    m_socket=NULL;
    connected = false;

}

bool Communication::writeData(QString dataString)
{
    qDebug()<< dataString;
    QJsonObject jsonObject;
    jsonObject["txt"] = dataString;
    QByteArray bytes = QJsonDocument(jsonObject).toJson(QJsonDocument::Compact);


    if(m_socket->state() == QAbstractSocket::ConnectedState)
    {
        m_socket->write(bytes); //write the data itself
        return m_socket->waitForBytesWritten();
    }
    else
        return false;
}

QString Communication::readyRead()
{
    QTcpSocket *socket = static_cast<QTcpSocket*>(sender());
    QByteArray *buffer = new QByteArray();
    QJsonParseError error;
    QJsonDocument jDoc;
    QJsonObject jsonObject;
    while (socket->bytesAvailable() > 0)
    {
        buffer->append(socket->readAll());
        jDoc = QJsonDocument::fromJson(*buffer, &error);
        jsonObject = jDoc.object();

        QStringList L = jsonObject.value("txt").toString().split(" ");
        if ( ! (L[0].compare("move")  == 0))
            qDebug() << "Le message envoyé est " + jsonObject.value("txt").toString();

        if( L[0].compare("identifiant") == 0)
        {
            bool ok;
            id = L[1].toInt(&ok,10);
            qDebug() << QString::fromStdString("J'ai reçu l'id ") + L[1];
        }
        else if( L[0].compare("play") == 0)
        {
            qDebug() << "play" ;
        }
        else if( L[0].compare("pause") == 0)
        {
            qDebug() << "pause" ;
        }
        else if( L[0].compare("setVolume") == 0)
        {
            qDebug() << "setVolume" ;
        }
        else if ( L[0].compare("mute") == 0)
        {
            qDebug() << "mute";
        }
        else if ( L[0].compare("initInfo") == 0)
        {
            qDebug() << "initInfo";
        }
        else if ( L[0].compare("playList") == 0)
        {
            qDebug() << "playList";
        }
        else if( L[0].compare("previous") == 0)
        {
            qDebug() << "previous";
        }
        else if( L[0].compare("forward") == 0)
        {
            qDebug() << "forward";
        }
        else if( L[0].compare("move") == 0)
        {
            qDebug() << "move";
        }
        else
        {
            qDebug() << "aucune correspondance trouvée";
            qDebug() << L[0];
        }
        emit orderToWindow(jsonObject.value("txt").toString());
    }
    return jsonObject.value("txt").toString();
}
