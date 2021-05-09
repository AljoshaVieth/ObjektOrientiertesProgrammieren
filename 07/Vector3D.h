#ifndef OOP_VECTOR3D_H
#define OOP_VECTOR3D_H

class Vector3D {
#include <ostream>
private:
    const float x, y, z;
public:
    Vector3D(float x, float y, float z);

    float get_x() const;

    float get_y() const;

    float get_z() const;

    Vector3D operator+(const Vector3D &other);

    Vector3D operator-(const Vector3D &other);

    Vector3D operator-(); // negation

    float operator*(const Vector3D &other);

};

std::ostream &operator<<(std::ostream &out, const Vector3D vector3D);

Vector3D operator*(const float &multiplier, const Vector3D &vector3D);

Vector3D operator*(const Vector3D &vector3D, const float &multiplier);

#endif //OOP_VECTOR3D_H
