#include "Pipe.hpp"
#include <math.h>
#include <iostream>
Pipe::Pipe(double _length, double _diameter, double _roughness, double _flow,
           std::string _name)
    : length(_length),
      diameter(_diameter),
      roughness(_roughness),
      flow(_flow),
      name(_name) {
    initialFlow = _flow;
    // this could be replaced by 'iterate'
    // as of now i'm still figuring out what needs to be recalculated
    iterate();
    }

Pipe::~Pipe() {}

void Pipe::calculateSpeed() { speed = flow / (pi * diameter * diameter / 4); }

void Pipe::calculateReynolds() {
    reynoldsNumber = abs(speed) * diameter * rho / mu;
}

void Pipe::calculateDarcyFriction() {
    //=(-1.8*LOG10(((N19/J19)/3.7)^1.11+6.9/M19))^(-2)
    darcyFriction = std::pow(
        (-1.8 * std::log10(std::pow(((roughness / diameter) / 3.7), 1.11) +
                           6.9 / reynoldsNumber)),
        -2);
}

void Pipe::calculateFrictionCoeffs() {
    K = 8 * darcyFriction / (g * pow(diameter, 5) * pi * pi);
    KLabsQ = K * length * std::abs(flow);
    KLQQ = KLabsQ * flow;
}

void Pipe::iterate() {
    calculateSpeed();
    calculateReynolds();
    calculateDarcyFriction();
    calculateFrictionCoeffs();
}
