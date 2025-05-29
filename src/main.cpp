// main.cpp
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Lissajous.h"
#include "Renderer.h"
#include "Utils.h"          // formatFloat
#include <vector>
#include <string>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
std::string fontDir = "/usr/share/fonts/truetype/dejavu/";
std::string fontFile = "DejaVuSans.ttf";
std::string fontPath = fontDir + fontFile;

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    SDL_Window* window = SDL_CreateWindow("Lissajous Curve", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    TTF_Font* font = TTF_OpenFont(fontPath.c_str(), 16);

    Lissajous liss(200.0f, 200.0f, 2.0f, 3.0f, 0.0f, 0.0f);

    bool running = true;
    bool fullscreen = false;
    bool showHelp = false;
    bool showParams = false;

    std::vector<std::string> helpStrings = {
        "F1: Toggle Help",
        "F2: Toggle Parameter Display",
        "W/S: Increase/Decrease A (Shift = x10)",
        "A/D: Increase/Decrease B (Shift = x10)",
        "+/-: Zoom A & B together",
        "T: Rotate CCW (Shift = 15 deg)",
        "R: Rotate CW (Shift = 15 deg)",
        "Backspace: Reset Zoom/Rotation/Freq/Delta",
        "[: Increase δ (Shift = 10 deg)",
        "]: Decrease δ (Shift = 10 deg)",
        "H/L: Increase/Decrease freqA (Shift = x10)",
        "J/K: Increase/Decrease freqB (Shift = x10)",
        "F11: Toggle Fullscreen",
        "Ctrl+Q: Quit"
    };

    std::vector<std::string> paramStrings;

    RenderOverlay help(renderer, font, 10, 10, 20, helpStrings);
    RenderOverlay params(renderer, font, 500, 10, 20, paramStrings);

    SDL_Event e;
    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) running = false;
            if (e.type == SDL_KEYDOWN) {
                SDL_Keymod mod = SDL_GetModState();
                switch (e.key.keysym.sym) {
                    case SDLK_q: if (mod & KMOD_CTRL) running = false; break;
                    case SDLK_F1: showHelp = !showHelp; break;
                    case SDLK_F2: showParams = !showParams; break;
                    case SDLK_w: liss.setA(liss.getA() + ((mod & KMOD_SHIFT) ? 10.0f : 1.0f)); break;
                    case SDLK_s: liss.setA(liss.getA() - ((mod & KMOD_SHIFT) ? 10.0f : 1.0f)); break;
                    case SDLK_a: liss.setB(liss.getB() - ((mod & KMOD_SHIFT) ? 10.0f : 1.0f)); break;
                    case SDLK_d: liss.setB(liss.getB() + ((mod & KMOD_SHIFT) ? 10.0f : 1.0f)); break;
                    case SDLK_EQUALS: liss.zoom(10.0f); break;
                    case SDLK_MINUS: liss.zoom(-10.0f); break;
                    case SDLK_t: liss.setTheta(liss.getTheta() - ((mod & KMOD_SHIFT) ? 15.0f : 1.0f)); break;
                    case SDLK_r: liss.setTheta(liss.getTheta() + ((mod & KMOD_SHIFT) ? 15.0f : 1.0f)); break;
                    case SDLK_LEFTBRACKET: liss.setDelta(liss.getDelta() + ((mod & KMOD_SHIFT) ? 10.0f : 1.0f)); break;
                    case SDLK_RIGHTBRACKET: liss.setDelta(liss.getDelta() - ((mod & KMOD_SHIFT) ? 10.0f : 1.0f)); break;
                    case SDLK_h: liss.setFreqA(liss.getFreqA() + ((mod & KMOD_SHIFT) ? 10.0f : 1.0f)); break;
                    case SDLK_l: liss.setFreqA(liss.getFreqA() - ((mod & KMOD_SHIFT) ? 10.0f : 1.0f)); break;
                    case SDLK_j: liss.setFreqB(liss.getFreqB() + ((mod & KMOD_SHIFT) ? 10.0f : 1.0f)); break;
                    case SDLK_k: liss.setFreqB(liss.getFreqB() - ((mod & KMOD_SHIFT) ? 10.0f : 1.0f)); break;
                    case SDLK_BACKSPACE: liss.reset(); break;
                    case SDLK_F11:
                        fullscreen = !fullscreen;
                        SDL_SetWindowFullscreen(window, fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
                        break;
                }
            }
        }

        paramStrings = {
            "A = " + formatFloat(liss.getA()),
            "B = " + formatFloat(liss.getB()),
            "freqA = " + formatFloat(liss.getFreqA()) + " Hz",
            "freqB = " + formatFloat(liss.getFreqB()) + " Hz",
            "δ = " + formatFloat(liss.getDelta()) + " deg",
            "θ = " + formatFloat(liss.getTheta()) + " deg"
        };
        params.setStrings(paramStrings);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        liss.draw(renderer, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
        if (showHelp) help.show();
        if (showParams) params.show();

        SDL_RenderPresent(renderer);
    }

    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    return 0;
}

