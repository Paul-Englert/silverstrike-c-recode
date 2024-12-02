#include "../include/gui.h"
#include "../include/raylib.h"
#include "../include/utils.h"
#include "../include/world.h"

#include <stdio.h>

static World world = {0};

void DrawFn(void) {
    RenderWorld(&world);
}

void UpdateFn(void) {
    UpdateWorld(&world);
}

int main(void) {
    world.car = CreateCar();
    world.camera.zoom = 1;
    InitGraphics((Window) {0,0,"Test", 60}, (Scene) {DrawFn, UpdateFn});
    while (!WindowShouldClose()) {
        UpdateWindow();
    }
    CloseWindow();
}