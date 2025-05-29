// Lissajous.h
#pragma once
#include <SDL2/SDL.h>
#include <utility>

class Lissajous {
public:
    Lissajous(float a, float b, float fa, float fb, float delta, float theta);

    void draw(SDL_Renderer* renderer, int centerX, int centerY);

    float getA() const;
    float getB() const;
    float getFreqA() const;
    float getFreqB() const;
    float getDelta() const;
    float getTheta() const;

    void setA(float value);
    void setB(float value);
    void setFreqA(float value);
    void setFreqB(float value);
    void setDelta(float deg);
    void setTheta(float deg);

    void zoom(float delta);
    void reset();

private:
    float A, B;
    float freqA, freqB;
    float deltaDeg;
    float thetaDeg;

    std::pair<float, float> rotate(float x, float y) const;
};
