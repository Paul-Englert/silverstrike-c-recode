#include "../include/gui.h"
#include "../include/raylib.h"

#include <stddef.h>

static Scene current_scene = {NULL, NULL, NULL};

void InitGraphics(Window window, Scene scene) {
    current_scene = scene;
    InitWindow(window.width, window.height, window.title);
    SetTargetFPS(window.fps);
}

void SetScene(Scene scene) {
    current_scene = scene;
}

static MouseInfo MakeMouseInfo(void) {
    MouseInfo mouse_info = {0};
    Vector2 mouse_delta = GetMouseDelta();
    mouse_info.x = GetMouseX();
    mouse_info.y = GetMouseY();
    mouse_info.dX = mouse_delta.x;
    mouse_info.dY = mouse_delta.y;
    mouse_info.states[0] = IsMouseButtonDown(0);
    mouse_info.states[1] = IsMouseButtonDown(1);
    mouse_info.was_pressed[0] = IsMouseButtonPressed(0);
    mouse_info.was_pressed[1] = IsMouseButtonPressed(1);
    mouse_info.was_released[0] = IsMouseButtonReleased(0);
    mouse_info.was_released[1] = IsMouseButtonReleased(1); 
    return mouse_info;
}

void UpdateWindow(void) {
    //update graphics
    BeginDrawing();
        current_scene.draw_routine();
    EndDrawing();
    //call mouse handler
    current_scene.mouse_handler(MakeMouseInfo());
    //call key handler
    int key;
    while ((key = GetKeyPressed()) != 0) {
        current_scene.key_handler(key);
    }
}