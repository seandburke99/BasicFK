#include <Link.h>

void calc_link_end(Link *l){
    l->end.x = l->start.x - SDL_cos(l->angle)*l->len;
    l->end.y = l->start.y + SDL_sin(l->angle)*l->len;
}

void calc_link_start(Link *l);

Link new_link(uint32_t len){
    Link l;
    l.angle = 0;
    l.end = new_vec(0,0);
    l.start = new_vec(0,0);
    l.len = len;
    return l;
}