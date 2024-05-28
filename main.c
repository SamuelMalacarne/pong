#include <stdio.h>
#include <locale.h>
#include <sys/time.h>
#include <unistd.h>
#include <ncurses.h>
#include "vec2.h"
#include "ball.h"
#include "racket.h"

#define WIDTH 60
#define HEIGHT 17

#define MARGIN 5

#define DELAY 5000

double getDeltaTime(struct timeval* last_time) {
    struct timeval current_time;
    gettimeofday(&current_time, NULL);

    double delta_time = (current_time.tv_sec - last_time->tv_sec) * 1000.0; // sec to ms
    delta_time += (current_time.tv_usec - last_time->tv_usec) / 1000.0; // us to ms

    *last_time = current_time;
    return delta_time;
}

bool handleCollisionRacketBall(Racket r, Ball *b) {
    if ((((double)r.x - 0.2) <= b->x && b->x <= ((double)r.x + 0.2)) && ((double)r.y <= b->y && b->y <= (double)(r.y + r.len))) {
        b->vel.x *= -1.0;    
    }
}

void resetBall(Ball *b) {
    b->x = WIDTH/2.0;
    b->y = HEIGHT/2.0;
}

int main() {

    setlocale(LC_ALL, "");

    double deltaTime;
    int input, scorePlayer1 = 0, scorePlayer2 = 0;
    WINDOW *window;
    Ball ball = { .vel = {.x = 0.02, .y = 0.01 }, .x = 10, .y = 10, .sprite = "●" };
    Racket p1 = { .vel = 0.05, .x = 5, .y = (HEIGHT/2) + MARGIN, .sprite = "▕", .len = 4 };
    Racket p2 = { .vel = 0.05, .x = WIDTH - 5, .y = (HEIGHT/2) + MARGIN, .sprite = "▎", .len = 4 };
    
    struct timeval lastTime;

    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    window = newwin(HEIGHT, WIDTH, 0, 0);
    
    gettimeofday(&lastTime, NULL);

    while (1) {

        deltaTime = getDeltaTime(&lastTime);
     
        drawBall(window, ball);
        updateBall(&ball, deltaTime, WIDTH, HEIGHT);
        handleCollisionRacketBall(p1, &ball);
        handleCollisionRacketBall(p2, &ball);

        if (ball.x < MARGIN) {
            resetBall(&ball);
            scorePlayer2++;
        } else if (ball.x > WIDTH - MARGIN) {
            resetBall(&ball);
            scorePlayer1++;
        }

        drawRacket(window, p1);
        drawRacket(window, p2);

        mvwprintw(window, 0, WIDTH/2 - 2, "%2d - %2d", scorePlayer1, scorePlayer2);

        mvprintw(HEIGHT+1, 0, "fps: %.2f      ", 1000/deltaTime);
        
        wrefresh(window);
        werase(window);

        input = getch();
        switch (input) {
            case KEY_UP:
                moveUp(&p2, deltaTime, HEIGHT);
            break;

            case KEY_DOWN:
                moveDown(&p2, deltaTime, HEIGHT);
            break;
            
            case 'w':
                moveUp(&p1, deltaTime, HEIGHT);
            break;

            case 's':
                moveDown(&p1, deltaTime, HEIGHT);
            break;
        }

        usleep(DELAY);        
    }

    endwin();     

    return 0;
}
