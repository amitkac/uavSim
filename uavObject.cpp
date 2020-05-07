#include "uavObject.h"
#include "TextManager.h"

uavObject::uavObject(const char *textureSheet, float x, float y)
{
    // renderer = ren;
    objtexture = TextureManager::loadTexture(textureSheet);
    xPos = x;
    yPos = y;
}

uavObject::~uavObject()
{
}

void uavObject::update(float intX, float intY, float x, float y)
{
    xPos = intX - x;

    yPos = intY - y;

    srcRect.h = 181.0;
    srcRect.w = 256.0;
    srcRect.x = 0.0;
    srcRect.y = 0.0;

    dstRect.x = xPos;
    dstRect.y = yPos;
    dstRect.w = srcRect.w;
    dstRect.h = srcRect.h;
}

void uavObject::render()
{
    SDL_RenderCopyExF(Sim::renderer, objtexture, NULL, &dstRect, 0.0, NULL, SDL_FLIP_NONE);
}