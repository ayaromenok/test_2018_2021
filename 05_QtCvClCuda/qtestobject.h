// Copyright(C) 2018 Andrey Yaromenok, ayaromenok@gmail.com
// MIT License - https://github.com/ayaromenok/test/blob/master/LICENSE

#ifndef QTESTOBJECT_H
#define QTESTOBJECT_H

#include <QObject>

class QTestObject : public QObject
{
    Q_OBJECT
public:
    explicit QTestObject(QObject *parent = nullptr);
    void testCPU();
    void testCL();
    void testCUDA();
    void getCpuInfo();
    void getClInfo();
    void getCudaInfo();
signals:

public slots:

};

#endif // QTESTOBJECT_H
