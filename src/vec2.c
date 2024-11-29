#include "../include/vec2.h"

#include <math.h>

static float PI = 3.14159265359;

static float Deg2Rad(float degrees) {
    return degrees * (PI/180);
}

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

Vec2 Vec2_Rotate(Vec2 v, float angle) {
    float rad = Deg2Rad(angle);
    float cos = cosf(rad), sin = sinf(rad);
    return (Vec2) {cos*v.x - sin*v.y, sin*v.x + cos*v.y};
}

float Vec2_DotP(Vec2 v1, Vec2 v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

float Vec2_Magnitude(Vec2 v) {
    return sqrtf(v.x*v.x + v.y*v.y);
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

void m_Vec2_Rotate(Vec2 *v, float angle) {
    float rad = Deg2Rad(angle);
    float cos = cosf(rad), sin = sinf(rad);
    Vec2 current = *v;
    v->x = cos*current.x - sin*current.y;
    v->y = sin*current.x + cos*current.y;
}

float Vec2_GetAngle(Vec2 v1, Vec2 v2) {
    float dotp = Vec2_DotP(v1, v2);
    float m1 = Vec2_Magnitude(v1), m2 = Vec2_Magnitude(v2);
    float cos = dotp / (m1 * m2);
    return acosf(cos);
}

Vec2 Quad_Center(Quad *quad) {
    Vec2 vec = {0};
    for (char i = 0; i < 4; ++i) {
        m_Vec2_Add(&vec, quad->points[i]);
    }
    return Vec2_Div(vec, 4);
}

void Quad_Move(Quad *quad, Vec2 vec) {
    for (char i = 0; i < 4; ++i) {
        m_Vec2_Add(&quad->points[i], vec);
    }
}

void Quad_Rotate(Quad *quad, Vec2 origin, float angle) {
    for (char i = 0; i < 4; ++i) {
        Vec2 delta = Vec2_Sub(quad->points[i], origin);
        m_Vec2_Rotate(&delta, angle);
        quad->points[i] = Vec2_Add(delta, origin);
    }
}

void Quad_Scale(Quad *quad, Vec2 origin, float factor) {
    for (char i = 0; i < 4; ++i) {
        Vec2 delta = Vec2_Sub(quad->points[i], origin);
        m_Vec2_Mult(&delta, factor);
        quad->points[i] = Vec2_Add(delta, origin);
    }
}