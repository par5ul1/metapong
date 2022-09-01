#pragma once

class GameStats {
    static int _games_played;
    static int _player_wins;
    static int _computer_wins;
public:
    GameStats(int games_played, int player_wins, int computer_wins) {
        _games_played = games_played;
        _player_wins = player_wins;
        _computer_wins = computer_wins;
    };
    GameStats() : GameStats(0, 0, 0) {};
    static int get_games_played() {return _games_played;}
    static int get_player_wins() {return _player_wins;}
    static int get_computer_wins() {return _computer_wins;}
    
    static void set_games_played(int num) {_games_played = num;}
    static void set_player_wins(int num) {_player_wins = num;}
    static void set_computer_wins(int num) {_computer_wins = num;}
    
    void inc_games_played() {++_games_played;}
    void inc_player_wins() {++_player_wins;}
    void inc_computer_wins() {++_computer_wins;}
};
