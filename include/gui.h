#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

typedef struct {
    int width, height;
} Window;

typedef struct {
    int x, y, dX, dY;
} MouseInfo;

typedef void (*DrawRoutine)(Window);

typedef void (*KeyHandler)(int);

typedef void (*MouseHandler)(MouseInfo);

typedef struct {
    DrawRoutine draw_routine;
    KeyHandler key_handler;
    MouseHandler mouse_handler;
} Scene;

void InitGraphics(void);

void DestroyWindow(void);

void SetScene(Scene scene);

void DrawGraphics(void);

#endif // _Graphics_H_