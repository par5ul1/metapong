#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <array>

#include "Entity.hpp"
#include "Constants.hpp"
#include "ScoreBoard.hpp"

class Entity;
class ScoreBoard;

class RenderWindow {
    SDL_Window *_window;
    SDL_Renderer *_renderer;
public:
    RenderWindow(const char *title, int width, int height);
    SDL_Texture *loadTexture(const char *file_path);
    void clear();
    void render(Entity &entity);
    void render_fill(Entity &entity);
    void render(ScoreBoard &board);
    void display();
    void destroy();
    SDL_Window *get_window() {return _window;}
    SDL_Renderer *get_renderer() {return _renderer;}
};
