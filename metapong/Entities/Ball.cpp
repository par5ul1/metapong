#include "Ball.hpp"

int PADDLE_WINDOW_OFFSET;

// Generates a new velocity Vector2. The magnitude is defined by speed.
Vector2<float> Ball::_generate_new_velocity(float speed) {
    float angle = 0;
    Vector2<float> new_velocity = {0, 0};
    while (fabs(cos(angle)) <= 0.6 || fabs(cos(angle)) >= 0.9) {
        angle = static_cast <float> (rand()) / static_cast <float> (RAND_MAX/(2*M_PI));
        new_velocity = {
            speed * cos(angle),
            speed * sin(angle)
        };
    }
    return new_velocity;
}

// Checks collisions against top and bottom walls
void Ball::_do_wall_collisions() {
    int y = get_position().y;

    if (y < 0 || y > FIELD_H - BALL_SIZE) {
        set_velocity({
            get_velocity().x,
            get_velocity().y * -1
        });
    }
}

void Ball::_do_player_collision(Player &player) {
    int x = get_position().x;
    int y = get_position().y;
    
    int player_y = (player.get_position().y - PADDLE_WINDOW_OFFSET)/SCALE;
    
    if (x > FIELD_W) {
        _stats.inc_computer_wins();
        _stats.inc_games_played();
        reset();
        _board->update();
    }
    
    if (x > FIELD_W - BALL_SIZE && y >= player_y - BALL_SIZE && y <= player_y + PADDLE_H) {
        Vector2<float> new_velocity = _generate_new_velocity(magnitude(get_velocity()));
        set_velocity({
            new_velocity.x * (new_velocity.x > 0 ? -1 : 1) * ACCELERATION,
            new_velocity.y * ACCELERATION
        });
    }
}

void Ball::_do_opponent_collision(Opponent &opponent) {
    int x = get_position().x;
    int y = get_position().y;
    
    int opponent_y = (opponent.get_position().y - PADDLE_WINDOW_OFFSET)/SCALE;
    
    if (x < -BALL_SIZE) {
        _stats.inc_player_wins();
        _stats.inc_games_played();
        reset();
        _board->update();
    }
    
    if (x < 0 && y >= opponent_y - BALL_SIZE && y <= opponent_y + PADDLE_H) {
        Vector2<float> new_velocity = _generate_new_velocity(magnitude(get_velocity()));
        set_velocity({
            new_velocity.x * (new_velocity.x < 0 ? -1 : 1) * ACCELERATION,
            new_velocity.y * ACCELERATION
        });
    }
}

void Ball::move(Player &player, Opponent &opponent) {
    // Handle collisions
    _do_wall_collisions();
    _do_player_collision(player);
    _do_opponent_collision(opponent);
    
    set_position({
        get_position().x + get_velocity().x * BALL_SPEED,
        get_position().y + get_velocity().y * BALL_SPEED
    });
}

void Ball::reset() {
    set_position({(FIELD_W - BALL_SIZE)/2, (FIELD_H - BALL_SIZE)/2});
    set_velocity(_generate_new_velocity(1));
}
