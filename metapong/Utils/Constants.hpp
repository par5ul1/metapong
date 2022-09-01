#pragma once

// XXX: This value is hardcoded.
extern int PADDLE_WINDOW_OFFSET;

const float DELTA_TIME = 10;

const int BALL_SIZE = 16;
const int PADDLE_W = 30;
const int PADDLE_H = 50;
const int FIELD_W = 640;
const int FIELD_H = 360;

const int SCALE = 2;
const float BALL_SPEED = 5;
const float PLAYER_SPEED = 10;
const float ACCELERATION = 1.1;

enum RoundOutcome {ROUND_LOST, ROUND_WON};
