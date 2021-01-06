#pragma once

#include <cmath>
#include <iostream>

using std::sqrt;

class Vector3
{
public:
    double elements[3];

    Vector3() : elements{0, 0, 0} {}
    Vector3(double e0, double e1, double e2) : elements{e0, e1, e2} {}

    double x() const { return elements[0]; }
    double y() const { return elements[1]; }
    double z() const { return elements[2]; }

    Vector3 operator-() const { return Vector3(-elements[0], -elements[1], -elements[2]); }
    double operator[](int i) const { return elements[i]; }
    double& operator[](int i) { return elements[i]; }

    Vector3& operator+=(const Vector3 &vec)
    {
        elements[0] += vec.elements[0];
        elements[1] += vec.elements[1];
        elements[2] += vec.elements[2];
        return *this;
    }

    Vector3& operator*=(const double t)
    {
        elements[0] *= t;
        elements[1] *= t;
        elements[2] *= t;
        return *this;
    }

    Vector3& operator/=(const double t) 
    {
        return *this *= 1 / t;
    }

    double length() const
    {
        return sqrt(length_squared());
    }

    double length_squared() const
    {
        return elements[0] * elements[0] + elements[1] * elements[1] + elements[2] * elements[2];
    }
};

//Type aliases
using Point3 = Vector3;    // 3D Point
using Color = Vector3;     // RGB Color

//Vector3 Utility Functions
inline std::ostream& operator<<(std::ostream &out, const Vector3 &vec)
{
    return out << vec.elements[0] << ' ' << vec.elements[1] << ' ' << vec.elements[2];
}

inline Vector3 operator+(const Vector3 &vecA, const Vector3 &vecB)
{
    return Vector3(vecA.elements[0] + vecB.elements[0], vecA.elements[1] + vecB.elements[1], vecA.elements[2] + vecB.elements[2]);
}

inline Vector3 operator-(const Vector3 &vecA, const Vector3 &vecB)
{
    return Vector3(vecA.elements[0] - vecB.elements[0], vecA.elements[1] - vecB.elements[1], vecA.elements[2] - vecB.elements[2]);
}

inline Vector3 operator*(const Vector3 &vecA, const Vector3 &vecB)
{
    return Vector3(vecA.elements[0] * vecB.elements[0], vecA.elements[1] * vecB.elements[1], vecA.elements[2] * vecB.elements[2]);
}

inline Vector3 operator*(double t, const Vector3 &vec)
{
    return Vector3(vec.elements[0] * t, vec.elements[1] * t, vec.elements[2] * t);
}

inline Vector3 operator*(const Vector3 &vec, double t)
{
    return t * vec;
}

inline Vector3 operator/(Vector3 vec, double t)
{
    return (1/t) * vec;
}

inline double dot(const Vector3 &vecA, const Vector3 &vecB)
{
    return vecA.elements[0] * vecB.elements[0]
        +  vecA.elements[1] * vecB.elements[1]
        +  vecA.elements[2] * vecB.elements[2];
}

inline Vector3 cross(const Vector3 &vecA, const Vector3 &vecB) {
    return Vector3(vecA.elements[1] * vecB.elements[2] - vecA.elements[2] * vecB.elements[1],
                   vecA.elements[2] * vecB.elements[0] - vecA.elements[0] * vecB.elements[2],
                   vecA.elements[0] * vecB.elements[1] - vecA.elements[1] * vecB.elements[0]);
}

inline Vector3 unit_vector(Vector3 vec)
{
    return vec / vec.length();
}