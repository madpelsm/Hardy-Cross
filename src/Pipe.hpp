#pragma once
#include <cmath>
#include <string>

#define pi 4 * std::atan(1)

class Pipe {
   public:
    double length;
    double diameter;
    double roughness;
    double flow;  // flow
    double darcyFriction;
    double reynoldsNumber;
    double speed;
    double initialFlow;
    double K;
    double KLabsQ = 1, KLQQ = 1;
    std::string name;

    // assume variable: water 15 degrees celcius
    double mu = 0.001307, rho = 1000,g=9.81;

    Pipe(double _length, double _diameter, double _roughness, double _flow,
         std::string _name);
    ~Pipe();
    void calculateSpeed();
    void calculateDarcyFriction();
    void calculateReynolds();
    void calculateFrictionCoeffs();
    void iterate();
};
