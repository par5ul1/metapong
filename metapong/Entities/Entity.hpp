#pragma once

#include <SDL2/SDL.h>
#include <iostream>
#include <array>
#include <ctime>
#include <cmath>
#include <random>

#include "RenderWindow.hpp"
#include "Math.hpp"
#include "Constants.hpp"

class RenderWindow;

class Entity {
    RenderWindow *_window;
    Vector2<float> _position;
    const Vector2<float> _intial_position;
    Vector2<float> _velocity;
    const Vector2<float> _initial_velocity;
    SDL_Rect _current_frame;
    SDL_Texture *_texture;
public:
    Entity(Vector2<float> position, Vector2<float> velocity, SDL_Texture *texture, RenderWindow *window);
    Entity(Vector2<float> position, SDL_Texture *texture, RenderWindow *window) : Entity(position, {0, 0}, texture, window) {};
    
    void set_window(RenderWindow *window) {_window = window;}
    void set_position(Vector2<float> position) {_position = position;}
    void set_velocity(Vector2<float> velocity) {_velocity = velocity;}
    void set_current_frame(SDL_Rect current_frame) {_current_frame = current_frame;}
    void set_texture(SDL_Texture *texture) {_texture = texture;}
    virtual void reset() {_position = _intial_position; _velocity = _initial_velocity;}
    
    RenderWindow *get_window() {return _window;}
    Vector2<float> get_position() {return _position;}
    Vector2<float> get_velocity() {return _velocity;}
    SDL_Rect get_current_frame() {return _current_frame;}
    SDL_Texture *get_texture() {return _texture;}
    
};
