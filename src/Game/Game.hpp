#ifndef GAME_H
#define GAME_H

#include <raylib.h>
#include <vector>
#include "../Entity/Entity.hpp"

class Entity;

class Game
{
public:
    int WIDTH;
    int HEIGHT;
    std::vector<Entity> entities;

    void Init();
    void Update();
    void Draw();
};

#endif