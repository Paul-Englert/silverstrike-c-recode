#ifndef _VEC2_H_
#define _VEC2_H_

typedef struct {
    float x, y;
} Vec2;

//functions
//functions prefixed with 'm' take their first argument via pointer and mutate that vector rather than returning a new one

//Vec2 functions

Vec2 Vec2_Add(Vec2 v1, Vec2 v2);

Vec2 Vec2_Sub(Vec2 v1, Vec2 v2);

Vec2 Vec2_Mult(Vec2 v, float factor);

Vec2 Vec2_Div(Vec2 v, float div);

Vec2 Vec2_Normalize(Vec2 v);

Vec2 Vec2_Rotate(Vec2 v, float angle);

float Vec2_DotP(Vec2 v1, Vec2 v2);

float Vec2_Magnitude(Vec2 v);

float Vec2_Magnitude_Sq(Vec2 v);

void m_Vec2_Add(Vec2 *v, Vec2 add);

void m_Vec2_Sub(Vec2 *v, Vec2 sub);

void m_Vec2_Mult(Vec2 *v, float factor);

void m_Vec2_Div(Vec2 *v, float div);

void m_Vec2_Normalize(Vec2 *v);

void m_Vec2_Rotate(Vec2 *v, float angle);

float Vec2_GetAngle(Vec2 v1, Vec2 v2);

#endif // _VEC2_H_
