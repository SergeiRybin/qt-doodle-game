#include <QCoreApplication>
#include <gamemanager.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    GameManager manager;
    return a.exec();
}
