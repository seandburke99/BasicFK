#include <Point.h>

double f_mag(const SDL_Point *v){
    return SDL_sqrt(v->x*v->x + v->y*v->y);
}

double f_dir(const SDL_Point *v){
    return SDL_atan2(v->x, v->y);
}

SDL_Point new_vec(int x, int y){
    SDL_Point f;
    f.x = x;
    f.y = y;
    return f;
}