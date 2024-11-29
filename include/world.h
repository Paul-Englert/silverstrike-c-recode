#ifndef _WORLD_H_
#define _WORLD_H_

#include "vec2.h"

//struct for camera
typedef struct {
    //center of screen (in world position)
    Vec2 pos;
    //rotation of camera
    float rotation;
    //zoom of camera
    float zoom;
} Camera2;

//amount of wheels a car has
#define WHEEL_COUNT 4

//struct for car
typedef struct {
    //geometric center of this car
    //calculated by adding the wheel vectors and dividing by WHEEL_COUNT
    //needed for adapting camera to movements
    Vec2 center_geometry;
    //center of mass of this car
    //needed for physics stuff
    Vec2 center_gravity;
    //positions of the 4 wheels, in order: front left, front right, back left, back right
    Quad wheels[WHEEL_COUNT];
    Quad body;
} Car;

Car CreateCar(void);

//struct for a map
typedef struct {
    Vec2 *track_points;
    int track_point_count;
} Map;

//struct for world
//contains everything
typedef struct {
    //the camera state in this world
    Camera2 camera;
    //the map this world represents
    Map map;
    //the car driving on this map
    Car car;
    //last timestamp that UpdateWorld was called for this world
    double last_tick;
    //time elapsed since last UpdateWorld call, set right at the beginning of UpdateWorld
    double delta_time;
} World;

//Updates the track, the car, the physics, the everything for this world
void UpdateWorld(World *world);

//Renders this world to the screen based on this world's camera's state
void RenderWorld(World *world);

#endif // _WORLD_H_