#ifndef ENTITY_H
#define ENTITY_H

#include "../Game/Game.hpp"

class Entity
{
public:
    virtual ~Entity() = default;

    virtual void Init();
    virtual void Update();
    virtual void Draw(); 
};

#endif