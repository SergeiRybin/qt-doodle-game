#include <QCoreApplication>
#include <websockethandler.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    WebSocketHandler hndlr{};
    return a.exec();
}
