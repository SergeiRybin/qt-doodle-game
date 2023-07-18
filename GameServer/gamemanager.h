#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QObject>
#include <messagehandler.h>
#include <websockethandler.h>

class GameManager : public QObject
{
    Q_OBJECT
public:
    explicit GameManager(QObject *parent = nullptr);

signals:

private:
    WebSocketHandler *m_wsHandler;
    MessageHandler *m_msgHandler;
};

#endif // GAMEMANAGER_H
