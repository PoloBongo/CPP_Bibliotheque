#include "Header.h"
#include <iostream>
#include <cmath>
#include "../includes/Colision.h"
#include "../../GameObjectLib/GameObject.h"


int main() {
    CallLibFunction();
    Collider<float> circle(2.0f, 3.0f,1.0f);
    Collider<float> circle2(3.0f, 4.0f, 1.0f);


    if (circle.CheckCollisionCircle(circle2)) {
        std::cout << "Collision entre cercle" << std::endl;
    }
    Collider<float> square(4.0f, 5.0f, 1.0f);
    Collider<float> square2(7.0f, 6.5f, 1.0f);

    if (square.CheckCollisionSquare(square2)) {
        std::cout << "Collision entre carrés !" << std::endl;
    }
    if (circle.CheckCollision_Cir_Squ(square2)) {
        std::cout << "Collision entre cerle et carré !" << std::endl;
    }
    if (square.CheckCollision_Cir_Squ(circle2)) {
        std::cout << "Collision entre carré et cercle !" << std::endl;
    }

    GameObject enemy("Enemy", "Bot");

    std::cout << enemy.GetTag() << std::endl;
    std::cout << enemy.GetName() << std::endl;

    Component transform("TransformComponent");
    Component renderer("RendererComponent");
    enemy.AddComponent(&transform);
    enemy.AddComponent(&renderer);

    enemy.Update();

    return 0;
}