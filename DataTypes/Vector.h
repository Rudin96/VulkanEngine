#pragma once

#include <iostream>

struct Vector2 
{
    float x = 0;
    float y = 0;

    Vector2();
    Vector2(float value);
    Vector2(float x, float y);

    friend std::ostream& operator<<(std::ostream& stream, const Vector2& vector);

    void Add(const Vector2& other);
    void Subtract(const Vector2& other);
    void Multiply(const Vector2& other);
    void Divide(const Vector2& other);
    void Divide(const float amount);

    Vector2& Normalize();

    float Magnitude();

    Vector2& operator +(const Vector2& other);
    Vector2& operator -(const Vector2& other);
    Vector2& operator *(const Vector2& other);
    Vector2& operator /(const Vector2& other);

    bool operator!=(const Vector2& other) const {
        return this->x != other.x || this->y != other.y;
    }

    bool operator==(const Vector2& other) const {
        return this->x == other.x && this->y == other.y;
    }
};

struct Vector3
{
    float x = 0;
    float y = 0;
    float z = 0;

    Vector3();
    Vector3(float x, float y, float z);

    friend std::ostream& operator<<(std::ostream &stream, const Vector3 &vector);

    void Add(const Vector3 &other);
    void Subtract(const Vector3 &other);
    void Multiply(const Vector3 &other);
    void Divide(const Vector3 &other);

    Vector3& operator +(const Vector3 &other);
    Vector3& operator -(const Vector3 &other);
    Vector3& operator *(const float other);
    Vector3& operator /(const float other);

    bool operator==(const Vector3& other) const {
        return this->x == other.x && this->y == other.y && this->z == other.z;
    }

};