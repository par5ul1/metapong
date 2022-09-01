#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "GameStats.hpp"
#include "RenderWindow.hpp"
#include "Math.hpp"
#include "Constants.hpp"

class RenderWindow;

class ScoreBoard {
    RenderWindow *_window;
    SDL_Rect _current_frame;
    TTF_Font *_font;
    SDL_Texture *_texture;
    Vector2<float> _position;
public:
    ScoreBoard(TTF_Font* font, RenderWindow *window) : _font(font), _window(window), _texture(nullptr), _current_frame({0, 0, 0, 0}), _position({0, 0}) {};
    
    void set_position(Vector2<float> position) {_position = position;}
    void set_current_frame(SDL_Rect current_frame) {_current_frame = current_frame;}
    void set_texture(SDL_Texture *texture) {_texture = texture;}
    
    Vector2<float> get_position() {return _position;}
    SDL_Rect get_current_frame() {return _current_frame;}
    SDL_Texture *get_texture() {return _texture;}
    
    void update();
};
