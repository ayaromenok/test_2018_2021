//Copyrigth (C) 2019 Andrey Yaromenok
#include <QtCore>

#include "yuser.h"

YUser::YUser(QObject *parent) : QObject(parent),
    _id(0),
    _uName("")
{

}

void
YUser::setId(int id)
{
    if (id != _id){
        qInfo() << "id" << _id << id;
        _id = id;
        emit idChanged(_id);
    }
}

void
YUser::setUserName(QString uName)
{
    if (uName != _uName){
        qInfo() << "userName" << _uName << uName;
        _uName = uName;
        emit userNameChanged(_uName);
    }
}

void
YUser::dumpToConsole()
{
    qInfo() << _id << _uName;
}
