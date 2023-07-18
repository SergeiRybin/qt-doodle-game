#include "websocketclient.h"

const QString WebSocketClient::m_url = "ws://127.0.0.1:8282";

WebSocketClient::WebSocketClient(QObject *parent)
    : QObject{parent}
{
    connect(&m_socket, &QWebSocket::connected, this, &WebSocketClient::onConnected);
    connect(&m_socket, &QWebSocket::disconnected, this, &WebSocketClient::onDisconnected);
}

void WebSocketClient::onConnected()
{
    qDebug() << "Client connected";
}

void WebSocketClient::onDisconnected()
{
    qDebug() << "Client disconnected";
}

void WebSocketClient::onTextMsgRecv(const QString &msg)
{
    qDebug() << "Message received: " << msg;
}

void WebSocketClient::connectToServer()
{
    connect(&m_socket, &QWebSocket::textMessageReceived, this, &WebSocketClient::onTextMsgRecv);
    m_socket.open(QUrl(m_url));
}

void WebSocketClient::onSendMessage(const QString &msg)
{
    // TODO: check if we  connected to the server
    m_socket.sendTextMessage(msg);
}
