#include "Entity.hpp"

Entity::Entity(Vector2<float> position, Vector2<float> velocity, SDL_Texture *texture, RenderWindow *window) : _position(position), _intial_position(position), _velocity(velocity), _initial_velocity(), _texture(texture), _window(window) {
    int w, h;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    _current_frame = {0, 0, w, h};
}
