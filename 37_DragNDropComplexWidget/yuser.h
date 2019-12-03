//Copyrigth (C) 2019 Andrey Yaromenok
#ifndef YUSER_H
#define YUSER_H

#include <QObject>

class YUser : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)

public:
    explicit YUser(QObject *parent = nullptr);
    int id(){return _id;}
    void setId(int id);
    QString userName(){return _uName;}
    void setUserName(QString uName);
    void dumpToConsole();
signals:
     void idChanged(int);
     void userNameChanged(const QString &newUserName);

private:
    int             _id;
    QString         _uName;
};

#endif // YUSER_H
