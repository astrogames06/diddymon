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
    std::vector<std::reference_wrapper<Entity>> entities;
    std::vector<Rectangle> obstacles;

    void Init();
    void Update();
    void Draw();
};

#endif