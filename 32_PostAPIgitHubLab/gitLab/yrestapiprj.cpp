#include <QtCore>
#include <QtNetwork>
#include "yrestapiprj.h"
//#include <QtNetworkAuth>

YRestApiPrj::YRestApiPrj(QObject *parent) : QObject(parent)
{
    _mgr = new QNetworkAccessManager(this);

    _url.setUrl("https://gitlab.com/api/v4/projects/15163048/issues");
    _request = new QNetworkRequest(_url);
    _request->setHeader(QNetworkRequest::ContentTypeHeader, "zHQ12Wpr7cyzdfZ_xMwsan");
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
                const QByteArray buffer(_reply->readAll());
                //response = QString::fromUtf8(buffer);
                //qDebug() << "response:" << buffer;//response;
                QJsonDocument jdoc = QJsonDocument::fromJson(buffer);

                if (jdoc.isObject()){
                    qDebug() << "jdoc is a object";
                } else {
                    qDebug() << "jdoc is NOT a object";
                }
                if (jdoc.isArray()){
                    qDebug() << "jdoc is a array";
                    QJsonArray jarray = jdoc.array();

                    for (int i=0; i < jarray.size(); ++i){
                        QJsonObject jObj = jarray[i].toObject();
                        //qDebug() << i << jObj;
                        if (jObj.contains("title"))
                            qDebug() << "issue title" << jObj["title"].toString();
                        if (jObj.contains("created_at"))
                            qDebug() << "issue created" << jObj["created_at"].toString();
                        if (jObj.contains("closed_by")){
                            qDebug() << "closed by return jObject - user";
                            QJsonObject jUser = jObj["closed_by"].toObject();
                            if (jUser.contains("username"))
                                qDebug() << "issue created by :" << jUser["username"].toString();
                            if (jUser.contains("name"))
                                qDebug() << "issue created by :" << jUser["name"].toString();
                        }
                    }

                } else {
                    qDebug() << "jdoc is NOT a array";
                }


            }
        } else {
            response = tr("Error: %1 status: %2").arg(_reply->errorString(), _reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toString());
            qDebug() << response;
        }

        _reply->deleteLater();
    }
}
