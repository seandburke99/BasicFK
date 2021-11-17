#include <Arm.h>
#include <stdio.h>

void compute_forward_kinematics(Arm *a, const double angles[]){
    a->links[0].start = a->base;
    for(int i=0;i<a->len;i++){
        a->links[i].angle = angles[i];
        calc_link_end(&a->links[i]);
        if(i<a->len-1)
            a->links[i+1].start = a->links[i].end;
    }
}

void show_arm(SDL_Renderer *ren, const Arm *a){
    SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0xFF);
    for(int i=0;i<a->len;i++){
        SDL_RenderDrawLine(
            ren, 
            a->links[i].start.x, 
            a->links[i].start.y,
            a->links[i].end.x,
            a->links[i].end.y
        );
    }
    SDL_SetRenderDrawColor(ren, 0xFF, 0, 0, 0xFF);
    SDL_RenderDrawPoint(ren, a->base.x, a->base.y);
}