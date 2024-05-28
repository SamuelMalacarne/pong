#include <stdio.h>
#include <ncurses.h>
#include "ball.h"

void bounce(Ball *b) {
    b->vel.x *= -1;
}

void drawBall(WINDOW *win, Ball b) {
    mvwprintw(win, (int)b.y, (int)b.x, "%s", b.sprite);
    wrefresh(win);
}

void checkWallCollision(Ball *b, int width, int height) {
    if (b->x >= width || b->x <= 0) b->vel.x *= -1;
    if (b->y >= height || b->y <= 0) b->vel.y *= -1;
}

void updateBall(Ball *b, double dt, int width, int height) {
    b->x += dt * b->vel.x;
    b->y += dt * b->vel.y;
    checkWallCollision(b, width, height);
}
