#ifndef QTESTOBJECT_H
#define QTESTOBJECT_H

#include <QObject>
class CvTestObject;

class QTestObject : public QObject
{
    Q_OBJECT
public:
    explicit QTestObject(QObject *parent = nullptr);
    ~QTestObject();
    bool testCPU();
    bool testCL();
    bool testCUDA();

signals:

public slots:

private:
    CvTestObject     *_cto;
};

#endif // QTESTOBJECT_H
