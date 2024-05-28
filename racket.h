#ifndef RACKET_H
#define RACKET_H

typedef struct {
    int x, y, len;
    double vel;
    char *sprite;
} Racket;

void drawRacket(WINDOW *w, Racket r);
void moveUp(Racket *r, double dt, int height);
void moveDown(Racket *r, double dt, int height);

#endif
