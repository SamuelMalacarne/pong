#include <stdio.h>
#include <math.h>
#include "vec2.h"

Vec2 addVec2(Vec2 a, Vec2 b) {
    Vec2 new;
    new.x = a.x + b.x;
    new.y = a.y + b.y;
}

Vec2 subVec2(Vec2 a, Vec2 b) {
    Vec2 new;
    new.x = a.x - b.x;
    new.y = a.y - b.y;
}

double magVec2(Vec2 a) {
    return sqrt(a.x * a.x + a.y * a.y); 
}

void normVec2(Vec2 *a) {
    double m = magVec2(*a);
    a->x /= m;
    a->y /= m;
}

// vec2 multvec2(vec2 a, vec2 b) {
//     vec2 new;
//     new.x = a.x * b.x;
//     new.y = a.y * b.y;
// }
// 
// vec2 divvec2(vec2 a, vec2 b) {
//     vec2 new;
//     new.x = a.x / b.x;
//     new.y = a.y / b.y;
// }
