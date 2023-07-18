#include "gamemanager.h"

GameManager::GameManager(QObject *parent)
    : QObject{parent}
{
    m_wsHandler = new WebSocketHandler(this);
    m_msgHandler = new MessageHandler(this);
    connect(m_wsHandler, &WebSocketHandler::messageReceived, m_msgHandler, &MessageHandler::messageReceived);
}
