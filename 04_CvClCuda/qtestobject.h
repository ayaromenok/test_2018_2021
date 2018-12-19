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
    double testCPU(int scale = 1, bool isSaveResult = false, bool isShowInfo = false);
    double testCL(int scale = 1, bool isSaveResult = false, bool isShowInfo = false,
                  bool isShowCLInfo = false);
    bool testCUDA(int scale = 1, bool isSaveResult = false, bool isShowInfo = false);

signals:

public slots:

private:
    CvTestObject     *_cto;
};

#endif // QTESTOBJECT_H
