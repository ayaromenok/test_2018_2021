#include "rtsphere.h"
#include <cmath>

RtSphere::RtSphere(QObject *parent) : QObject(parent)
{

}

RtSphere::RtSphere(const QVector3D &center, float radius)
{
    setCenter(center);
    setRadius(radius);
}
QVector3D RtSphere::center() const
{
    return _center;
}

void RtSphere::setCenter(const QVector3D &center)
{
    _center = center;
}

float RtSphere::radius() const
{
    return _radius;
}

void RtSphere::setRadius(float radius)
{
    _radius = radius;
}

bool
RtSphere::rayIntersect(const QVector3D &origin, const QVector3D &direction, float &t) const
{
    QVector3D length = _center - origin;
    float tca = QVector3D::dotProduct( length, direction);
    float d2 =QVector3D::dotProduct(length,length) - tca*tca;
    if (d2 > _radius*_radius) {
        return false;
    }

    float thc = sqrtf(_radius*_radius - d2);
    t = tca - thc;
    float t1 = tca +thc;
    if (t < 0){
        t = t1;
    }
    if (t < 0) {
        return false;
    }
    return true;
}
