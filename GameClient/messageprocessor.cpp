#include "messageprocessor.h"
#include <QJsonObject>
#include <QJsonDocument>
#include "../common/common.h"

MessageProcessor::MessageProcessor(QObject *parent)
    : QObject{parent}
{

}

void MessageProcessor::onProcessMessage(const QString &str)
{

}

void MessageProcessor::onNewGameRequest()
{
    QJsonObject jsonObj;
    jsonObj["type"] = MessageType::NEWGAME;
    QJsonDocument doc(jsonObj);
    QString strJson(doc.toJson(QJsonDocument::Compact));
    emit sendMessage(strJson);
}

void MessageProcessor::onJoinGameRequest(size_t lobbyid)
{
    QJsonObject jsonObj;
    jsonObj["type"] = MessageType::JOINGAME;
    jsonObj["lobbyid"] = static_cast<double>(lobbyid);
    QJsonDocument doc(jsonObj);
    QString strJson(doc.toJson(QJsonDocument::Compact));
    emit sendMessage(strJson);
}

void MessageProcessor::onSendMsgToChat(const QString)
{

}
