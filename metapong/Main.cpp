#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <array>
#include <ctime>
#include <cmath>
#include <random>

#include "GameManager.hpp"
#include "ScoreBoard.hpp"
#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Ball.hpp"
#include "Player.hpp"
#include "Opponent.hpp"
#include "Constants.hpp"

int main() {
    
    // Begin RNG
    srand((unsigned int) time(nullptr));
    rand();
    
    // SDL Inits
    if (SDL_Init(SDL_INIT_VIDEO)) {
        std::cout << "SDL_Init() ran into an error. Error: " << SDL_GetError() << std::endl;
    }
    
    if (!IMG_Init(IMG_INIT_PNG)) {
        std::cout << "IMG_Init() ran into an error. Error: " << SDL_GetError() << std::endl;
    }
    
    if (TTF_Init()) {
        std::cout << "TTF_Init() ran into an error. Error: " << SDL_GetError() << std::endl;
    }
    
    SDL_DisplayMode screen;
    SDL_GetCurrentDisplayMode(0, &screen);
    
    // Create Windows
    RenderWindow field_window("", FIELD_W * SCALE, FIELD_H * SCALE);
    RenderWindow hud_window("Meta Pong", (FIELD_W - 50) * SCALE, (screen.h - FIELD_H * SCALE)/4);
    RenderWindow player_window("", PADDLE_W * SCALE, PADDLE_H * SCALE);
    RenderWindow opponent_window("", PADDLE_W * SCALE, PADDLE_H * SCALE);
    
    // Get the locations of all the windows
    int field_x, field_y;
    int player_x, player_y;
    int opponent_x, opponent_y;
    
    SDL_GetWindowPosition(field_window.get_window(), &field_x, &field_y);
    PADDLE_WINDOW_OFFSET = field_y;
    
    SDL_SetWindowPosition(hud_window.get_window(), SDL_WINDOWPOS_CENTERED, field_y - FIELD_H * SCALE);
    
    SDL_SetWindowPosition(player_window.get_window(), field_x + FIELD_W * SCALE, SDL_WINDOWPOS_CENTERED);
    SDL_GetWindowPosition(player_window.get_window(), &player_x, &player_y);
    
    SDL_SetWindowPosition(opponent_window.get_window(), field_x - PADDLE_W * SCALE, SDL_WINDOWPOS_CENTERED);
    SDL_GetWindowPosition(opponent_window.get_window(), &opponent_x, &opponent_y);
    
    // Load Textures
    SDL_Texture *ball_texture = field_window.loadTexture("Assets/ball.png");
    SDL_Texture *player_texture = player_window.loadTexture("Assets/paddle.png");
    SDL_Texture *opponent_texture = opponent_window.loadTexture("Assets/paddle.png");
    
    // Load Fonts
    TTF_Font *font = TTF_OpenFont("Assets/cmu.ttf", 16);
    
    ScoreBoard board(font, &hud_window);
    board.update();
    
    // Create Entities
    Ball ball({(FIELD_W - BALL_SIZE)/2, (FIELD_H - BALL_SIZE)/2}, ball_texture, &board, &field_window);
    Player player({static_cast<float>(player_x), static_cast<float>(player_y)}, player_texture, &player_window);
    Opponent opponent({static_cast<float>(opponent_x), static_cast<float>(opponent_y)}, opponent_texture, &opponent_window);
    
    // Have the manager take care of the main loop
    GameManager game(board, ball, player, opponent);
    game.play();
    
    // Cleanup
    field_window.destroy();
    hud_window.destroy();
    player_window.destroy();
    opponent_window.destroy();
    
    SDL_Quit();
    IMG_Quit();
    TTF_Quit();
    
    return 0;
}
