#include "connection.h"


Connection::Connection(){}

bool Connection::createconnection()
{
    db=QSqlDatabase::addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("Gestion_Produit");
    db.setUserName("amani");
    db.setPassword("amani");

    if(db.open()) test=true;

    return test;

}

void Connection:: closeConnection(){db.close();}
