#pragma once

#include "Entity.hpp"
#include "Player.hpp"
#include "Opponent.hpp"
#include "GameStats.hpp"
#include "ScoreBoard.hpp"

class Opponent;

class Ball : public Entity {
    GameStats _stats;
    ScoreBoard *_board;
    void _do_wall_collisions();
    void _do_player_collision(Player &player);
    void _do_opponent_collision(Opponent &opponent);
    void _update_score(RoundOutcome outcome);
    Vector2<float> _generate_new_velocity(float speed);
public:
    Ball(Vector2<float> position, Vector2<float> velocity, SDL_Texture *texture, ScoreBoard *board, RenderWindow *window) : Entity(position, velocity, texture, window), _board(board) {};
    Ball(Vector2<float> position, SDL_Texture *texture, ScoreBoard *board, RenderWindow *window) : Ball(position, _generate_new_velocity(1), texture, board, window) {};
    
    void move(Player &player, Opponent &opponent);
    void reset();
};
