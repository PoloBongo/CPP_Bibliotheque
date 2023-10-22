#pragma once

#include "Vector_math.h"
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <cstdint>
#include <iomanip>
#include <algorithm>


template<typename T, typename U>
T Vector<T, U>::getX() {
    return x;
}

template<typename T, typename U>
U Vector<T, U>::getY() {
    return y;
}
template<typename T, typename U>
Vector<T, U>::Vector(T x, U y) : x(x), y(y) {}

template<typename T, typename U>
Vector<T, U>::Vector(double magnitude) {
    x = static_cast<T>(magnitude);
    y = static_cast<U>(magnitude);
}

template<typename T, typename U>
double Vector<T, U>::magnitude() {
    return std::sqrt(x * x + y * y);
}

template<typename T, typename U>
Vector<T, U> Vector<T, U>::downVector() {
    return Vector<T, U>(0.-1);
}

template<typename T, typename U>
Vector<T, U> Vector<T, U>::leftVector() {
    return Vector<T, U>(-1. 0);
}

template<typename T, typename U>
Vector<T, U> Vector<T, U>::oneVector() {
    return Vector<T, U>(1. 1);
}
template<typename T, typename U>
Vector<T, U> Vector<T, U>::rightVector() {
    return Vector<T, U>(1. 0);
}

template<typename T, typename U>
Vector<T, U> Vector<T, U>::upVector() {
    return Vector<T, U>(0. 1);
}


template<typename T, typename U>
Vector<T, U> Vector<T, U>::zeroVector() {
    return Vector<T, U>(0. 0);
}


template<typename T, typename U>
Vector<T, U> Vector<T, U>::normalize() {
    double length = magnitude();
    if (length == 0) {
        return Vector<T, U>(0, 0);
    }
    return Vector<T, U>(x / length, y / length);
}

template<typename T, typename U>
Vector<T, U> Vector<T, U>::minVector(Vector<T, U>& Left, Vector<T, U>& Right) {
    T nouveauX;
    U nouveauY;
    if (Left.x < Right.x) {
        nouveauX = Left.x;
    }
    else {
        nouveauX = Right.x;
    }

    if (Left.y < Right.y) {
        nouveauY = Left.y;
    }
    else {
        nouveauY = Right.y;
    }

    return Vector<T, U>(nouveauX, nouveauY);
}

template<typename T, typename U>
Vector<T, U> Vector<T, U>::maxVector(Vector<T, U>& Left, Vector<T, U>& Right) {
    T nouveauX;
    U nouveauY;
    if (Left.x > Right.x) {
        nouveauX = Left.x;
    }
    else {
        nouveauX = Right.x;
    }

    if (Left.y > Right.y) {
        nouveauY = Left.y;
    }
    else {
        nouveauY = Right.y;
    }

    return Vector<T, U>(nouveauX, nouveauY);
}

template<typename T, typename U>
Vector<T, U> Vector<T, U>::perpendiculaireVector(Vector<T, U>& a, char choix) {
    T nouveauX = a.x;
    U nouveauY = a.y;

    if (choix == 'x') {
        nouveauX = -a.x;
    }
    else if (choix == 'y') {
        nouveauY = -a.y;
    }

    return Vector<T, U>(nouveauX, nouveauY);
}

template<typename T, typename U>
Vector<T, U> Vector<T, U>::reflectVector(Vector<T, U>& a, Vector<T, U>& normal) {
    Vector<T, U> newNormal = normal.normalize();
    float dotProduct = 2 * dotVector(a, newNormal);
    return Vector<T, U>(a.x - dotProduct * newNormal.x, a.y - dotProduct * newNormal.y);
}

template<typename T, typename U>
double Vector<T, U>::dotVector(Vector<T, U>& Left, Vector<T, U>& Right) {
    double result = Left.x * Right.x + Left.y * Right.y;
    return result;
}

template<typename T, typename U>
double Vector<T, U>::detVector(Vector<T, U>& Left, Vector<T, U>& Right) {
    double result = Left.x * Right.y - Left.y * Right.x;
    return result;
}

template<typename T, typename U>
Vector<T, U> Vector<T, U>::lerpVector(Vector<T, U>& Left, Vector<T, U>& Right, double t) {
    t = std::max(0.0, std::min(1.0, t));
    double resultX = Left.x + t * (Right.x - Left.x);
    double resultY = Left.y + t * (Right.y - Left.y);
    return Vector<T, U>(resultX, resultY);
}

template<typename T, typename U>
Vector<T, U> Vector<T, U>::lerpClampedVector(Vector<T, U>& Left, Vector<T, U>& Right, double t) {
    t = std::clamp<double>(t, 0.0, 1.0);
    double resultX = Left.x + t * (Right.x - Left.x);
    double resultY = Left.y + t * (Right.y - Left.y);
    return Vector<T, U>(resultX, resultY);
}

template<typename T, typename U>
double Vector<T, U>::angleVector(Vector<T, U>& Left, Vector<T, U>& Right) {
    double dotProduct = dotVector(Left, Right);
    double leftNorm = Left.magnitude();
    double rightNorm = Right.magnitude();
    double angleRadians = std::acos(dotProduct / (leftNorm * rightNorm));
    double angleDegrees = angleRadians * 180.0 / 3.14159265358979323846;
    return angleDegrees;
}

template<typename T, typename U>
double Vector<T, U>::signedAngleVector(Vector<T, U>& Left, Vector<T, U>& Right) {
    double dotProduct = dotVector(Left, Right);
    double determinant = detVector(Left, Right);
    return std::atan2(determinant, dotProduct);
}

template<typename T, typename U>
Vector<T, U> Vector<T, U>::clampMagnitude(Vector<T, U>& a, double maxMagnitude) {
    double currentMagnitude = a.magnitude();
    if (currentMagnitude > maxMagnitude) {
        double scaleFactor = maxMagnitude / currentMagnitude;
        T newX = a.x * scaleFactor;
        U newY = a.y * scaleFactor;
        return Vector<T, U>(newX, newY);
    }
    return Vector<T, U>(a);
}

template<typename T, typename U>
Vector<T, U> Vector<T, U>::smoothDamp(Vector<T, U>& target, Vector<T, U>& currentVelocity, double smoothTime, double maxSpeed, double deltaTime) {
    Vector<T, U> delta = target - *this;
    double maxDelta = maxSpeed * smoothTime;

    Vector<T, U> targetVelocity = delta * (2.0 / smoothTime);
    targetVelocity = targetVelocity.clampMagnitude(targetVelocity, maxDelta);

    currentVelocity = (currentVelocity + targetVelocity * deltaTime).clampMagnitude(maxDelta);

    T resultX = x + currentVelocity.x * deltaTime;
    U resultY = y + currentVelocity.y * deltaTime;

    return Vector<T, U>(resultX, resultY);
}

template<typename T, typename U>
double Vector<T, U>::distanceVector(Vector<T, U>& Left, Vector<T, U>& Right) {
    Vector<T, U> result = Left - Right;
    return result.magnitude();
}

template<typename T, typename U>
Vector<T, U> Vector<T, U>::scaleVector(Vector<T, U>& a, double choix) {

    T nouveauX = a.x * choix;
    U nouveauY = a.y * choix;

    return Vector<T, U>(nouveauX, nouveauY);
}

template<typename T, typename U>
Vector<T, U> operator+(Vector<T, U> Left, Vector<T, U> Right) {
    T resultX = Left.x + Right.x;
    U resultY = Left.y + Right.y;
    return Vector<T, U>(resultX, resultY);
}

template<typename T, typename U>
Vector<T, U>operator-(Vector<T, U>& Left, Vector<T, U>& Right) {
    T nouveauX = Left.x - Right.x;
    U nouveauY = Left.y - Right.y;
    return Vector<T, U>(nouveauX, nouveauY);
};

template<typename T, typename U>
Vector<T, U> operator*(const Vector<T, U>& Left, const double &ascalar) {
    T resultX = Left.x * scalar;
    U resultY = Left.y * scalar;
    return Vector<T, U>(resultX, resultY);
}

template<typename T, typename U>
Vector<T, U> operator/(const Vector<T, U> &Left, const double &ascalar) {
    if (scalar != 0.0) {
        T resultX = Left.x / scalar;
        U resultY = Left.y / scalar;
        return Vector<T, U>(resultX, resultY);
    }
    return Vector<T, U>(0, 0); 
}
