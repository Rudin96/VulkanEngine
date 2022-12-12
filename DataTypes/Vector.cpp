#include "Vector.h"

Vector3::Vector3()
{
    x = 0.f;
    y = 0.f;
    z = 0.f;
};

Vector3::Vector3(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

void Vector3::Subtract(const Vector3 &other)
{
    this->x -= other.x;
    this->y -= other.y;
    this->z -= other.z;
}

void Vector3::Add(const Vector3 &other)
{
    this->x += other.x;
    this->y += other.y;
    this->z += other.z;
}

void Vector3::Multiply(const Vector3 &other)
{
    this->x *= other.x;
    this->y *= other.y;
    this->z *= other.z;
}

void Vector3::Divide(const Vector3& other)
{
    this->x /= other.x;
    this->y /= other.y;
    this->z /= other.z;
}

Vector3& Vector3::operator+(const Vector3 &other)
{
    this->Add(other);
    return (*this);
}

Vector3& Vector3::operator-(const Vector3 &other)
{
    this->Subtract(other);
    return (*this);
}

Vector3& Vector3::operator*(const float other)
{
    this->Multiply(Vector3(other, other, other));
    return (*this);
}

Vector3& Vector3::operator/(const float other)
{
    this->Divide(Vector3(other, other, other));
    return *this;
}

std::ostream& operator<<(std::ostream& stream, const Vector2& vector)
{
    stream << "X: " << vector.x << " Y: " << vector.y;
    return stream;
}

std::ostream& operator<<(std::ostream &stream, const Vector3 &vector)
{
    stream << "X: " << vector.x << " Y: " << vector.y << " Z: " << vector.z;
    return stream;
}

Vector2::Vector2()
{
    x = 0.f;
    y = 0.f;
}

Vector2::Vector2(float value)
{
    this->x, this->y = value;
}

Vector2::Vector2(float x, float y)
{
    this->x = x;
    this->y = y;
}

void Vector2::Subtract(const Vector2& other)
{
    this->x -= other.x;
    this->y -= other.y;
}

void Vector2::Add(const Vector2& other)
{
    this->x += other.x;
    this->y += other.y;
}

void Vector2::Multiply(const Vector2& other)
{
    this->x *= other.x;
    this->y *= other.y;
}

void Vector2::Divide(const Vector2& other)
{
    this->x /= other.x;
    this->y /= other.y;
}

Vector2& Vector2::operator+(const Vector2& other)
{
    this->Add(other);
    return *this;
}

Vector2& Vector2::operator-(const Vector2& other)
{
    this->Subtract(other);
    return *this;
}

Vector2& Vector2::operator*(const Vector2& other)
{
    this->Multiply(other);
    return *this;
}

Vector2& Vector2::operator/(const Vector2& other)
{
    this->Multiply(other);
    return *this;
}
