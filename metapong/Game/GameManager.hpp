#pragma once

#include "Entity.hpp"
#include "Ball.hpp"
#include "Player.hpp"
#include "Opponent.hpp"
#include "Constants.hpp"
#include "GameStats.hpp"
#include "ScoreBoard.hpp"

class GameManager {
    ScoreBoard _board;
    Ball _ball;
    Player _player;
    Opponent _opponent;
    
    float _accumulator = 0;
    
    bool _running = true;
public:
    GameManager(ScoreBoard &board, Ball &ball, Player &player, Opponent &opponent) : _board(board), _ball(ball), _player(player), _opponent(opponent) {};
    void play();
    void restart(); // TODO: Reset positions, do play() again with the same info.
};
