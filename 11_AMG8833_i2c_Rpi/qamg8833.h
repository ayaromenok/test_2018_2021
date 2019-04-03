#ifndef QAMG8833_H
#define QAMG8833_H

#include <QObject>

class QAMG8833 : public QObject
{
    Q_OBJECT
public:
    explicit QAMG8833(QObject *parent = nullptr);
    ~QAMG8833();

    void initI2C(int AMG8833 = 0x69);
    void initIR();
    void dumpData();
signals:

public slots:

private slots:
    float signed12bit2float(int value);
private:
    int 		fd_;
    int			rslt_;
};

#endif // QAMG8833_H
