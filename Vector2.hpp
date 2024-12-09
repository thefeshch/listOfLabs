#ifndef VECTOR2_H
#define VECTOR2_H

#include <iostream>

struct Vector2 {
    float x;
	float y;

    bool operator==(const Vector2& other) const;
    Vector2& operator+=(const Vector2& other);
    Vector2& operator-=(const Vector2& other);
    Vector2& operator*=(float a);
    Vector2& operator/=(float a);

    float& operator[](int index);
    const float& operator[](int index) const;
};

Vector2 operator+(const Vector2& v, const Vector2& w);
Vector2 operator-(const Vector2& v, const Vector2& w);
Vector2 operator*(float a, const Vector2& v);
Vector2 operator*(const Vector2& v, float a);
Vector2 operator/(const Vector2& v, float a);

std::ostream& operator<<(std::ostream& ostr, const Vector2& v);

#endif 