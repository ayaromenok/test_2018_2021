#ifndef YRESTAPIPRJ_H
#define YRESTAPIPRJ_H

#include <QObject>
#include <QUrl>
class QNetworkAccessManager;
class QNetworkRequest;
class QNetworkReply;

class YRestApiPrj : public QObject
{
    Q_OBJECT
public:
    explicit YRestApiPrj(QObject *parent = nullptr);

signals:

public slots:
    void parseReplyPrj();

private:
    QNetworkAccessManager   *_mgr;
    QNetworkReply           *_reply;
    QNetworkRequest         *_request;
    QUrl                    _url;
};

#endif // YRESTAPIPRJ_H
