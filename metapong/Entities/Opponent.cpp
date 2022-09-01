#include "Opponent.hpp"

void Opponent::move(Ball &ball) {
    
    // Keep the paddle velocity fixed and in the correct direction
    if ((get_position().y - PADDLE_WINDOW_OFFSET)/SCALE + BALL_SIZE > ball.get_position().y) {
        set_velocity({0, -PLAYER_SPEED});
    } else {
        set_velocity({0, PLAYER_SPEED});
    }
    
    // Update the position
    set_position({
        get_position().x + get_velocity().x,
        get_position().y + get_velocity().y
    });
    
    // Update the window itself
    SDL_SetWindowPosition(get_window()->get_window(), get_position().x, get_position().y);
}
