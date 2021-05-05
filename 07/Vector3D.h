


//
// Created by Aljosha on 04.05.2021.
//

#ifndef OOP_VECTOR3D_H
#define OOP_VECTOR3D_H

class Vector3D {
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


#endif //OOP_VECTOR3D_H
