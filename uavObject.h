#include "Sim.h"

// each object has its own behaviour
class uavObject
{
public:
    uavObject(const char *textureSheet, float x, float y);
    ~uavObject();

    void update(float intX, float intY, float x, float y);
    void render();

private:
    float xPos;
    float yPos;

    SDL_Texture *objtexture;
    // SDL_Rect srcRect, dstRect;
    SDL_FRect srcRect, dstRect;
    // SDL_Renderer *renderer;
};