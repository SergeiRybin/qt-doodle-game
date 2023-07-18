#include "gamemanager.h"

GameManager::GameManager(QObject *parent)
    : QObject{parent}
{
    m_client = new WebSocketClient(this);
    m_msgProcessor = new MessageProcessor(this);
    connect(m_msgProcessor, &MessageProcessor::sendMessage, m_client, &WebSocketClient::onSendMessage);
}
