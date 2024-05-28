#include <stdio.h>
#include <math.h>
#include <ncurses.h>
#include "racket.h"

void drawRacket(WINDOW *w, Racket r) {
    int i;
    for (i = 0; i < r.len; i++) {
        mvwprintw(w, r.y+i, r.x, "%s", r.sprite);
    }
}

void moveUp(Racket *r, double dt, int height) {
    if (0 < r->y)
        r->y -= ceil(dt * r->vel);
}

void moveDown(Racket *r, double dt, int height) {
    if ((r->y + r->len) < height)
        r->y += ceil(dt * r->vel);
}
