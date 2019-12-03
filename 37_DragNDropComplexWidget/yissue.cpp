//Copyrigth (C) 2019 Andrey Yaromenok
#include <QtCore>

#include "yissue.h"

YIssue::YIssue(QObject *parent) : QObject(parent),
    _id(0),
    _iid(0),
    _user(0),
    _title(""),
    _body("")
{

}
void
YIssue::setId(int id)
{
    if (id != _id){
        qInfo() << "id" << _id << id;
        _id = id;
        emit idChanged(_id);
    }
}

void
YIssue::setIid(int iid)
{
    if (iid != _iid){
        qInfo() << "iid" << _iid << iid;
        _iid = iid;
        emit iidChanged(_iid);
    }
}

void
YIssue::setUser(int user)
{
    if (user != _user){
        qInfo() << "user" << _user << user;
        _user = user;
        emit userChanged(user);
    }
}
void
YIssue::setTitle(QString title)
{
    if (title != _title){
        qInfo() << "title" << _title << title;
        _title = title;
        emit titleChanged(_title);
    }
}
void
YIssue::setBody(QString body)
{
    if (body != _body){
        qInfo() << "body" << _body << body;
        _body = body;
        emit bodyChanged(_body);
    }
}

void
YIssue::dumpToConsole()
{
    qInfo() << _id << _iid << _user << _title << _body;
}
