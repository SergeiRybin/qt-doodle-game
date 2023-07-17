#ifndef WEBSOCKETHANDLER_H
#define WEBSOCKETHANDLER_H

#include <QObject>
#include <QtWebSockets/QWebSocketServer>
#include <QtWebSockets/QtWebSockets>

class WebSocketHandler : public QObject
{
    Q_OBJECT
public:
    explicit WebSocketHandler(QObject *parent = nullptr);

private slots:
    void onConnect();
    void onDisconnect();
    void onMessageReceived(QString);

private:
    static const quint32 idMin = 1000;
    static const quint32 idMax = 9999;
    QWebSocketServer *m_server;
    QMap<QString, QWebSocket *> m_sockets;
    QRandomGenerator rndGen;
};

#endif // WEBSOCKETHANDLER_H
