#include <QtCore>
#include <QtNetwork>
#include "yrestapiprj.h"

YRestApiPrj::YRestApiPrj(QObject *parent) : QObject(parent)
{
    _mgr = new QNetworkAccessManager(this);
    _url.setUrl("https://gitlab.com/ayaromenok");
    _request = new QNetworkRequest(_url);
    //_request->setHeader(QNetworkRequest::ContentTypeHeader, "application/vnd.github.v3+json");
    //_request->setHeader(QNetworkRequest::ContentTypeHeader, "text/plain");
    _reply=_mgr->get(*_request);

    connect(_reply, SIGNAL(finished()), this, SLOT(parseReplyPrj()));
}

void YRestApiPrj::parseReplyPrj()
{
    QString response;
    if (_reply) {
        if (_reply->error() == QNetworkReply::NoError) {
            const int available = _reply->bytesAvailable();
            if (available > 0) {
                //const QByteArray buffer(_reply->readAll());
                //response = QString::fromUtf8(buffer);
                qDebug() << "response:" << _reply->readAll();//response;
            }
        } else {
            response = tr("Error: %1 status: %2").arg(_reply->errorString(), _reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toString());
            qDebug() << response;
        }

        _reply->deleteLater();
    }
}
