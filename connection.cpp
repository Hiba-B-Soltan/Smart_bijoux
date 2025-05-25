#include "connection.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
connection::connection()
{

}
bool connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");


db.setDatabaseName("sourceprojet2A");//inserer le nom de la source de données ODBC
db.setUserName("yousef");//inserer nom de l'utilisateur
db.setPassword("147896325");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

    return  test;
}
