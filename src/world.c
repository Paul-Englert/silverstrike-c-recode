#include "../include/world.h"
#include "../include/raylib.h"
#include "../include/vec2.h"

#include <stdbool.h>
#include <stdio.h>
#include <math.h>

#define _BEIGE      (Color) {0xde, 0xe2, 0xe6, 0xFF}
#define _GREY       (Color) {0x34, 0x3a, 0x40, 0xFF}

#define ZOOM_CONST (1080/30)

typedef struct {
    double sin, cos;
    Vec2 screen_half;
    Vec2 position;
    float zoom;
} CameraSnapshot;

static CameraSnapshot MakeCameraSnapshot(Camera2 *camera) {
    return (CameraSnapshot) {sinf((camera->rotation)*DEG2RAD), cosf((camera->rotation)*DEG2RAD), (Vec2){GetRenderWidth()/2, GetRenderHeight()/2}, camera->pos, camera->zoom};
}

static Vec2 World2Screen(const CameraSnapshot *camera, Vec2 origin) {
    m_Vec2_Sub(&origin, camera->position);
    origin = (Vec2){camera->cos*origin.x - camera->sin*origin.y, camera->sin*origin.x + camera->cos*origin.y};
    m_Vec2_Mult(&origin, camera->zoom * ZOOM_CONST);

    //mirror y coordinate
    origin.y *= -1;

    //shift coordinate system
    m_Vec2_Add(&origin, camera->screen_half);
    return origin;
}

static void RenderMap(World *world) {

}

static void RenderCar(World *world) {

}

void RenderWorld(World *world) {
    ClearBackground(RAYWHITE);
    const CameraSnapshot camera = MakeCameraSnapshot(&world->camera);
    Quad q = world->car.body;
    for (int i = 0; i < 4; ++i) {
        bool flag = false;
        Vec2 p1 = World2Screen(&camera, q.points[i]);
        if (i == 3) {
            i = 0;
            flag = true;
        }
        Vec2 p2 = World2Screen(&camera, q.points[i+1]);
        DrawLine((int)p1.x, (int)p1.y, (int)p2.x, (int)p2.y, _GREY);
        if (flag) break;
    }
}

void UpdateWorld(World *world) {
    //sync delta time and tick count
    {
        double now = GetTime();
        world->delta_time = now - world->last_tick;
        world->last_tick = now;
        ++world->tick_count;
    }
    //sync camera pos with car position and camera rotation with car rotation
    {
        //TODO extend car's geometry position vector so camera is not in the middle of the screen
        Vec2 direction = Vec2_Sub(world->car.center_geometry, world->camera.pos);
        float dist = Vec2_Magnitude(direction); //distance camera to car
        float adaption_speed = -(1/expf(dist/10)) + 1;
        adaption_speed *= world->delta_time;
        m_Vec2_Mult(&direction, adaption_speed);
        m_Vec2_Add(&world->camera.pos, direction);
        //TODO sync camera rotation
    }
}

Car CreateCar(void) {
    Car car = {0};

    Quad body = {0};
    body.points[0] = (Vec2){1,  1};
    body.points[1] = (Vec2){1, -1};
    body.points[2] = (Vec2){-1, -1};
    body.points[3] = (Vec2){-1, 1};
    car.body = body;

    return car;
}