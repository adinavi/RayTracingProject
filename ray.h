#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class Ray {
public:
    Vec3 origin, direction;

    Ray() {}
    Ray(const Vec3 &origin, const Vec3 &direction) : origin(origin), direction(direction) {}

    Vec3 at(double t) const {
        return origin + direction * t;
    }
};

#endif
