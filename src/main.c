#include "../include/graphics.h"
#include "../include/raylib.h"

int main(void) {
    InitWindow(0, 0, "Test");
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }
    CloseWindow();
}