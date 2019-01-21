#ifndef RTSPHERE_H
#define RTSPHERE_H

#include <QObject>
#include <QVector3D>

class RtSphere : public QObject
{
    Q_OBJECT
public:
    explicit RtSphere(QObject *parent = nullptr);
    RtSphere(const QVector3D &center, float radius);

    QVector3D center() const;
    void setCenter(const QVector3D &center);

    float radius() const;
    void setRadius(float radius);

    bool rayIntersect(const QVector3D &origin, const QVector3D &direction, float &t) const;

signals:

public slots:

private:
    QVector3D   _center;
    float       _radius;
};

#endif // RTSPHERE_H
