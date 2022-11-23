#pragma once

#include <iostream>

struct Vector2 {
    int x = 0;
    int y = 0;

    Vector2();
    Vector2(int x, int y);

    friend std::ostream& operator<<(std::ostream& stream, const Vector2& vector);

    void Add(const Vector2& other);
    void Subtract(const Vector2& other);
    void Multiply(const Vector2& other);
    void Divide(const Vector2& other);

    Vector2& operator +(const Vector2& other);
    Vector2& operator -(const Vector2& other);
    Vector2& operator *(const Vector2& other);
    Vector2& operator /(const Vector2& other);
};

struct Vector3
{
    int x = 0;
    int y = 0;
    int z = 0;

    Vector3();
    Vector3(int x, int y, int z);

    friend std::ostream& operator<<(std::ostream &stream, const Vector3 &vector);

    void Add(const Vector3 &other);
    void Subtract(const Vector3 &other);
    void Multiply(const Vector3 &other);
    void Divide(const Vector3 &other);

    Vector3& operator +(const Vector3 &other);
    Vector3& operator -(const Vector3 &other);
    Vector3& operator *(const int other);
    Vector3& operator /(const int other);

};