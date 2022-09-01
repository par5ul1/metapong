#include "Player.hpp"

void Player::move() {
    
    // Update the position
    set_position({
        get_position().x + get_velocity().x,
        get_position().y + get_velocity().y
    });
    
    // Update the window itself
    SDL_SetWindowPosition(get_window()->get_window(), get_position().x, get_position().y);
}
