// Renderer.cpp
#include "Renderer.h"

RenderText::RenderText(SDL_Renderer* renderer, TTF_Font* font, int x, int y, const std::string& text)
    : renderer(renderer), font(font), x(x), y(y), text(text) {}

void RenderText::setText(const std::string& newText) {
    text = newText;
}

void RenderText::render() {
    SDL_Color color = {255, 255, 255, 255};
    SDL_Surface* surface = TTF_RenderUTF8_Blended(font, text.c_str(), color);
    if (!surface) return;

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect dstRect = {x, y, surface->w, surface->h};
    SDL_FreeSurface(surface);

    if (texture) {
        SDL_RenderCopy(renderer, texture, nullptr, &dstRect);
        SDL_DestroyTexture(texture);
    }
}

RenderOverlay::RenderOverlay(SDL_Renderer* renderer, TTF_Font* font, int x, int y, int spacing, const std::vector<std::string>& strings)
    : renderer(renderer), font(font), x(x), y(y), lineSpacing(spacing) {
    setStrings(strings);
}

void RenderOverlay::setStrings(const std::vector<std::string>& newStrings) {
    strings = newStrings;
    lines.clear();
    int yOffset = y;
    for (const auto& str : strings) {
        lines.emplace_back(renderer, font, x, yOffset, str);
        yOffset += lineSpacing;
    }
}

void RenderOverlay::show() {
    for (auto& line : lines) {
        line.render();
    }
}

