//
// Created by faiskada on 15/10/2025.
//

#ifndef ENGIN_VECTOR2_H
#define ENGIN_VECTOR2_H
#include <type_traits>
#include <bits/valarray_after.h>

template<typename T>
class Vector2 {
#pragma region Vector2 Proxy
    class ComponentProxy {
        Vector2& parent;
        bool isX;
        
    public:
        ComponentProxy(const Vector2& parent, const bool isX) : parent(parent), isX(isX)
        {}

        explicit operator T() const {
            return this->isX ? parent.x : parent.y;
        }

        ComponentProxy& operator=(T val) {
            if (isX) parent.x = val;
            else parent.y = val;
            
            parent.length = std::sqrt(parent.x*parent.x + parent.y*parent.y);
            parent.squaredLength = parent.length * parent.length;
            
            return *this;
        }
    };
#pragma endregion
    
    static_assert(std::is_arithmetic_v<T>, "Vector2 must be arithmetic type.");
    T x, y;
    
    double length;
    double squaredLength;
public:
    ComponentProxy X, Y;
    
    const double* const Length = &length;
    const double* const SquaredLength = &squaredLength;
    
    Vector2(T x, T y) : x(x), y(y), X(*this, true), Y(*this, false) {
        this->length = std::sqrt(x*x + y*y);
        this->squaredLength = this->length * this->length;
    }

#pragma region Vector2 Transformations
    Vector2& normalize() {
        if (this->length > 0) {
            this->X = this->x / this->length;+
            this->Y = this->y / this->length;
        }

        return *this;
    }
    T dot(const Vector2& b) {
        return this->x * b.x + this->y * b.y;
    }
    T cross(const Vector2& b) {
        return this->x * b.y - this->y * b.x;
    }
#pragma endregion

#pragma region Vector2 to Vector2 Arithmetic Operators
    // addition
    Vector2& operator+=(const Vector2& b) {
        this->X += b.x;
        this->Y += b.y;
        
        return *this;
    }
    Vector2 operator+(const Vector2& b) const {
        return Vector2(*this) += b;
    }

    // subtraction
    Vector2& operator-=(const Vector2& b) {
        this->X -= b.x;
        this->Y -= b.y;
        

        return *this;
    }
    Vector2 operator-(const Vector2& b) const {
        return Vector2(*this) -= b;
    }

    // division
    Vector2& operator/=(const Vector2& b) {
        this->X /= b.x;
        this->Y /= b.y;

        return *this;
    }
    Vector2 operator/(const Vector2& b) const {
        return Vector2(*this) /= b;
    }

    // multiplication
    Vector2& operator*=(const Vector2& b) {
        this->X *= b.x;
        this->Y *= b.y;

        return *this;
    }
    Vector2 operator*(const Vector2& b) const {
        return Vector2(*this) *= b;
    }

    // assignment
    Vector2& operator=(const Vector2& b) {
        if (this != &b) {
            this->X = b.x;
            this->Y = b.y;
        }

        return *this;
    }
#pragma endregion

#pragma region Vector2 to Scalar Arithmetic Operators
    // division
    Vector2& operator/=(const T& b) {
        this->X /= b;
        this->Y /= b;
        
        return *this;
    }
    Vector2 operator/(const T& b) const {
        return Vector2(*this) /= b;
    }

    // multiplication
    Vector2& operator*=(const T& b) {
        this->X *= b;
        this->Y *= b;

        return *this;
    }
    Vector2 operator*(const T& b) const {
        return Vector2(*this) *= b;
    }
#pragma endregion

#pragma region Vector2 Logical Operators
    bool operator==(const Vector2& b) const {
        return (this->x == b.x) && (this->y == b.y);
    }
    bool operator!=(const Vector2& b) const {
        return !(*this == b);
    }

#pragma region Lexicographical Operators
    bool operator<(const Vector2& b) const {
        return (x < b.x) || (x == b.x && y < b.y);
    }
    bool operator>(const Vector2& b) const {
        return b < *this;
    }
    bool operator<=(const Vector2& b) const {
        return !(b < *this);
    }
    bool operator>=(const Vector2& b) const {
        return !(*this < b);
    }
#pragma endregion
    
#pragma region Length Operators
    bool length_equals_to(const Vector2& b) const {
        return this->length == b.length;
    }
    bool length_nequals_to(const Vector2& b) const {
        return this->length != b.length;
    }
    bool length_greater_than(const Vector2& b) const {
        return this->length > b.length;
    }
    bool length_less_than(const Vector2& b) const {
        return this->length < b.length;
    }
    bool length_gequal_to(const Vector2& b) const {
        return this->length >= b.length;
    }
    bool length_lequal_to(const Vector2& b) const {
        return this->length <= b.length;
    }
#pragma endregion
#pragma endregion
};


#endif //ENGIN_VECTOR2_H