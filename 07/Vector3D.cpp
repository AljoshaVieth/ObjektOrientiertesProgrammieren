//
// Created by Aljosha on 04.05.2021.
//
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


}

