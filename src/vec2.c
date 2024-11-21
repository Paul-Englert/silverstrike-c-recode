#include "../include/vec2.h"

#include <math.h>

Vec2 Vec2_Add(Vec2 v1, Vec2 v2) {
    return (Vec2) {v1.x + v2.x, v1.y + v2.y};
}

Vec2 Vec2_Sub(Vec2 v1, Vec2 v2) {
    return (Vec2) {v1.x - v2.x, v1.y - v2.y};
}

Vec2 Vec2_Mult(Vec2 v, float factor) {
    return (Vec2) {v.x * factor, v.y * factor};
}

Vec2 Vec2_Div(Vec2 v, float div) {
    return (Vec2) {v.x / div, v.y / div};
}

Vec2 Vec2_Normalize(Vec2 v) {
    return Vec2_Div(v, Vec2_Magnitude(v));
}

float Vec2_DotP(Vec2 v1, Vec2 v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

float Vec2_Magnitude(Vec2 v) {
    return sqrtf((float)(v.x*v.x + v.y*v.y));
}

float Vec2_Magnitude_Sq(Vec2 v) {
    return v.x*v.x + v.y*v.y;
}

void m_Vec2_Add(Vec2 *v, Vec2 add) {
    v->x += add.x;
    v->y += add.y;
}

void m_Vec2_Sub(Vec2 *v, Vec2 sub) {
    v->x -= sub.x;
    v->y -= sub.y;
}

void m_Vec2_Mult(Vec2 *v, float factor) {
    v->x *= factor;
    v->y *= factor;
}

void m_Vec2_Div(Vec2 *v, float div) {
    v->x /= div;
    v->y /=div;
}

void m_Vec2_Normalize(Vec2 *v) {
    m_Vec2_Div(v, Vec2_Magnitude(*v));
}