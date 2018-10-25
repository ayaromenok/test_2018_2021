// Copyright(C) 2018 Andrey Yaromenok, ayaromenok@gmail.com
// MIT License - https://github.com/ayaromenok/OpenCVwithQt/blob/master/LICENSE

#ifndef QCVOBJECT_H
#define QCVOBJECT_H

#include <QObject>

class QCvObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qint64 testCPU READ testCPU WRITE setTestCPU NOTIFY testCPUChanged)
    Q_PROPERTY(qint64 testCL READ testCL WRITE setTestCL NOTIFY testCLChanged)
public:
    explicit QCvObject(QObject *parent = nullptr);
    ~QCvObject();

signals:
    void testCPUChanged(qint64 value);
    void testCLChanged(qint64 value);
public slots:
    qint64 testCPU();
    qint64 testCL();
    void setTestCL(qint64 value);
    void setTestCPU(qint64 value);

private:
    void perfTest(bool bCL, bool bCuda, int count);
    void perfSuperResTest(bool bCL, bool bCuda, int count);

    qint64             _testCPU;
    qint64             _testCL;
    qint64             _testVal;
};

#endif // QCVOBJECT_H
