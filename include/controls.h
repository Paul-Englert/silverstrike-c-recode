#ifndef _CONTROLS_H_
#define _CONTROLS_H_

typedef int Key;

typedef struct {

} Controls;

void LoadControlsOrDefault(const char *source_path);

Controls SaveControlsToFile(Controls controls, const char *target_path);

#endif // _CONTROLS_H_