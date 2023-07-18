#ifndef MESSAGEPROCESSOR_H
#define MESSAGEPROCESSOR_H

#include <QObject>

class MessageProcessor : public QObject
{
    Q_OBJECT
public:
    explicit MessageProcessor(QObject *parent = nullptr);

public slots:
    void onProcessMessage(const QString &str);
    void onNewGameRequest();
    void onJoinGameRequest(size_t lobbyid);
    void onSendMsgToChat(const QString);

signals:
    void connectionAllowed(size_t userid);
    void newGameCreated(size_t lobbyid);
    void joinGameAllowed();
    void messageReceived(const QString &msg, size_t userid);
    void sendMessage(const QString &str);
};

#endif // MESSAGEPROCESSOR_H
