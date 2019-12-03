//Copyrigth (C) 2019 Andrey Yaromenok
#ifndef YISSUE_H
#define YISSUE_H

#include <QObject>

class YIssue : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(int iid READ iid WRITE setIid NOTIFY iidChanged)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString body READ body WRITE setBody NOTIFY bodyChanged)
    Q_PROPERTY(int user READ user WRITE setUser NOTIFY userChanged)
public:
    explicit YIssue(QObject *parent = nullptr);

    int id(){return _id;}
    int iid(){return _iid;}
    int user(){return _user;}
    QString title(){return _title;}
    QString body(){return _body;}

    void setId(int id);
    void setIid(int iid);
    void setUser(int user);
    void setTitle(QString title);
    void setBody(QString body);

    void dumpToConsole();
signals:
    void idChanged(int);
    void iidChanged(int);
    void userChanged(int);
    void titleChanged(const QString &newTitle);
    void bodyChanged(const QString &bodyTitle);

private:
    int         _id;
    int         _iid;
    int         _user;
    QString     _title;
    QString     _body;

};

#endif // YISSUE_H
