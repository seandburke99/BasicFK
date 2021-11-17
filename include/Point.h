#ifndef POINT_H
#define POINT_H
#include <SDL2/SDL_rect.h>

double f_mag(const SDL_Point *v);
double f_dir(const SDL_Point *v);
void set_dir(SDL_Point *p, const double a);
SDL_Point new_vec(int x, int y);

#endif