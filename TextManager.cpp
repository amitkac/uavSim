#include "TextManager.h"

SDL_Texture *TextureManager::loadTexture(const char *fileName)
{

    SDL_Surface *tmpSurface = IMG_Load(fileName);
    SDL_Texture *tex = SDL_CreateTextureFromSurface(Sim::renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    return tex;
}

void TextureManager::draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dst)
{
    SDL_RenderCopy(Sim::renderer, tex, &src, &dst);
}