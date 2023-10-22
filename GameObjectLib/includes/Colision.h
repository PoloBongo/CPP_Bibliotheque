#pragma once
#include <iostream>
#include <cmath>

template <typename T>
class Collider {
public:
    Collider(T x, T y, T radius) : x(x), y(y), radius(radius) {}

    // Méthode pour vérifier la collision avec un autre collider
    template < typename U>
    bool CheckCollisionCircle(Collider<U>& other) {
        if (std::is_same<T, U>::value) {

            // Les deux objets sont des cercles
            float distance = sqrt(pow(x - other.GetX(), 2) + pow(y - other.GetY(), 2));
            return distance < (static_cast<float>(*this) + static_cast<float>(other));

        }
    }
    template < typename U>

    bool CheckCollisionSquare(Collider<U>& other) {
        if (std::is_same<T, U>::value) {

            // Les deux objets sont des carrés
            float halfWidth1 = static_cast<float>(*this) / 2.0f;
            float halfWidth2 = static_cast<float>(other) / 2.0f;

            float left1 = x - halfWidth1;
            float right1 = x + halfWidth1;
            float top1 = y - halfWidth1;
            float bottom1 = y + halfWidth1;

            float left2 = other.GetX() - halfWidth2;
            float right2 = other.GetX() + halfWidth2;
            float top2 = other.GetY() - halfWidth2;
            float bottom2 = other.GetY() + halfWidth2;

            return (right1 >= left2 && left1 <= right2 && bottom1 >= top2 && top1 <= bottom2);
        }


    }

    template < typename U>
    bool CheckCollision_Cir_Squ(Collider<U>& other) {
        // Les objets sont de types différents (carré-cercle)
        if (std::is_same<T, float>::value) {
            // L'objet this est un cercle et l'autre objet est un carré
            float halfWidth = static_cast<float>(other) / 2.0f;
            float halfHeight = halfWidth;
            float left = other.GetX() - halfWidth;
            float right = other.GetX() + halfWidth;
            float top = other.GetY() - halfHeight;
            float bottom = other.GetY() + halfHeight;

            float closestX = std::max(left, std::min(x, right));
            float closestY = std::max(top, std::min(y, bottom));

            float distance = sqrt(pow(x - closestX, 2) + pow(y - closestY, 2));
            return distance < static_cast<float>(*this);
        }
        else {
            // L'objet this est un carré et l'autre objet est un cercle
            float halfWidth = static_cast<float>(*this) / 2.0f;
            float halfHeight = halfWidth;
            float left = x - halfWidth;
            float right = x + halfWidth;
            float top = y - halfHeight;
            float bottom = y + halfHeight;

            float closestX = std::max(left, std::min(other.GetX(), right));
            float closestY = std::max(top, std::min(other.GetY(), bottom));

            float distance = sqrt(pow(other.GetX() - closestX, 2) + pow(other.GetY() - closestY, 2));
            return distance < static_cast<float>(other);
        }
    }
    T GetX() const { return x; }
    T GetY() const { return y; }
    T GetRadius() const { return radius; }


    operator float() {
        return static_cast<float>(this->radius);
    }

private:
    T x;
    T y;
    T radius;
};

