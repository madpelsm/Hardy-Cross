#pragma once
#include "Pipe.hpp"
#include <vector>
class loop{
    public:
        double sumKLabsQ=1;
        double sumKLQQ=1;
        double correction=0;
        int maxIterations=1;
        std::vector<Pipe*> pipes;//pointers so pipes can be easily shared between different loops
        loop();
        loop(std::vector<Pipe*> _pipes);
        ~loop();
        void addPipe(Pipe * _pipe);
        void iterate();
        void showResults();
        void adjustPipeFlows();
};
