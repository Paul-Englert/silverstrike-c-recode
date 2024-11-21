#ifndef _GUI_H_
#define _GUI_H

#include <stdio.h>

typedef struct {
    size_t width, height;
    size_t delta_time;
} Window;

typedef struct {
    size_t x, y;
    int dX, dY;
} MouseInfo;

typedef void (*DrawRoutine)(Window);

typedef void (*KeyHandler)(int);

typedef void (*MouseHandler)(MouseInfo);

typedef struct {
    DrawRoutine draw_routine;
    KeyHandler key_handler;
    MouseHandler mouse_handler;
} Scene;

void InitGraphics(Scene scene);

void DestroyWindow(void);

void SetScene(Scene scene);

void UpdateScreen(void);

#endif // _GUI_H_