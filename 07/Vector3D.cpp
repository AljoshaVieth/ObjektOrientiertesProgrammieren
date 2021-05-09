//
// Created by Aljosha on 04.05.2021.
//
#include <ostream>
namespace hfu {


#include "Vector3D.h"

    Vector3D::Vector3D(float x, float y, float z) : x(x), y(y), z(z) {}

    float Vector3D::get_x() const {
        return x;
    }

    float Vector3D::get_y() const {
        return y;
    }

    float Vector3D::get_z() const {
        return z;
    }

    Vector3D Vector3D::operator+(const Vector3D &other) {
        return Vector3D(x + other.x, y + other.y, z + other.z);
    }

    Vector3D Vector3D::operator-(const Vector3D &other) {
        return Vector3D(x - other.x, y - other.y, z - other.z);
    }

    Vector3D Vector3D::operator-() {
        return Vector3D(-x, -y, -z);
    }

    float Vector3D::operator*(const Vector3D &other) {
        return x * other.x + y * other.y + z * other.z;
    }

    // Using getter methods instead of friend because they are needed anyway. A vector is useless hen it´s values are inaccessible
    std::ostream &operator<<(std::ostream &out, const Vector3D vector3D) {
        out << "(" << vector3D.get_x() << "," << vector3D.get_y() << "," << vector3D.get_z() << ")";
        return out;
    }

    Vector3D operator*(const float &multiplier, const Vector3D &vector3D) {
        return Vector3D(vector3D.get_x() * multiplier, vector3D.get_y() * multiplier, vector3D.get_z() * multiplier);
    }

    Vector3D operator*(const Vector3D &vector3D, const float &multiplier) {
        return operator*(multiplier, vector3D);
    }


}

