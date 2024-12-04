#include "../include/gui.h"
#include "../include/raylib.h"
#include "../include/utils.h"
#include "../include/world.h"

#include <stdio.h>

void DrawFn(void) {
    RenderWorld(&Game.world);
}

void UpdateFn(void) {
    UpdateWorld(&Game.world);
}

static void PrepWorld(World *world) {
    world->camera.zoom = 1;
    world->camera.pos = {0};
    world->camera.zoom = 0;
    world->car = CreateCar();
    LoadMap(&world->map, "");
    world->last_tick = 0;
    world->delta_time = 0;
    world->tick_count = 0;
}

#define WINDOW_CONFIG (Window){0,0,"Test", 60}

int main(void) {
    PrepWorld();
    InitGraphics(WINDOW_CONFIG, (Scene) {DrawFn, UpdateFn});
    while (!WindowShouldClose()) {
        UpdateWindow();
    }
    CloseWindow();
}