#ifndef _GAME_H_
#define _GAME_H_

#include "garage.h"
#include "controls.h"
#include "world.h"

struct {
    World current_world;
    Controls controls;
    Garage garage;
} Game;

#endif // _GAME_H_