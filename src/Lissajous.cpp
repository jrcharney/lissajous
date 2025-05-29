// Lissajous.cpp
#include "Lissajous.h"
#include "MathConstants.h"
#include <cmath>
#include <utility> // for std::pair

Lissajous::Lissajous(float a, float b, float fa, float fb, float delta, float theta)
    : A(a), B(b), freqA(fa), freqB(fb), deltaDeg(delta), thetaDeg(theta) {}

void Lissajous::draw(SDL_Renderer* renderer, int centerX, int centerY) {
    const int steps = 1000;
    const float dt = 1.0f / steps;

    SDL_Point prev;
    for (int i = 0; i <= steps; ++i) {
        float t = i * dt;
        float radiansA = TWO_PI * freqA * t + deltaDeg * TO_RADIANS;
        float radiansB = TWO_PI * freqB * t;

        float x = A * sin(radiansA);
        float y = B * sin(radiansB);

        auto [rotX, rotY] = rotate(x, y);

        SDL_Point point = { static_cast<int>(centerX + rotX), static_cast<int>(centerY - rotY) };
        if (i > 0) SDL_RenderDrawLine(renderer, prev.x, prev.y, point.x, point.y);
        prev = point;
    }
}

std::pair<float, float> Lissajous::rotate(float x, float y) const {
    float thetaRad = thetaDeg * TO_RADIANS;
    float rotX = x * cos(thetaRad) - y * sin(thetaRad);
    float rotY = x * sin(thetaRad) + y * cos(thetaRad);
    return { rotX, rotY };
}

float Lissajous::getA() const { return A; }
float Lissajous::getB() const { return B; }
float Lissajous::getFreqA() const { return freqA; }
float Lissajous::getFreqB() const { return freqB; }
float Lissajous::getDelta() const { return deltaDeg; }
float Lissajous::getTheta() const { return thetaDeg; }

void Lissajous::setA(float value) { A = value; }
void Lissajous::setB(float value) { B = value; }
void Lissajous::setFreqA(float value) { freqA = value; }
void Lissajous::setFreqB(float value) { freqB = value; }
void Lissajous::setDelta(float deg) { deltaDeg = deg; }
void Lissajous::setTheta(float deg) { thetaDeg = deg; }

void Lissajous::zoom(float delta) {
    A += delta;
    B += delta;
    if (A < 1) A = 1;
    if (B < 1) B = 1;
}

void Lissajous::reset() {
    A = 200.0f;
    B = 200.0f;
    freqA = 2.0f;
    freqB = 3.0f;
    deltaDeg = 0.0f;
    thetaDeg = 0.0f;
}

