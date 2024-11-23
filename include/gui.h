#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

typedef struct {
    int x, y, dX, dY;
} MouseInfo;

typedef struct {
    int width, height;
    const char *title;
    int fps;
} Window;

typedef void (*DrawRoutine)(void);

typedef void (*KeyHandler)(int);

typedef void (*MouseHandler)(MouseInfo);

typedef struct {
    DrawRoutine draw_routine;
    KeyHandler key_handler;
    MouseHandler mouse_handler;
} Scene;

void InitWindow(Window window, Scene scene);

void SetScene(Scene scene);

void UpdateWindow(void);

#endif // _Graphics_H_