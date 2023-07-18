#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include <QObject>

class MessageHandler : public QObject
{
    Q_OBJECT
public:
    explicit MessageHandler(QObject *parent = nullptr);

public slots:
    void processMessage(const QString &str, size_t userid);
    void allowUser(size_t userid, size_t lobbyid);

signals:
    void newGameRequest(size_t id);
    void joinGameRequest(size_t lobbbyid);
    void sendMessage(const QString &str, size_t userid);
    void messageReceived(const QString &msg);
};

#endif // MESSAGEHANDLER_H
