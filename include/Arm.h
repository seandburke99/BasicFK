#ifndef ARM_H
#define ARM_H
#include <Link.h>
#include <Point.h>
#include <stdint.h>
#include <SDL_render.h>
#include <SDL2/SDL_rect.h>

typedef struct Arm Arm;

struct Arm{
    uint32_t len;
    SDL_Point base;
    Link *links;
};

void compute_forward_kinematics(Arm *a, const double angles[]);
void show_arm(SDL_Renderer *ren, const Arm *a);

#endif