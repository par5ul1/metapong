#pragma once

#include "Player.hpp"
#include "Ball.hpp"

class Ball;

class Opponent : public Player {
public:
    using Player::Player;
    void move(Ball &ball);
};
