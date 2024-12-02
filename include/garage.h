#ifndef _GARAGE_H_
#define _GARAGE_H_

#include "world.h"

typedef struct {
    
} Garage;

Car Garage_CreateCar(Garage *garage);

void Garage_RenderGarage(Garage *garage);

void Garage_UpdateGarage(Garage *garage);

#endif // _GARAGE_H_