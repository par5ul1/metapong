#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char *title, int w, int h) : _window(nullptr), _renderer(nullptr) {
    _window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
    
    if (_window == nullptr) {
        std::cout << "Failed to create window. Error: " << SDL_GetError() << std::endl;
    }
    
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    if (_renderer == nullptr) {
        std::cout << "Failed to create renderer. Error: " << SDL_GetError() << std::endl;
    }
}

SDL_Texture *RenderWindow::loadTexture(const char *file_path) {
    SDL_Texture *texture = nullptr;
    texture = IMG_LoadTexture(_renderer, file_path);
    
    if (texture == nullptr) {
        std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;
    }
    
    return texture;
}

void RenderWindow::clear() {
    SDL_RenderClear(_renderer);
}

void RenderWindow::render(Entity &entity) {
    SDL_Rect src = entity.get_current_frame();
    SDL_Rect dst = {
        static_cast<int>(entity.get_position().x) * SCALE,
        static_cast<int>(entity.get_position().y) * SCALE,
        entity.get_current_frame().w * SCALE,
        entity.get_current_frame().h * SCALE
    };
    
    SDL_RenderCopy(_renderer, entity.get_texture(), &src, &dst);
}

void RenderWindow::render_fill(Entity &entity) {
    
    int w, h;
    SDL_GetWindowSize(_window, &w, &h);
    
    SDL_Rect src = entity.get_current_frame();
    SDL_Rect dst = {
        0,
        0,
        w,
        h
    };

    SDL_RenderCopy(_renderer, entity.get_texture(), &src, &dst);
}

void RenderWindow::render(ScoreBoard &board) {
    SDL_Rect src = board.get_current_frame();
    SDL_Rect dst = {
        static_cast<int>(board.get_position().x) * SCALE,
        static_cast<int>(board.get_position().y) * SCALE,
        board.get_current_frame().w * SCALE,
        board.get_current_frame().h * SCALE
    };
    
    SDL_RenderCopy(_renderer, board.get_texture(), &src, &dst);
}

void RenderWindow::display() {
    SDL_RenderPresent(_renderer);
}

void RenderWindow::destroy() {
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
}
