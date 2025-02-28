#ifndef PLAYER_H
#define PLAYER_H

#include "../Entity/Entity.hpp"

class Player : public Entity
{
public:
    Vector2 velocity;
    const int PLAYER_SIZE = 50;
    const float MOVE_SPEED = 200.0f;

    void Init() override;
    void Update() override;
    void Draw() override;
};

#endif