#ifndef Sim_h
#define Sim_h
#include <SDL2/SDL.h>
#include <stdio.h>
#include <SDL2/SDL_image.h>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 800; //960 for stillwater, 720 for others

class Sim
{

public:
    Sim();
    ~Sim();
    void init(const char *title, int xpos, int ypos, int width, int height,
              bool fullscreen, int count);
    void handleEvents();
    void update(float x, float y);
    void render();
    void clean();

    bool running() { return isRunning; };

    static SDL_Renderer *renderer; // need to refer it always

private:
    int count;
    bool isRunning;
    SDL_Window *window;
    // SDL_Renderer *renderer;
};

#endif