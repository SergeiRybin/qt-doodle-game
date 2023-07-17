#include "websockethandler.h"

WebSocketHandler::WebSocketHandler(QObject *parent)
    : QObject{parent}, rndGen(QDateTime::currentMSecsSinceEpoch())
{
    m_server = new QWebSocketServer("Game server", QWebSocketServer::NonSecureMode, this);
    connect(m_server, &QWebSocketServer::newConnection, this, &WebSocketHandler::onConnect);
//    connect(m_server, &QWebSocketServer::closed, this, &WebSocketHandler::onDisconnect);
    m_server->listen(QHostAddress::Any, 8282);
}

void WebSocketHandler::onConnect()
{
    qDebug() << "Server: Connection established";
    QWebSocket *sock = m_server->nextPendingConnection();
    connect(sock, &QWebSocket::textMessageReceived, this, &WebSocketHandler::onMessageReceived);
    connect(sock, &QWebSocket::disconnected, this, &WebSocketHandler::onDisconnect);
    QString id;
    while (QString::number(rndGen.bounded(idMin, idMax)) && !m_sockets.contains(id))
    {
        m_sockets[id] = sock;
    }
}

void WebSocketHandler::onDisconnect()
{
    qDebug() << "Server: Connection is interrupted";
    QWebSocket *client = qobject_cast<QWebSocket *>(sender());
    if (client)
    {
        m_sockets.removeAll(client);
        client->deleteLater();
    }

}

void WebSocketHandler::onMessageReceived(QString msg)
{
    qDebug() << "Server: Message received : " << msg;
}
