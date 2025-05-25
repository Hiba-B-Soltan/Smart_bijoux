#include "client.h"
#include "connection.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    client w;
    connection c;
    c.createconnect();
    w.show();
    return a.exec();
}
