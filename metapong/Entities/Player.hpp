#pragma once

#include "Entity.hpp"

class Player : public Entity {
public:
    using Entity::Entity;
    void move();
};
