// Renderer.h
#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <vector>

class RenderText {
private:
    SDL_Renderer* renderer;
    TTF_Font* font;
    int x, y;
    std::string text;

public:
    RenderText(SDL_Renderer* renderer, TTF_Font* font, int x, int y, const std::string& text);
    void setText(const std::string& newText);
    void render();
};

class RenderOverlay {
private:
    SDL_Renderer* renderer;
    TTF_Font* font;
    int x, y;
    int lineSpacing;
    std::vector<std::string> strings;
    std::vector<RenderText> lines;

public:
    RenderOverlay(SDL_Renderer* renderer, TTF_Font* font, int x, int y, int spacing, const std::vector<std::string>& strings);
    void setStrings(const std::vector<std::string>& newStrings);
    void show();
};

