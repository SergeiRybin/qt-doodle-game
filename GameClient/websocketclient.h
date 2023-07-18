#ifndef WEBSOCKETCLIENT_H
#define WEBSOCKETCLIENT_H

#include <QObject>
#include <QtWebSockets/QtWebSockets>

class WebSocketClient : public QObject
{
    Q_OBJECT
public:
    explicit WebSocketClient(QObject *parent = nullptr);
    void connectToServer();

public slots:
    void onSendMessage(const QString &msg);

private slots:
    void onConnected();
    void onDisconnected();
    void onTextMsgRecv(const QString &msg);

private:
    QWebSocket m_socket;
    static const QString m_url;
};

#endif // WEBSOCKETCLIENT_H
