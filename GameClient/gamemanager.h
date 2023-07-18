#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QObject>
#include <QDebug>
#include <websocketclient.h>
#include <messageprocessor.h>

class GameManager : public QObject
{
    Q_OBJECT
public:
    explicit GameManager(QObject *parent = nullptr);

public slots:
    Q_INVOKABLE void connectToServer() {m_client->connectToServer();}
    Q_INVOKABLE void onNewGameRequest() {m_msgProcessor->onNewGameRequest();}
    Q_INVOKABLE void onJoinGameRequest(size_t lobbyid) {m_msgProcessor->onJoinGameRequest(lobbyid);}
signals:

private:
    WebSocketClient *m_client;
    MessageProcessor *m_msgProcessor;
};

#endif // GAMEMANAGER_H
