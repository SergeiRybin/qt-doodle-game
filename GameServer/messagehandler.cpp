#include "messagehandler.h"
#include <QJsonObject>
#include <QJsonDocument>
#include "../common/common.h"

MessageHandler::MessageHandler(QObject *parent)
    : QObject{parent}
{

}

void MessageHandler::processMessage(const QString &str, size_t userid)
{
    qDebug() << "Message received: " << str;
    auto doc = QJsonDocument::fromJson(str.toUtf8());
    if (!doc.isNull() && !doc.isEmpty())
    {
        if (doc.isObject())
        {
            QJsonObject jsonObj = doc.object();
            const QJsonValue type = jsonObj["type"];
            const QJsonValue lobbyid = jsonObj["lobbyid"];
            const QJsonValue text = jsonObj["text"];
            if (type == MessageType::NEWGAME)
            {
                emit newGameRequest(userid);
            }
            else if (type == MessageType::JOINGAME && lobbyid.isDouble())
            {
                emit joinGameRequest(lobbyid.toInt());
            }
            else if (type == MessageType::MESSAGE && text.isString())
            {
                emit messageReceived(text.toString());
            }
            else
            {
                qDebug() << "JSON data is invalid";
            }

        }
        else
        {
            qDebug() << "Document is not an object";
            return;
        }
    }
    else
    {
        qDebug() << "Document is not a valid JSON";
        return;
    }
}

void MessageHandler::allowUser(size_t userid, size_t lobbyid)
{
    QJsonObject jsonObj;
    jsonObj["type"] = MessageType::ALLOWJOIN;
    jsonObj["lobbyid"] = static_cast<double>(lobbyid);
    QJsonDocument doc(jsonObj);
    QString strJson(doc.toJson(QJsonDocument::Compact));
    emit sendMessage(strJson, userid);
}
