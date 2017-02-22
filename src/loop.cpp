#include "loop.hpp"
#include <iostream>

loop::loop(){
}

loop::~loop(){
}

loop::loop(std::vector<Pipe *> _pipes):pipes(_pipes){
    for(auto p:pipes){
        std::cout<<"pipe "<<p->name<<" added\n"<<std::endl;
    }
}

void loop::iterate(){
    sumKLabsQ=0.0000000000000001;
    sumKLQQ=0;
    for(auto p:pipes){
        p->iterate();
        sumKLabsQ+=p->KLabsQ;
        sumKLQQ+=p->KLQQ;
    }
    correction=(-1)*sumKLQQ/(2*sumKLabsQ);
    adjustPipeFlows();
}

void loop::adjustPipeFlows(){
    for(auto p:pipes){
        p->flow+=correction;
    }
}

void loop::showResults(){
    for(auto p:pipes){
        std::cout<<p->name<<":"<<p->flow<<std::endl;
    }
}

void loop::addPipe(Pipe * _pipe){
    pipes.push_back(_pipe);
    std::cout<<pipes.back()->name<<" added"<<std::endl;
}
