#include "ScoreBoard.hpp"

void ScoreBoard::update() {
    _window->clear();
    
    std::string score_text;
    
    if (GameStats::get_games_played() >= 10) {
        score_text = (GameStats::get_computer_wins() > GameStats::get_player_wins() ? "You lost!" : "You win!")
        + std::string(" (Press R to Restart or Q to Quit)") ;
    } else {
        score_text = std::to_string(GameStats::get_computer_wins()) + "        " + std::to_string(GameStats::get_player_wins());
    }
    
    SDL_Surface * surface = TTF_RenderText_Solid(_font, score_text.c_str(), {255, 255, 255, 255});
    
    _texture = SDL_CreateTextureFromSurface(_window->get_renderer(), surface);
    SDL_FreeSurface(surface);
    
    int w, h;
    int x, y;
    SDL_DisplayMode screen;
    SDL_GetCurrentDisplayMode(0, &screen);
    
    SDL_QueryTexture(_texture, NULL, NULL, &w, &h);
    _current_frame = {0, 0, w, h};
    
    SDL_GetWindowSize(_window->get_window(), &x, &y);
    x /= SCALE;
    y /= SCALE;
    x = (x - w)/2;
    y = (y - h)/2;
    
    set_position({static_cast<float>(x), static_cast<float>(y)});
    
    _window->render(*this);
    _window->display();
}
