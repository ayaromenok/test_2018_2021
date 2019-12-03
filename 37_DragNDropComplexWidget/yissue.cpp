//Copyrigth (C) 2019 Andrey Yaromenok
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
        _id = id;
        emit idChanged(id);
    }
}

void
YIssue::setIid(int iid)
{
    if (iid != _iid){
        _iid = iid;
        emit iidChanged(iid);
    }
}

void
YIssue::setUser(int user)
{
    if (user != _user){
        _user = user;
        emit userChanged(user);
    }
}
void
YIssue::setTitle(QString title)
{
    if (title != _title){
        _title = title;
        emit titleChanged(_title);
    }
}
void
YIssue::setBody(QString body)
{
    if (body != _body){
        _body = body;
        emit bodyChanged(_body);
    }
}
