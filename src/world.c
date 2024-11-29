#include "../include/world.h"
#include "../include/raylib.h"
#include "../include/vec2.h"

#include <stdbool.h>
#include <stdio.h>
#include <math.h>

#define _BEIGE (Color) {0xde, 0xe2, 0xe6, 0xFF}
#define _GREY (Color) {0x34, 0x3a, 0x40, 0xFF}

void RenderWorld(World *world) {
    //only testing for now
    //draws a chess board
    ClearBackground(RAYWHITE);
    DrawFPS(10,10);
    const int width = GetRenderWidth(), height = GetRenderHeight();
    //printf("height: %d, width %d\n", height, width);
    const int size = width/10;
    int y = -size*2, x = 0;
    bool flag = false;
    while (y < height + size*2) {
        int shift_x = (int)world->camera.pos.x % (2*size), shift_y = (int)world->camera.pos.y % (2*size);
        int index = flag ? 0 : 1;
        x = -size*2;
        while (x < width + size*2) {
            DrawRectangle(x + shift_x, y + shift_y, size, size, index%2 == 0 ? _BEIGE : _GREY);
            x += size;
            ++index;
        }
        y += size;
        flag = !flag;
    }
}

void UpdateWorld(World *world) {
    //sync delta time
    {
        double now = GetTime();
        world->delta_time = now - world->last_tick;
        world->last_tick = now;
    }
    //sync camera and car position
    {
        Vec2 direction = Vec2_Sub(world->car.center_geometry, world->camera.pos);
        float dist = Vec2_Magnitude(direction);
        float adaption_speed = -(1/expf(dist/10)) + 1;
        m_Vec2_Mult(&direction, adaption_speed);
        m_Vec2_Add(&world->camera, direction);
    }
}