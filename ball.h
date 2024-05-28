#ifndef BALL_H
#define BALL_H

#include "vec2.h"
#include <ncurses.h>

typedef struct {
    Vec2 vel;
    double x, y;
    char *sprite;
} Ball;

void bounce(Ball *b);
void drawBall(WINDOW *win, Ball b);
void updateBall(Ball *b, double dt, int width, int height);

#endif
