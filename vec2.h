#ifndef VEC2_H
#define VEC2_H

typedef struct {
    double x, y;
} Vec2;

Vec2 addVec2(Vec2 a, Vec2 b);
Vec2 subVec2(Vec2 a, Vec2 b);
double magVec2(Vec2 a);
void normVec2(Vec2 *a);

#endif
