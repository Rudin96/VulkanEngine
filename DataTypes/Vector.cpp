#include "Vector.h"

Vector3::Vector3()
{
    x = 0;
    y = 0;
    z = 0;
};

Vector3::Vector3(int x, int y, int z)
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

Vector3& Vector3::operator*(const int other)
{
    this->Multiply(Vector3(other, other, other));
    return (*this);
}

Vector3& Vector3::operator/(const int other)
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
}

Vector2::Vector2(int x, int y)
{
}

void Vector2::Add(const Vector2& other)
{
}

void Vector2::Subtract(const Vector2& other)
{
}

void Vector2::Multiply(const Vector2& other)
{
}

void Vector2::Divide(const Vector2& other)
{
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
