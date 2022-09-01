#include "GameManager.hpp"

void GameManager::play() {
    SDL_Event event;

    // Timestepping setup
    float current_time = SDL_GetTicks();
    
    int player_x, player_y;

    while (_running) {

        float new_time = SDL_GetTicks();
        float frame_time = new_time - current_time;
        current_time = new_time;

        _accumulator += frame_time;

        while (_accumulator >= DELTA_TIME) {
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT || event.window.event == SDL_WINDOWEVENT_CLOSE) {
                    _running = false;
                }

                if (event.type == SDL_KEYDOWN) {
                    SDL_GetWindowPosition(_player.get_window()->get_window(), &player_x, &player_y);
                    switch (event.key.keysym.scancode) {
                        case SDL_SCANCODE_UP:
                            _player.set_velocity({0, -PLAYER_SPEED});
                            break;
                        case SDL_SCANCODE_DOWN:
                            _player.set_velocity({0, PLAYER_SPEED});
                            break;
                        case SDL_SCANCODE_R:
                            restart();
                            break;
                        case SDL_SCANCODE_Q:
                            _running = false;
                            break;
                        default:
                            break;
                    }
                }

                if (event.type == SDL_KEYUP) {
                    SDL_GetWindowPosition(_player.get_window()->get_window(), &player_x, &player_y);
                    switch (event.key.keysym.scancode) {
                        case SDL_SCANCODE_UP:
                            _player.set_velocity({0, 0});
                            break;
                        case SDL_SCANCODE_DOWN:
                            _player.set_velocity({0, 0});
                            break;
                        default:
                            break;
                    }
                }
            }

            _accumulator -= DELTA_TIME;

        }

        _ball.get_window()->clear();
        _ball.get_window()->render(_ball);
        _ball.get_window()->display();
        
        _player.get_window()->clear();
        _player.get_window()->render_fill(_player);
        _player.get_window()->display();
        
        _opponent.get_window()->clear();
        _opponent.get_window()->render_fill(_opponent);
        _opponent.get_window()->display();

        _ball.move(_player, _opponent);
        _opponent.move(_ball);
        _player.move();
    }
}

void GameManager::restart() {
    GameStats::set_games_played(0);
    GameStats::set_player_wins(0);
    GameStats::set_computer_wins(0);
    _board.update();
    
    _ball.reset();
    _player.reset();
    _opponent.reset();
}
