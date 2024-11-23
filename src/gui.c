#include "../include/gui.h"
#include "../include/raylib.h"

static Scene current_scene = {NULL, NULL, NULL};

void InitWindow(Window window, Scene scene) {
    current_scene = scene;
    InitWindow(window.width, window.height, window.title);
    SetTargetFps(window.fps);
}

void SetScene(Scene scene) {
    current_scene = scene;
}

void UpdateWindow(void) {
    //update graphics
    BeginDrawing();
        current_scene.draw_routine();
    EndDrawing();
    //call mouse handler
    Vector2 mouse_delta = GetMouseDelta();
    MouseInfo mouse_info = {GetMouseX(), GetMouseY(), mouse_delta.x, mouse_delta.y};
    current_scene.mouse_handler(mouse_info);
    //call key handler
    int key;
    while ((key = GetKeyPressed()) != 0) {
        current_scene.key_handler(key);
    }
}