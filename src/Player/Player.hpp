#ifndef PLAYER_H
#define PLAYER_H

#include "../Entity/Entity.hpp"

class Player : public Entity
{
public:
    Vector2 position;

    void Init() override;
    void Update() override;
    void Draw() override;
};

#endif