#pragma once
#include "Sim.h"

class Map
{

public:
    Map();
    ~Map();

    void loadMap(int arr[20][25]);
    void drawMap();

private:
    SDL_Rect srcD, dstD;
    SDL_Texture *blueBack;
    SDL_Texture *whiteback;
    // SDL_Texture *grass;
    // SDL_Texture *water;

    int map[20][25];
};