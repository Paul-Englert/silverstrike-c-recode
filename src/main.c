#include "../include/gui.h"
#include "../include/raylib.h"

#include <stdio.h>

void DrawFn(void) {
    ClearBackground(RAYWHITE);
}

void KeyFn(int key) {
    printf("key pressed: %d\n", key);
}

void MouseFn(MouseInfo mouse_info) {

}

int main(void) {
    InitGraphics((Window) {0,0,"Test", 60}, (Scene) {DrawFn, KeyFn, MouseFn});
    while (!WindowShouldClose()) {
        UpdateWindow();
    }
    CloseWindow();
}