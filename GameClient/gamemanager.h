#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QObject>
#include <QDebug>

class GameManager : public QObject
{
    Q_OBJECT
public:
    explicit GameManager(QObject *parent = nullptr);

public slots:
    Q_INVOKABLE void clicked(QString str) {qDebug() << "Button clicked: " << str;}

signals:

};

#endif // GAMEMANAGER_H
