#pragma once

template<typename T, typename U>
class Vector {
private:
    T x;
    U y;
public:

    T getX();

    U getY();

    Vector(T x, U y);

    Vector(double magnitude);

    double magnitude();

    Vector<T, U> normalize();

    Vector<T, U> downVector();

    Vector<T, U> leftVector();

    Vector<T, U> oneVector();

    Vector<T, U> rightVector();

    Vector<T, U> upVector();

    Vector<T, U> zeroVector();

    static Vector<T, U> minVector(Vector<T, U>& Left, Vector<T, U>& Right);

    static Vector<T, U> maxVector(Vector<T, U>& Left, Vector<T, U>& Right);

    static double distanceVector(Vector<T, U>& Left, Vector<T, U>& Right);

    static Vector<T, U> scaleVector(Vector<T, U>& a, double choix);
    
    static Vector<T, U> perpendiculaireVector(Vector<T, U>& a, char choix);

    static Vector<T, U> reflectVector(Vector<T, U>& a, Vector<T, U>& normal);

    static double dotVector(Vector<T, U>& Left, Vector<T, U>& Right);

    static double detVector(Vector<T, U>& Left, Vector<T, U>& Right);

    static Vector<T, U> lerpVector(Vector<T, U>& Left, Vector<T, U>& Right, double t);

    static Vector<T, U> lerpClampedVector(Vector<T, U>& Left, Vector<T, U>& Right, double t);

    static double angleVector(Vector<T, U>& Left, Vector<T, U>& Right);

    static double signedAngleVector(Vector<T, U>& Left, Vector<T, U>& Right);
    
    static Vector<T, U> clampMagnitude(Vector<T, U>& a, double maxMagnitude);

    static Vector<T, U> smoothDamp(Vector<T, U>& target, Vector<T, U>& currentVelocity, double smoothTime, double maxSpeed, double deltaTime);

};

template<typename T, typename U>
Vector<T, U> operator+(Vector<T, U>& Left, Vector<T, U>& Right);

template<typename T, typename U>
Vector<T, U> operator-(Vector<T, U>& Left, Vector<T, U>& Right);

template<typename T, typename U>
Vector<T, U> operator*(const Vector<T, U>& Left, const double ascalar);

template<typename T, typename U>
Vector<T, U> operator/(const Vector<T, U>& Left, const double ascalar);



#include "Vector_math.inl"