#include "Sim.h"
#include "TextManager.h"
#include "uavObject.h"
#include <iostream>
#include <stdio.h>
#include "Map.h"
// #include "blitImage.h"

// SDL_Texture *uavText;

// SDL_Rect srcRect, dstRect;
// dstRect.h = 128;
// dstRect.w = 256;
// dstRect.x = SCREEN_WIDTH / 2 - dstRect.w / 2;
// dstRect.y = SCREEN_HEIGHT / 2 - dstRect.h / 2;

uavObject *uav1;
// uavObject *uav2;
Map *map;
// blitImage *bg;
float initXpos = SCREEN_WIDTH / 2 - 50;
float initYpos = SCREEN_HEIGHT / 2 - 250;

SDL_Renderer *Sim::renderer = nullptr;

Sim::Sim()
{
}

Sim::~Sim()
{
}

void Sim::init(const char *title, int xpos, int ypos, int width, int height,
               bool fullscreen, int count)
{
    bool flag = true;
    int scrFlag = 0;

    if (fullscreen)
    {
        scrFlag = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) // if it returns -1, there was an error
    {
        // print that errir using SDL_getError
        printf("SDL could not initialize! SDl error: %s \n", SDL_GetError());
        isRunning = false;
    }

    else
    {
        window = SDL_CreateWindow(title, xpos, ypos, width, height, scrFlag);

        if (window == NULL)
        {
            printf("window didn't create! SDl error: %s \n", SDL_GetError());
            isRunning = false;
        }
        else
        {
            renderer = SDL_CreateRenderer(window, -1, 0);
            if (renderer == NULL)
            {
                printf("Renderor didn't create! SDl error: %s \n", SDL_GetError());
                isRunning = false;
            }
            else
            {
                // SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                // SDL_Surface *screenBack = NULL;
                // screenBack = SDL_GetWindowSurface(window);

                // SDL_Surface *background = SDL_LoadBMP("img/back.bmp");
                // SDL_BlitSurface(background, NULL, screenBack, NULL);
                // SDL_UpdateWindowSurface(window);

                isRunning = true;
                count = 0;
            }

            //  create texture
            // SDL_Surface *tmpSurf = IMG_Load("img/uav.png");

            // UAV texture, get more textures

            uav1 = new uavObject("img/uav34.png", initXpos, initYpos); //SCREEN_WIDTH / 2 - 10, SCREEN_HEIGHT / 2 - 30);
            // uav2 = new uavObject("img/uav34.png", initXpos - 450, initYpos + 100);
            map = new Map();
            // SDL_FreeSurface(tmpSurf);
            //bg = new blitImage;
        }
    }
}

void Sim::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    default:
        break;
    }
}

void Sim::update(float x, float y)
{
    uav1->update(initXpos, initYpos, x, y);
    // uav2->update(initXpos - 450, initYpos + 100, x, y);
}

void Sim::render()
{
    SDL_RenderClear(renderer);
    // render here
    //  paint first--then second
    map->drawMap();
    // bg->drawBackground();
    uav1->render();
    // uav2->render();

    SDL_RenderPresent(renderer);
}

void Sim::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    IMG_Quit();
    SDL_Quit();
    printf("called delete\n");
    delete uav1;
    // delete uav2;
    // delete bg;
    // delete map;

    printf("cleaned everything \n");
}
