#ifndef LINK_H
#define LINK_H
#include <stdint.h>
#include <Point.h>

typedef struct Link Link;

struct Link{
    uint16_t len;
    SDL_Point start;
    SDL_Point end;
    double angle;
};

void calc_link_end(Link *l);
void calc_link_start(Link *l);
Link new_link(uint32_t len);


#endif