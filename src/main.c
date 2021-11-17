#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <Arm.h>

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 600

#define FPS 30
#define DELAY 1000/FPS

#define NUMLINKS 6
#define LENLINKS 30
#define STEP M_PI/128

int main(int argc, char *argv[]){
    if(SDL_Init(0)){
        fprintf(stderr, "Unable to init SDL\n");
        return -1;
    }
    Arm a;
    SDL_Window *win;
    SDL_Renderer *ren;
    win = SDL_CreateWindow(
        "Forward Kinematics", 
        SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        0
    );
    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    a.len = NUMLINKS;
    a.links = malloc(NUMLINKS*sizeof(Link));
    for(int i=0;i<a.len;i++){
        a.links[i] = new_link(LENLINKS);
    }
    double angles[NUMLINKS] = {5*M_PI/5};
    a.base = new_vec(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    uint8_t quit = 0;
    int8_t dir[NUMLINKS] = {1,-1,1,-1,1,-1};
    for(int i=0;i<NUMLINKS;i++){
        angles[i] = 3*M_PI/2;
    }
    while(!quit){
        SDL_SetRenderDrawColor(ren, 0,0,0,0);
        SDL_RenderClear(ren);
        SDL_Event e;
        while(SDL_PollEvent(&e) != 0){
            switch(e.type){
                case SDL_QUIT:
                    quit = 1;
                    break;
                case SDL_KEYDOWN:
                    switch(e.key.keysym.sym){
                        case SDLK_q:
                            quit = 1;
                            break;
                    }
                    break;
                default:
                    break;
            }
        }
        for(int i=0;i<a.len;i++){
            if((fabs(angles[i])<M_PI*5/4) || (fabs(angles[i])>M_PI*7/4))
                dir[i] *= -1;
            angles[i] += dir[i]*STEP;
        }
        compute_forward_kinematics(&a, angles);
        show_arm(ren, &a);
        SDL_RenderPresent(ren);
        SDL_Delay(DELAY);
    }
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    return 0;
}